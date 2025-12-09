#pragma once
#include "Proveedor.h"
#include <cstdio>

class ProveedorArchivo{

private:

    const char *archivo_Proveedor = "Proveedores.dat" ;

    const char *archivo_Proveedor_Backup = "Proveedores_Backup.bkp" ;

public:


    bool guardar(const Proveedor &reg) ;

    bool bajaLogica(int id_persona) ;

    bool altaLogica(int id_persona) ;

    Proveedor leer(int pos) ;

    bool modificar(const Proveedor &reg) ;

    void modificarCampo() ;

    int getCantidadRegistros() ;

    int buscarPosicion(int id_persona) ;

    bool validarCUIT(std::string cuit) ;

    bool hacerBackup() ;

    bool restaurarBackup() ;

} ;


