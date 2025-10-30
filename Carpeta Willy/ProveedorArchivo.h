#ifndef PROVEEDORARCHIVO_H_INCLUDED
#define PROVEEDORARCHIVO_H_INCLUDED
#pragma once
#include "Proveedor.h"
#include <cstdio>

class ProveedorArchivo
{
private: /// Atributos

    const char *archivo_Proveedor = "Proveedores.dat";

public: /// Metodos

/// FUNCIONES ABML

    bool guardar (const Proveedor &reg);

    bool bajaLogica (int id_persona);

    bool altaLogica(int id_persona) ;

    Proveedor leer (int pos);

    bool modificar (const Proveedor &reg);

/// FUNCIONES AUXILIARES

    int getCantidadRegistros ();

    int buscarPosicion (int id_persona);

};

#endif // PROVEEDORARCHIVO_H_INCLUDED
