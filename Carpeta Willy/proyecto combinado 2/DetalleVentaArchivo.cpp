#include "DetalleVentaArchivo.h"
#include "VentaArchivo.h"
#include <iostream>
#include <cstdio>

using namespace std;


bool DetalleVentaArchivo::guardar(const Detalle_Venta &reg)
{

    FILE* pventa ;

    pventa = fopen(archivo_DetalleVenta,"ab") ;

    if(pventa == nullptr)
    {

        cout << "NO SE PUDO CREAR EL ARCHIVO " ;

        return false ;
    }

    int escrito = fwrite(&reg,sizeof(Detalle_Venta),1,pventa);

    fclose(pventa);

    return escrito;
}

Detalle_Venta DetalleVentaArchivo::leer(int pos)
{

    Detalle_Venta reg ;

    FILE* pventa ;

    pventa = fopen(archivo_DetalleVenta, "rb") ;

    if(pventa == nullptr)
    {

        cout << "NO SE PUDO CREAR EL ARCHIVO" ;

        return reg ;
    }

    fseek(pventa,pos*sizeof(Detalle_Venta), SEEK_SET) ;

    fread(&reg,sizeof(Detalle_Venta),1,pventa) ;

    fclose(pventa) ;

    return reg ;

}

bool DetalleVentaArchivo::bajaLogica(int idDetalle)
{

    int pos = buscarPosicion(idDetalle) ;

    if(pos == -1)
    {

        return false ;
    }

    Detalle_Venta reg = leer(pos) ;

    reg.setEstado(false) ;

    FILE* pventa ;

    pventa = fopen(archivo_DetalleVenta,"rb+") ;

    if (pventa == nullptr)
    {
        return false ;
    }

    fseek(pventa,pos*sizeof(Detalle_Venta),SEEK_SET) ;

    int escrito = fwrite(&reg,sizeof(Detalle_Venta),1,pventa) ;

    fclose(pventa) ;

    return escrito ;

}

bool DetalleVentaArchivo::darDealta(int idDetalle)
{

    int pos= buscarPosicion(idDetalle);

    if(pos == -1)
    {
        return false;
    }

    Detalle_Venta reg = leer(pos);

    reg.setEstado(true);

    FILE* pventa;
    pventa = fopen(archivo_DetalleVenta,"rb+");

    if (pventa == nullptr)
    {
        return false;
    }

    fseek(pventa,pos*sizeof(Detalle_Venta),SEEK_SET);

    int escrito = fwrite(&reg,sizeof(Detalle_Venta),1,pventa);

    fclose(pventa);

    return escrito;
}

bool DetalleVentaArchivo::modificar(const Detalle_Venta &reg)
{

    int pos;
    pos = buscarPosicion(reg.getID_Detalle());

    if(pos == -1)
    {
        return false;
    }

    FILE* pventa;
    pventa = fopen(archivo_DetalleVenta,"rb+");

    if(pventa == nullptr)
    {
        return false;
    }

    fseek(pventa,pos*sizeof(Detalle_Venta),SEEK_SET);

    int escrito = fwrite(&reg,sizeof(Detalle_Venta),1,pventa);

    fclose(pventa);

    return escrito;

}
int DetalleVentaArchivo::obtenerID(){


    int bytes ;

    int numRegistros ;

    FILE* pventa ;

    pventa = fopen(archivo_DetalleVenta,"rb");

    if(pventa == nullptr){ return 1 ; }

    fseek(pventa,0,SEEK_END) ;

    bytes = ftell(pventa) ;

    fclose(pventa) ;

    if(bytes == 0){ return 1 ; }

    numRegistros = bytes / sizeof(Detalle_Venta) ;

    return numRegistros + 1 ;

}

int DetalleVentaArchivo::getCantidadRegistros()
{

    FILE* pventa;
    pventa = fopen(archivo_DetalleVenta, "rb");

    if(pventa == nullptr)
    {

        cout << "NO SE PUDO CREAR EL ARCHIVO" ;
        return false ;
    }

    fseek(pventa,0,SEEK_END);
    int tamanoBytes = ftell(pventa);

    fclose(pventa);

    return tamanoBytes / sizeof(Detalle_Venta);

}
int DetalleVentaArchivo::buscarPosicion(int idDetalle)
{

    Detalle_Venta reg;

    int cantidad = getCantidadRegistros();

    for (int i = 0; i < cantidad; i++)
    {

        reg = leer(i);

        if(reg.getID_Detalle() == idDetalle)
        {

            return i;
        }
    }

    return -1;

}

void DetalleVentaArchivo::generarReporteRecaudacionPorProducto() {

    Detalle_Venta detalle ;

    ProductoArchivo archivoProducto ;

    VentaArchivo archivoVenta ;

    // ASIGNACION DINAMICA

    int max_capacidad = getCantidadRegistros() ;

    if (max_capacidad == 0) {

        cout << "El archivo de detalles de venta esta vacio. No hay datos para el reporte." << endl ;

        return ;
    }

    // Declaracion de punteros para los arreglos paralelos dinamicos

    int *ids_productos = new int[max_capacidad] ;

    float *totales_recaudados = new float[max_capacidad] ;

    // Inicialización de los arreglos a 0

    for(int i = 0; i < max_capacidad; i++) {

        ids_productos[i] = 0 ;

        totales_recaudados[i] = 0.0 ;
    }

    int total_productos_distintos = 0 ;

    float granTotal = 0.0 ;

    // ITERAR Y ACUMULAR

    for (int i = 0; i < max_capacidad; i++) {

        detalle = leer(i) ;

        //  EXCLUIR VENTAS ANULADAS

        // 1. Busco el registro de Venta asociado a este detalle.

        int id_venta_actual = detalle.getID_Venta() ;

        int pos_venta = archivoVenta.buscarPosicion(id_venta_actual) ;

        bool venta_activa = false ;

        if (pos_venta != -1) {

            Venta venta_asociada = archivoVenta.leer(pos_venta) ;

            // 2. Verificamos el estado de la Venta (Baja Lógica).

            venta_activa = venta_asociada.getEstado() ; // true = Activa, false = Anulada
        }

        // Solo se acumula si la venta NO fue anulada (estado = true)

        if (venta_activa) {

            float recaudacion_linea = detalle.getCantidad() * detalle.getPrecio_Unitario() ;

            int id_producto_actual = detalle.getID_Producto() ;

            // Búsqueda para encontrar el ID

            int posicion_encontrada = -1 ;

            for (int j = 0; j < total_productos_distintos; j++) {

                if (ids_productos[j] == id_producto_actual) {

                    posicion_encontrada = j ;

                    break ;
                }
            }

            // Acumular o Agregar

            if (posicion_encontrada != -1) {

                // El producto ya existe, acumular

                totales_recaudados[posicion_encontrada] += recaudacion_linea ;

            } else {

                // Producto nuevo, agregar

                if (total_productos_distintos < max_capacidad) {

                    ids_productos[total_productos_distintos] = id_producto_actual ;

                    totales_recaudados[total_productos_distintos] = recaudacion_linea ;

                    total_productos_distintos++ ;

                } else {

                    cout << "[ERROR CRITICO] No se pudo agregar al reporte.";
                }
            }
        }
    }

    // IMPRIMIR EL REPORTE Y CALCULAR EL TOTAL GENERAL

    cout << "------------------------------------------" << endl ;

    // Iterar solo sobre los elementos que contienen datos

    for (int i = 0; i < total_productos_distintos; i++) {

        int id_prod = ids_productos[i] ;

        float total_recaudacion = totales_recaudados[i] ;

        // Busco el producto en su archivo para obtener la descripcion

        Producto producto ;

        int pos = archivoProducto.buscarPosicion(id_prod) ;

        if (pos != -1) { producto = archivoProducto.leer(pos) ; }

        // Muestro ID y Descripcion

        cout << "ID: " << id_prod ;

        if (producto.getID_Producto() >= 0) {

            cout << " | Producto: " << producto.getDescripcion() ;

        } else {

            cout << "Producto: (Descripcion no disponible)" ;
        }

        // Mostrar Recaudación

        cout << " | Recaudacion Total: $" << total_recaudacion << endl ;

        cout << "------------------------------------------" << endl ;

        granTotal += total_recaudacion ;
    }

    // 4. MOSTRAR EL TOTAL HISTÓRICO Y LIBERAR MEMORIA

    cout  << "TOTAL RECAUDADO POR TODOS LOS PRODUCTOS (SIN VENTAS ANULADAS): $" << granTotal << endl ;

    cout << "------------------------------------------" << endl ;

    // libero

    delete[] ids_productos ;

    delete[] totales_recaudados ;

    system("pause") ;
}
