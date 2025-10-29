#include "EmpleadoArchivo.h"
#include <iostream>
#include <cstdio>

using namespace std;

/// FUNCIONES ABML

bool EmpleadoArchivo::guardar(const Empleado &reg)
{
    FILE *archivo; // Se crea el puntero para utilizar el archivo

    archivo = fopen(archivo_Empleado, "ab"); // Se abre el archivo en modo append binary

    if (archivo == nullptr) // Se verifica si se abrio correctamente el archivo
    {
        cout << "NO SE PUDO CREAR EL ARCHIVO. " << endl;
        return false;
    }

    int escribio = fwrite(&reg, sizeof (Empleado), 1, archivo); // Se escribe la informacion en el archivo

    fclose(archivo); // Se cierra el archivo

    return escribio; // Devuelvo la variable escribio

}

bool EmpleadoArchivo::bajaLogica(int id_persona)
{
    int pos = buscarPosicion(id_persona);

    if (pos == -1)
    {
        cout << "El ID que ingreso es incorrecto. " << endl;
        system ("pause");
        return false;
    }

    Empleado reg = leer (pos);

    reg.setEstado(false);

    FILE *archivo;

    archivo = fopen (archivo_Empleado, "rb+");
    if (archivo == nullptr)
    {
        return false;
    }

    fseek (archivo, pos * sizeof (Empleado), SEEK_SET);

    int escrito = fwrite (&reg, sizeof (Empleado), 1, archivo);

    fclose (archivo);

    return escrito;

}


Empleado EmpleadoArchivo::leer (int pos)
{
    Empleado reg;

    FILE *archivo;
    archivo = fopen(archivo_Empleado, "rb");

    if (archivo == nullptr)
    {
        return reg;
    }

    fseek (archivo, pos * sizeof (Empleado), SEEK_SET);

    fread (&reg, sizeof (Empleado), 1, archivo);

    fclose (archivo);

    return reg;
}

bool EmpleadoArchivo::modificar (const Empleado &reg)
{
    int pos = buscarPosicion (reg.getID());

    if (pos == -1)
    {
        cout << "El ID ingresado es incorrecto. " << endl;
        return false;
    }

    FILE *archivo;

    archivo = fopen (archivo_Empleado, "rb+");

    if (archivo == nullptr)
    {
        return false;
    }

    fseek (archivo, pos * sizeof (Empleado), SEEK_SET);

    int escribio = fwrite (&reg, sizeof (Empleado), 1, archivo);

    fclose (archivo);

    return escribio;
}

/// FUNCIONES AUXILIARES

int EmpleadoArchivo::buscarPosicion (int id_persona)
{
    Empleado reg;

    int cantReg = getCantidadRegistros();

    for (int i = 0; i<cantReg; i++)
    {
        reg = leer (i);

        if (reg.getID() == id_persona)
        {
            return i;
        }
    }
    return -1;
}

int EmpleadoArchivo::getCantidadRegistros ()
{
    FILE *archivo;

    archivo = fopen(archivo_Empleado, "rb");

    if (archivo == nullptr)
    {
        return 0;
    }

    fseek(archivo, 0, SEEK_END);

    int tamanio = ftell(archivo);

    fclose(archivo);

    return tamanio / sizeof (Empleado);
}
