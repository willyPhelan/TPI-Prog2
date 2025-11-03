#include "ProveedorArchivo.h"
#include <iostream>
#include <cstdio>


using namespace std;

/// FUNCIONES ABML

bool ProveedorArchivo::guardar(const Proveedor &reg)
{

    FILE *archivo ;

    archivo = fopen (archivo_Proveedor, "ab") ;

    if (archivo == nullptr)
    {

        cout << "NO SE PUDO CREAR EL ARCHIVO. " << endl ;

        return false ;
    }

    int escribio = fwrite (&reg, sizeof (Proveedor), 1, archivo) ;

    fclose (archivo) ;

    return escribio ;

}

bool ProveedorArchivo::bajaLogica(int id_persona)
{

    int pos = buscarPosicion(id_persona) ;

    if (pos == -1)
    {

        cout << "El ID que ingreso es incorrecto. " << endl ;

        system ("pause") ;

        return false ;
    }

    Proveedor reg = leer (pos) ;

    reg.setEstado(false) ;

    FILE *archivo ;

    archivo = fopen (archivo_Proveedor, "rb+") ;

    if (archivo == nullptr)
    {
        return false ;
    }

    fseek (archivo, pos * sizeof (Proveedor), SEEK_SET) ;

    int escrito = fwrite (&reg, sizeof (Proveedor), 1, archivo) ;

    fclose (archivo) ;

    return escrito ;
}

bool ProveedorArchivo::altaLogica(int id_persona)
{

    int pos = buscarPosicion(id_persona);

    if (pos == -1)
    {
        cout << "El ID que ingreso es incorrecto. " << endl;
        system ("pause");
        return false;
    }

    Proveedor reg = leer (pos);

    reg.setEstado(true);

    FILE *archivo;

    archivo = fopen (archivo_Proveedor, "rb+");

    if (archivo == nullptr)
    {
        return false;
    }

    fseek (archivo, pos * sizeof (Proveedor), SEEK_SET);

    int escrito = fwrite (&reg, sizeof (Proveedor), 1, archivo);

    fclose (archivo);

    return escrito;
}

Proveedor ProveedorArchivo::leer (int pos)
{

    Proveedor reg ;

    FILE *archivo ;

    archivo = fopen (archivo_Proveedor, "rb") ;

    if (archivo == nullptr)
    {
        return reg ;
    }

    fseek (archivo, pos * sizeof (Proveedor), SEEK_SET) ;

    fread (&reg, sizeof (Proveedor), 1, archivo) ;

    fclose (archivo) ;

    return reg ;
}

bool ProveedorArchivo::modificar(const Proveedor &reg)
{

    int pos = buscarPosicion (reg.getID()) ;

    if (pos == -1)
    {

        cout << "El ID ingresado es incorrecto. " << endl ;

        return false ;
    }

    FILE *archivo ;

    archivo = fopen (archivo_Proveedor, "rb+") ;

    if (archivo == nullptr)
    {
        return false ;
    }

    fseek (archivo, pos * sizeof (Proveedor), SEEK_SET) ;

    int escribio = fwrite (&reg, sizeof (Proveedor), 1, archivo) ;

    fclose (archivo) ;

    return escribio ;
}

/// FUNCIONES AUXILIARES

int ProveedorArchivo::buscarPosicion (int id_persona)
{

    Proveedor reg ;

    int cantReg = getCantidadRegistros() ;

    for (int i = 0; i<cantReg; i++)
    {

        reg = leer (i) ;

        if (reg.getID() == id_persona)
        {

            return i ;
        }
    }

    return -1 ;
}

int ProveedorArchivo::getCantidadRegistros ()
{

    FILE *archivo ;

    archivo = fopen (archivo_Proveedor, "rb") ;

    if (archivo == nullptr)
    {
        return 0 ;
    }

    fseek (archivo, 0, SEEK_END) ;

    int tamanio = ftell (archivo) ;

    fclose (archivo) ;

    return tamanio / sizeof (Proveedor) ;
}
