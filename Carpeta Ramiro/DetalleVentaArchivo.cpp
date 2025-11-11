#include "DetalleVentaArchivo.h"
#include "ProductoArchivo.h"
#include <iostream>
#include <cstdio>
#include <new>

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
int DetalleVentaArchivo::obtenerID()
{

    int Bytes;
    int numRegistros;
    FILE* pventa;
    pventa = fopen(archivo_DetalleVenta,"rb");

    if(pventa == nullptr)
    {
        return 1;
    }

    fseek(pventa,0,SEEK_END);

    Bytes = ftell(pventa);

    fclose(pventa);

    if(Bytes == 0)
    {
        return 1;
    }

    numRegistros = Bytes / sizeof(Detalle_Venta);

    return numRegistros + 1;

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

int DetalleVentaArchivo::buscarIndiceDeMarca(const char* marcaBuscada, char** marcas, int tamActual)
{
    for (int i = 0; i < tamActual; i++) {
        if (strcmp(marcas[i], marcaBuscada) == 0) {
            return i; // La encontramos en el índice 'i'
        }
    }
    return -1; // No se encontró, es una marca nueva
}

 void DetalleVentaArchivo::reportePorMarca(){

    // --- PASO 1: Preparar Instancias de Archivo ---
    ProductoArchivo archivoProductos; // La clase de detalle "usa" la de producto

    // Usamos 'this->' para llamar a métodos de esta misma clase
    int cantDetalles = this->getCantidadRegistros();

    if (cantDetalles == 0) {
        cout << "No hay detalles de venta para reportar." << endl;
        system("pause");
        return; // Salimos de la función
    }

    // --- PASO 2: Preparar Arrays DINÁMICOS ---
    int capacidadActual = 10;
    int cantMarcasEncontradas = 0;
    int cantidadTotal = 0;

    int* contadoresReporte = new int[capacidadActual];
    char** marcasReporte = new char*[capacidadActual];

    if (contadoresReporte == NULL || marcasReporte == NULL) {
        cout << "Error: No hay memoria suficiente para el reporte." << endl;
        system("pause");
        return;
    }

    for(int i=0; i<capacidadActual; i++){
        contadoresReporte[i] = 0;
    }


    // --- PASO 3: Leer Detalles y Contar ---
    for (int i = 0; i < cantDetalles; i++) {

        Detalle_Venta regDetalle = this->leer(i);

        cantidadTotal += regDetalle.getCantidad();
        int idProd = regDetalle.getID_Producto();
        int cantidad = regDetalle.getCantidad();

        char marcaActual[30];
        archivoProductos.getMarcaPorID(idProd, marcaActual, 30);

        // 'this->'
        int indice = this->buscarIndiceDeMarca(marcaActual, marcasReporte, cantMarcasEncontradas);

        // 3c. Contar
        if (indice == -1) { // Marca NUEVA

            if (cantMarcasEncontradas == capacidadActual) {
                int nuevaCapacidad = capacidadActual * 2;
                int* nuevosContadores = new int[nuevaCapacidad];
                char** nuevasMarcas = new char*[nuevaCapacidad];

                if (nuevosContadores == NULL || nuevasMarcas == NULL) {
                     cout << "Error: Falla al redimensionar la memoria." << endl;
                     break;
                }

                for (int j = 0; j < capacidadActual; j++) {
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
            if(marcasReporte[cantMarcasEncontradas] == NULL){
                cout << "Error: Falla al asignar memoria para string." << endl;
                break;
            }

            strncpy(marcasReporte[cantMarcasEncontradas], marcaActual, 29);
            marcasReporte[cantMarcasEncontradas][29] = '\0';
            contadoresReporte[cantMarcasEncontradas] = cantidad;
            cantMarcasEncontradas++;

        } else { // Marca EXISTENTE
            contadoresReporte[indice] += cantidad;
        }
    }

    // --- PASO 4: Mostrar Reporte ---
    system("cls"); // Limpiamos la pantalla
    cout << "--- REPORTE DE UNIDADES VENDIDAS POR MARCA ---" << endl;
    cout << "----------------------------------------------" << endl;

    if (cantMarcasEncontradas == 0) {
        cout << "No se encontraron ventas detalladas para reportar." << endl;
    } else {
        for (int i = 0; i < cantMarcasEncontradas; i++) {
            cout << "Marca: " << marcasReporte[i]
                 << " - Total Unidades: " << contadoresReporte[i] << endl;
        }
    }
    cout << "----------------------------------------------" << endl;
    cout << "UNIDADES TOTALES (TODAS LAS MARCAS): " << cantidadTotal << endl;
    cout << "----------------------------------------------" << endl;


    // --- PASO 5: Liberar la Memoria Dinámica ---
    for (int i = 0; i < cantMarcasEncontradas; i++) {
        delete[] marcasReporte[i];
    }
    delete[] marcasReporte;
    delete[] contadoresReporte;

    system("pause");
 }
