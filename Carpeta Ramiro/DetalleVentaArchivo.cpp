#include "DetalleVentaArchivo.h"
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
