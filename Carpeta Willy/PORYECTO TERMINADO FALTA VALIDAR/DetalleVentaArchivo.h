#pragma once
#include "Detalle_Venta.h"
#include "Venta.h"
#include <cstdio>


class DetalleVentaArchivo
{
private:

    const char* archivo_DetalleVenta = "DetalleVenta.dat";

     const char* archivo_DetalleVentabkp = "DetalleVenta.bkp";

public:

    bool guardar(const Detalle_Venta &reg) ;

    Detalle_Venta leer(int pos) ;

    bool bajaLogica(int idDetalle) ;

    bool darDealta(int idDetalle) ;

    bool modificar(const Detalle_Venta &reg) ;

    int obtenerID() ;

    int getCantidadRegistros() ;

    int buscarPosicion(int idDetalle) ;

    void generarReporteRecaudacionPorProducto() ;

    void generarReporteRecaudacionPorTipoProducto() ;

    bool hacerBackup() ;

    bool restaurarBackup() ;

};

