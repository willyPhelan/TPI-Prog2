#include "ProveedorArchivo.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include "Utils.h"


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


bool ProveedorArchivo::validarCUIT(string cuit)
{

    Proveedor proveedor1;

    int const cantReg = getCantidadRegistros();

    int opcion;

    for (int i = 0; i <cantReg ; i++)
    {

        proveedor1 = leer(i) ;

        while (strcmp(cuit.c_str(), proveedor1.getCuit().c_str()) == 0 && proveedor1.getEstado() == true)
        {

            cout << "El CUIT ya corresponde a un proveedor existente. Desea salir o introducir otro CUIT? (1- Agregar otro CUIT, 2- Salir):" ;

            cin >> opcion ;

            switch (opcion)
            {

            case 1:

                cout << "Ingrese el nuevo CUIT: "  ;

                cin >> cuit ;

                break ;

            case 2:

                cout << endl << "Saliendo..." << endl ;

                return false;

                break ;

            default:

                cout << "La opcion que eligio es invalida. Intentelo de nuevo. " << endl ;

                break ;
            }

        }
    }

    return true;
}


void ProveedorArchivo::modificarCampo ()
{

    Proveedor proveedor1;

    string datos;

    int datos2;

    cout << "Modificar un campo especifico de un proveedor " << endl;

    cout << "-------------------------------------------" << endl;

    cout << "Ingrese el ID del proveedor a modificar: ";

    cin >> datos2;

    int pos = buscarPosicion (datos2);

    if (pos == -1)
    {

        cout << "ERROR: ID de proveedor no encontrado. " << endl;

        system ("pause");

        return;
    }

    proveedor1 = leer (pos);

    do
    {

        system ("cls");

        cout << "Proveedor a modificar (ID: " << proveedor1.getID() << ")" << endl;

        cout << "-----------------------------" << endl ;

        proveedor1.mostrar();

        cout << "Seleccione una opcion o el campo a modificar: " << endl;

        cout << "1. Nombre" << endl;

        cout << "2. Telefono" << endl;

        cout << "3. Direccion" << endl;

        cout << "4. CUIT" << endl;

        cout << "5. Mail" << endl;

        cout << "6. Tipo de proveedor" << endl;

        cout << "7. Finalizar modificaciones y volver al menu anterior" << endl;

        cout << "Opcion: " << endl;

        cin >> datos2;

        cout << endl;

        switch (datos2)
        {

        case 1:   // Modificar nombre (string)
        {

            cout << "Modificar nombre: " << endl;

            cin >> datos;

            proveedor1.setNombre(datos);

            if (modificar(proveedor1) == true)
            {

                cout << "Nombre modificado correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar el nombre correctamente. " << endl;
            }

            system ("pause");

            break;
        }

        case 2:   // Modificar telefono (string)
        {

            cout << "Modificar telefono: " << endl;

            cin >> datos;

            proveedor1.setTelefono(datos);

            if (modificar(proveedor1) == true)
            {

                cout << "Telefono modificado correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar el telefono correctamente. " << endl;
            }

            system ("pause");

            break;

        }

        case 3:  // Modificar direccion (string)
        {

            cout << "Modificar direccion: " << endl;

            datos = cargarCadena ();

            proveedor1.setDireccion(datos);

            if (modificar(proveedor1) == true)
            {

                cout << "Direccion modificada correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar la direccion correctamente. " << endl;
            }

            system ("pause");

            break;

        }

        case 4:  // Modificar CUIT (string)
        {

            cout << "Modificar CUIT: " << endl;

            cin >> datos;

            bool const validado = validarCUIT (datos);

            if (validado == false)
            {

                return;
            }

            proveedor1 = leer (pos);

            proveedor1.setCuit(datos);

            if (modificar(proveedor1) == true)
            {

                cout << "El CUIT fue modificado correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar el CUIT correctamente. " << endl;
            }

            system ("pause");

            break;
        }

        case 5:  // Modificar mail (string)
        {

            cout << "Modificar mail: " << endl;

            cin >> datos;

            proveedor1.setMail (datos);

            if (modificar(proveedor1) == true)
            {

                cout << "Mail modificado correctamente. " << endl;
            }
            else
            {

                cout << "ERROR: No se pudo modificar el mail correctamente. " << endl;
            }

            system ("pause");

            break;
        }

        case 6: // Modificar tipo de proveedor (int)
        {

            cout << "Modificar tipo de proveedor: " << endl;

            cin >> datos2;

            proveedor1.setTipo_proveedor (datos2);

            if (modificar(proveedor1) == true)
            {

                cout << "Tipo de proveedor modificado correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar el tipo de proveedor correctamente. " << endl;
            }

            system ("pause");

            break;
        }

        case 7: // Salir al menu anterior
        {

            cout << "Saliendo al menu anterior..." << endl;

            system ("pause");

            system ("cls");

            return;

            break;
        }

        default:
        {

            cout << "La opcion que ingreso es incorrecta. Intentelo de nuevo. " << endl;

            system ("pause");

            break;
        }
        }
    }
    while (datos2 != 7);
}


bool ProveedorArchivo::hacerBackup ()
{


    // Abro el archivo original ("Proveedores.dat")

    FILE* pArchivoOriginal = fopen(archivo_Proveedor,"rb") ;

    if(pArchivoOriginal == nullptr)
    {

        // Si no existe el archivo original, devuelve error.

        return false ;
    }

    // 2. Abro o creo el archivo de backup

    FILE* pBackup = fopen(archivo_Proveedor_Backup,"wb") ;

    if(pBackup == nullptr)
    {

        // Si no se puede crear el backup, cerrar el original y devolver error.

        fclose(pArchivoOriginal) ;

        return false ;
    }

    // Búfer temporal para copiar datos

    char temporal[1024] ;

    int bytesLeidos ;

    // Copio el contenido: leer un bloque y escribirlo hasta el final del archivo

    while((bytesLeidos = fread(temporal, 1, 1024, pArchivoOriginal)) > 0)
    {

        // Escribir solo los bytes que se leyeron (pueden ser menos de 1024 en la última lectura)

        fwrite(temporal, 1, bytesLeidos, pBackup) ;
    }

    // Cerrar ambos archivos

    fclose(pArchivoOriginal) ;

    fclose(pBackup) ;

    return true ;

}

bool ProveedorArchivo::restaurarBackup ()
{

    FILE* pArchivoBkp = fopen(archivo_Proveedor_Backup, "rb") ;

    if (pArchivoBkp == NULL)
    {

        return false ;
    }

    FILE* pArchivoOriginal = fopen(archivo_Proveedor, "wb") ;

    if (pArchivoOriginal == NULL)
    {

        fclose(pArchivoBkp) ;

        return false ;
    }

    char temporal[1024] ;

    int bytesLeidos ;

    while ((bytesLeidos = fread(temporal, 1, 1024, pArchivoBkp)) > 0)
    {

        fwrite(temporal, 1, bytesLeidos, pArchivoOriginal) ;
    }

    fclose(pArchivoBkp) ;

    fclose(pArchivoOriginal) ;

    return true ;


}
