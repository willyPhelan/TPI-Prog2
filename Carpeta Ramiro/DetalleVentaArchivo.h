#pragma once
#include "Detalle_Venta.h"
#include <cstdio>


class DetalleVentaArchivo
{
    private:

    const char* archivo_DetalleVenta = "DetalleVenta.dat";

    public:

        bool guardar(const Detalle_Venta &reg);
        Detalle_Venta leer(int pos);
        bool bajaLogica(int idDetalle);
        bool altaLogica (int id_persona);
        bool modificar(const Detalle_Venta &reg);
        int obtenerID();
        int getCantidadRegistros();
        int buscarPosicion(int idDetalle);

};

