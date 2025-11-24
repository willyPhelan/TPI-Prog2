#pragma once
#include "Detalle_Venta.h"

#include <cstdio>


class DetalleVentaArchivo
{
private:

    const char* archivo_DetalleVenta = "DetalleVenta.dat";

    const char *archivo_DetalleVenta_Backup = "DetalleVenta_Backup.bkp";

public:

    bool guardar(const Detalle_Venta &reg) ;

    Detalle_Venta leer(int pos) ;

    bool bajaLogica(int idDetalle) ;

    bool darDealta(int idDetalle);
    bool modificar(const Detalle_Venta &reg);
    int obtenerID();
    int getCantidadRegistros();
    int buscarPosicion(int idVenta);



    int buscarIndiceDeMarca(const char* marcaBuscada, char** marcas, int tamActual);

    void generarReporteRecaudacionPorProducto() ;

    void reportePorMarca ();

    void generarReporteRecaudacionPorTipoProducto ();

    bool hacerBackup ();

    bool restaurarBackup ();

};

