#pragma once
#include "Venta.h"
#include <cstdio>


class VentaArchivo {

    private:

        const char *archivo_Venta = "Ventas.dat" ;

    public:

        bool guardar(const Venta &reg) ;

        Venta leer(int pos) ;

        bool bajaLogica(int id_venta) ;

        bool modificar(const Venta &reg) ;

        int obtenerID() ;

        int getCantidadRegistros() ;

        int buscarPosicion(int id_venta) ;


};
