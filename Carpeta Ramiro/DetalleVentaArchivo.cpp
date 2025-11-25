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

        cout << "NO SE PUDO CREAR EL ARCHIVO " << endl ;

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

        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl  ;

        return reg ;
    }

    fseek(pventa,pos*sizeof(Detalle_Venta), SEEK_SET) ;

    fread(&reg,sizeof(Detalle_Venta),1,pventa) ;

    fclose(pventa) ;

    return reg ;

}

bool DetalleVentaArchivo::bajaLogica(int idVenta)
{
    Detalle_Venta reg;
    int cantInactivos = 0;

    const int cantidad = getCantidadRegistros();

    for (int i = 0; i < cantidad; i++)
    {
        reg = leer(i);

        if(reg.getID_Venta() == idVenta)
        {

            reg.setEstado(false);
            modificar(reg);
            cantInactivos++;
        }

    }

    if(cantInactivos != 0)
    {
        return true;
    }else
    {
        return false;
    }
}

bool DetalleVentaArchivo::darDealta(int idVenta)
{
    Detalle_Venta reg;
    int cantActivos = 0;

    const int cantidad = getCantidadRegistros();

    for (int i = 0; i < cantidad; i++)
    {
        reg = leer(i);

        if(reg.getID_Venta() == idVenta)
        {
            reg.setEstado(true);
            modificar(reg);
            cantActivos++;
        }
    }
    if(cantActivos != 0)
    {
        return true;
    }else
    {
        return false;
    }
}

bool DetalleVentaArchivo::modificar(const Detalle_Venta &reg)
{

    int pos;

    pos = buscarPosicion(reg.getID_Detalle()) ;

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
int DetalleVentaArchivo::obtenerID()
{


    int bytes ;

    int numRegistros ;

    FILE* pventa ;

    pventa = fopen(archivo_DetalleVenta,"rb");

    if(pventa == nullptr)
    {
        return 1 ;
    }

    fseek(pventa,0,SEEK_END) ;

    bytes = ftell(pventa) ;

    fclose(pventa) ;

    if(bytes == 0)
    {
        return 1 ;
    }

    numRegistros = bytes / sizeof(Detalle_Venta) ;

    return numRegistros + 1 ;

}

int DetalleVentaArchivo::getCantidadRegistros()
{

    FILE* pventa;

    pventa = fopen(archivo_DetalleVenta, "rb");

    if(pventa == nullptr)
    {

        cout << "NO SE PUDO CREAR EL ARCHIVO" << endl  ;

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

int DetalleVentaArchivo::buscarIndiceDeMarca(const char* marcaBuscada, char** marcas, int tamActual)
{
    for (int i = 0; i < tamActual; i++)
    {
        if (strcmp(marcas[i], marcaBuscada) == 0)
        {
            return i;
        }
    }
    return -1;
}

void DetalleVentaArchivo::generarReporteRecaudacionPorProducto()
{

    Detalle_Venta detalle ;

    ProductoArchivo archivoProducto ;

    VentaArchivo archivoVenta ;

    int max_capacidad = getCantidadRegistros() ;

    if (max_capacidad == 0)
    {

        cout << "El archivo de detalles de venta esta vacio. No hay datos para el reporte." << endl ;

        return ;
    }

    int *ids_productos = new int[max_capacidad] ;

    float *totales_recaudados = new float[max_capacidad] ;

    for(int i = 0; i < max_capacidad; i++)
    {

        ids_productos[i] = 0 ;

        totales_recaudados[i] = 0.0 ;
    }

    int total_productos_distintos = 0 ;

    float granTotal = 0.0 ;

    for (int i = 0; i < max_capacidad; i++)
    {

        detalle = leer(i) ;

        int id_venta_actual = detalle.getID_Venta() ;

        int pos_venta = archivoVenta.buscarPosicion(id_venta_actual) ;

        bool venta_activa = false ;

        if (pos_venta != -1)
        {

            Venta venta_asociada = archivoVenta.leer(pos_venta) ;

            venta_activa = venta_asociada.getEstado() ;
        }



        if (venta_activa)
        {

            float recaudacion_linea = detalle.getCantidad() * detalle.getPrecio_Unitario() ;

            int id_producto_actual = detalle.getID_Producto() ;

            int posicion_encontrada = -1 ;

            for (int j = 0; j < total_productos_distintos; j++)
            {

                if (ids_productos[j] == id_producto_actual)
                {

                    posicion_encontrada = j ;

                    break ;
                }
            }



            if (posicion_encontrada != -1)
            {



                totales_recaudados[posicion_encontrada] += recaudacion_linea ;

            }
            else
            {


                if (total_productos_distintos < max_capacidad)
                {

                    ids_productos[total_productos_distintos] = id_producto_actual ;

                    totales_recaudados[total_productos_distintos] = recaudacion_linea ;

                    total_productos_distintos++ ;

                }
                else
                {

                    cout << "ERROR. No se pudo agregar al reporte." ;
                }
            }
        }
    }


    cout << "RECAUDACION HISTORICA POR PRODUCTO" << endl ;

    cout << "------------------------------------------" << endl ;

    for (int i = 0; i < total_productos_distintos; i++)
    {

        int id_prod = ids_productos[i] ;

        float total_recaudacion = totales_recaudados[i] ;

        Producto producto ;

        int pos = archivoProducto.buscarPosicion(id_prod) ;

        if (pos != -1)
        {

            producto = archivoProducto.leer(pos) ;
        }


        cout << "ID: " << id_prod ;

        if (producto.getID_Producto() >= 0)
        {

            cout << " | Producto: " << producto.getDescripcion() ;

        }
        else
        {

            cout << "Producto: (Descripcion no disponible)" ;
        }

        cout << " | Recaudacion Total: $" << total_recaudacion << endl ;

        cout << "------------------------------------------" << endl ;

        granTotal += total_recaudacion ;
    }

    cout  << "TOTAL RECAUDADO POR TODOS LOS PRODUCTOS (SIN VENTAS ANULADAS): $" << granTotal << endl ;

    cout << "------------------------------------------" << endl ;

    delete[] ids_productos ;

    delete[] totales_recaudados ;

}


void DetalleVentaArchivo::reportePorMarca()
{

    ProductoArchivo archivoProductos;

    int cantDetalles = this->getCantidadRegistros();

    if (cantDetalles == 0)
    {
        cout << "No hay detalles de venta para reportar." << endl;

        return;
    }

    int capacidadActual = 10;

    int cantMarcasEncontradas = 0;

    int cantidadTotal = 0;

    int* contadoresReporte = new int[capacidadActual];

    char** marcasReporte = new char*[capacidadActual];

    if (contadoresReporte == NULL || marcasReporte == NULL)
    {
        cout << "Error: No hay memoria suficiente para el reporte." << endl;

        return;
    }

    for(int i=0; i<capacidadActual; i++)
    {
        contadoresReporte[i] = 0;
    }



    for (int i = 0; i < cantDetalles; i++)
    {

        Detalle_Venta regDetalle = this->leer(i);

        cantidadTotal += regDetalle.getCantidad();

        int idProd = regDetalle.getID_Producto();

        int cantidad = regDetalle.getCantidad();

        char marcaActual[30];

        archivoProductos.MarcaPorID(idProd, marcaActual, 30);


        int indice = this->buscarIndiceDeMarca(marcaActual, marcasReporte, cantMarcasEncontradas);


        if (indice == -1)
        {

            if (cantMarcasEncontradas == capacidadActual)
            {
                int nuevaCapacidad = capacidadActual * 2;

                int* nuevosContadores = new int[nuevaCapacidad];

                char** nuevasMarcas = new char*[nuevaCapacidad];

                if (nuevosContadores == NULL || nuevasMarcas == NULL)
                {
                    cout << "Error: Falla al redimensionar la memoria." << endl;
                    break;
                }

                for (int j = 0; j < capacidadActual; j++)
                {
                    nuevosContadores[j] = contadoresReporte[j];

                    nuevasMarcas[j] = marcasReporte[j];
                }

                delete[] contadoresReporte;

                delete[] marcasReporte;

                contadoresReporte = nuevosContadores;

                marcasReporte = nuevasMarcas;

                capacidadActual = nuevaCapacidad;
            }

            marcasReporte[cantMarcasEncontradas] = new char[30];

            if(marcasReporte[cantMarcasEncontradas] == NULL)
            {

                cout << "Error: Falla al asignar memoria para string." << endl;

                break;
            }

            strncpy(marcasReporte[cantMarcasEncontradas], marcaActual, 29);

            marcasReporte[cantMarcasEncontradas][29] = '\0';

            contadoresReporte[cantMarcasEncontradas] = cantidad;

            cantMarcasEncontradas++;

        }
        else
        {
            contadoresReporte[indice] += cantidad;
        }
    }


    cout << "REPORTE DE UNIDADES VENDIDAS POR MARCA" << endl;

    cout << "----------------------------------------------" << endl;

    if (cantMarcasEncontradas == 0)
    {
        cout << "No se encontraron ventas detalladas para reportar." << endl;
    }
    else
    {
        for (int i = 0; i < cantMarcasEncontradas; i++)
        {
            cout << "Marca: " << marcasReporte[i]

            << " - Total Unidades: " << contadoresReporte[i] << endl;
        }
    }
    cout << "----------------------------------------------" << endl;
    cout << "UNIDADES TOTALES (TODAS LAS MARCAS): " << cantidadTotal << endl;
    cout << "----------------------------------------------" << endl;


    for (int i = 0; i < cantMarcasEncontradas; i++)
    {

    delete[] marcasReporte[i];
    }

    delete[] marcasReporte;
    delete[] contadoresReporte;


}

void DetalleVentaArchivo::generarReporteRecaudacionPorTipoProducto()
{

    const int MAX_TIPOS = 3 ;

    float totales_recaudados[MAX_TIPOS] = {} ;

    int tipos_existentes[MAX_TIPOS] = {} ;

    int total_tipos_distintos = 0 ;

    float granTotal = 0.0 ;

    ProductoArchivo archivoProducto ;

    VentaArchivo archivoVenta ;

    int cantidadDetalles = getCantidadRegistros() ;

    for (int i = 0; i < cantidadDetalles; i++)
    {

        Detalle_Venta detalle = leer(i) ;

        if (!detalle.getEstado()) continue ;

        int idVenta = detalle.getID_Venta() ;

        int posVenta = archivoVenta.buscarPosicion(idVenta) ;

        if (posVenta == -1) continue ;

        Venta venta = archivoVenta.leer(posVenta) ;

        if (!venta.getEstado()) continue ;

        int posProd = archivoProducto.buscarPosicion(detalle.getID_Producto()) ;

        if (posProd == -1) continue ;

        Producto regP = archivoProducto.leer(posProd) ;

        int tipo_prod = regP.getTipoProducto() ;

        float recaudacion = detalle.getCantidad() * detalle.getPrecio_Unitario() ;

        bool encontrado = false ;

        for (int j = 0; j < total_tipos_distintos; j++)
        {

            if (tipos_existentes[j] == tipo_prod)
            {

                totales_recaudados[j] += recaudacion ;

                encontrado = true ;

                break ;
            }
        }

        if (!encontrado && total_tipos_distintos < MAX_TIPOS)
        {

            tipos_existentes[total_tipos_distintos] = tipo_prod ;

            totales_recaudados[total_tipos_distintos] = recaudacion ;

            total_tipos_distintos++ ;
        }
    }

    cout << "RECUADACION HISTORICA POR TIPO DE PORDUCTO" << endl ;

    cout << "--------------------------------------------------------" << endl;

    for (int i = 0; i < total_tipos_distintos; i++)
    {

        string nombreTipo ;

        switch (tipos_existentes[i])
        {

        case 1:

            nombreTipo = "PCs" ;

            break ;

        case 2:

            nombreTipo = "Accesorios" ;

            break ;

        case 3:

            nombreTipo = "Otros" ;

            break ;

        default:

            nombreTipo = "Desconocido" ;

            break ;
        }

        cout << "Tipo de Producto: " << nombreTipo ;

        cout << " | Recaudacion Total: $" << totales_recaudados[i] << endl ;

        cout << "--------------------------------------------------------" << endl ;

        granTotal += totales_recaudados[i] ;
    }

    cout << "Total recaudado por todos los tipos de productos: $" << granTotal << endl ;

    cout << "--------------------------------------------------------" << endl ;
}


bool DetalleVentaArchivo::hacerBackup ()
{

    FILE* pArchivoOriginal = fopen(archivo_DetalleVenta,"rb") ;

    if(pArchivoOriginal == nullptr)
    {

        return false ;
    }

    FILE* pBackup = fopen(archivo_DetalleVenta_Backup,"wb") ;

    if(pBackup == nullptr)
    {

        fclose(pArchivoOriginal) ;

        return false ;
    }

    char temporal[1024] ;

    int bytesLeidos ;

    while((bytesLeidos = fread(temporal, 1, 1024, pArchivoOriginal)) > 0)
    {

        fwrite(temporal, 1, bytesLeidos, pBackup) ;
    }

    fclose(pArchivoOriginal) ;

    fclose(pBackup) ;

    return true ;

}

bool DetalleVentaArchivo::restaurarBackup ()
{

    FILE* pArchivoBkp = fopen(archivo_DetalleVenta_Backup, "rb") ;

    if (pArchivoBkp == NULL)
    {

        return false ;
    }

    FILE* pArchivoOriginal = fopen(archivo_DetalleVenta, "wb") ;

    if (pArchivoOriginal == NULL)
    {

        fclose(pArchivoBkp) ;

        return false ;
    }

    char temporal[1024] ;

    int bytesLeidos ;

    while ((bytesLeidos = fread(temporal, 1, 1024, pArchivoBkp)) > 0)
    {

        fwrite(temporal, 1, bytesLeidos, pArchivoOriginal) ;
    }

    fclose(pArchivoBkp) ;

    fclose(pArchivoOriginal) ;

    return true ;

}
