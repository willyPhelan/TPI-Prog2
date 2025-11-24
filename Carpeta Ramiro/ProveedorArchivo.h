#ifndef PROVEEDORARCHIVO_H_INCLUDED
#define PROVEEDORARCHIVO_H_INCLUDED
#pragma once
#include "Proveedor.h"
#include <cstdio>

class ProveedorArchivo
{
private: /// Atributos

    const char *archivo_Proveedor = "Proveedores.dat";

    const char *archivo_Proveedor_Backup = "Proveedores_Backup.bkp";

public: /// Metodos

/// FUNCIONES ABML

    bool guardar (const Proveedor &reg);

    bool bajaLogica (int id_persona);

    bool altaLogica(int id_persona) ;

    Proveedor leer (int pos);

    bool modificar (const Proveedor &reg);

    void modificarCampo ();

/// FUNCIONES AUXILIARES

    int getCantidadRegistros ();

    int buscarPosicion (int id_persona);

    bool validarCUIT (std::string cuit);

/// BACKUPS

    bool hacerBackup ();

    bool restaurarBackup ();

};



#endif // PROVEEDORARCHIVO_H_INCLUDED
