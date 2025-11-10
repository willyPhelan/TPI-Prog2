#include "ClienteArchivo.h"
#include "Cliente.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include "Utils.h"


using namespace std ;

/// FUNCIONES ABML

bool ClienteArchivo::guardar(const Cliente &reg)
{

    FILE *archivo ;

    archivo = fopen (archivo_Cliente, "ab") ;

    if (archivo == nullptr)
    {

        cout << "NO SE PUDO CREAR EL ARCHIVO. " << endl ;

        return false ;
    }

    int escribio = fwrite (&reg, sizeof (Cliente), 1, archivo) ;

    fclose (archivo) ;

    return escribio ;
}

bool ClienteArchivo::bajaLogica (int id_persona)
{

    int pos = buscarPosicion (id_persona) ;

    if (pos == -1)
    {

        return false ;

    }
    Cliente reg = leer (pos) ;

    reg.setEstado (false) ;

    FILE *archivo ;

    archivo = fopen (archivo_Cliente, "rb+") ;

    if (archivo == nullptr)
    {
        return false ;
    }

    fseek (archivo, pos * sizeof (Cliente), SEEK_SET) ;

    int escrito = fwrite (&reg, sizeof (Cliente), 1, archivo) ;

    fclose (archivo) ;

    return escrito ;

}

bool ClienteArchivo::altaLogica (int id_persona)
{

    int pos = buscarPosicion (id_persona);

    if (pos == -1)
    {

        cout << "El ID que ingreso es incorrecto. " << endl;

        system ("pause");

        return false;
    }
    Cliente reg = leer (pos);

    reg.setEstado (true);

    FILE *archivo;

    archivo = fopen (archivo_Cliente, "rb+");

    if (archivo == nullptr)
    {
        return false;
    }

    fseek (archivo, pos * sizeof (Cliente), SEEK_SET);

    int escrito = fwrite (&reg, sizeof (Cliente), 1, archivo);

    fclose (archivo);

    return escrito;

}

Cliente ClienteArchivo::leer (int pos)
{

    Cliente reg ;

    FILE *archivo ;

    archivo = fopen (archivo_Cliente, "rb") ;

    if (archivo == nullptr)
    {
        return reg ;
    }

    fseek (archivo, pos * sizeof (Cliente), SEEK_SET) ;

    fread (&reg, sizeof (Cliente), 1, archivo) ;

    fclose (archivo) ;

    return reg ;
}

bool ClienteArchivo::modificar (const Cliente &reg)
{

    int pos = buscarPosicion (reg.getID()) ;

    if (pos == -1)
    {

        cout << "El ID ingresado es incorrecto. " << endl ;

        return false ;
    }

    FILE *archivo;

    archivo = fopen (archivo_Cliente, "rb+") ;

    if (archivo == nullptr)
    {
        return false ;
    }

    fseek (archivo, pos * sizeof (Cliente), SEEK_SET) ;

    int escribio = fwrite (&reg, sizeof (Cliente), 1, archivo) ;

    fclose (archivo) ;

    return escribio ;
}
/// FUNCIONES AUXILIARES

int ClienteArchivo::buscarPosicion (int id_persona)
{

    Cliente reg ;

    int cantReg = getCantidadRegistros() ;

    for (int i = 0; i<cantReg; i++)
    {

        reg = leer(i) ;

        if (reg.getID() == id_persona)
        {
            return i ;
        }

    }
    return -1 ;
}


int ClienteArchivo::getCantidadRegistros ()
{

    FILE *archivo ;

    archivo = fopen (archivo_Cliente, "rb") ;

    if (archivo == nullptr)
    {
        return 0 ;
    }

    fseek (archivo, 0, SEEK_END) ;

    int tamanio = ftell (archivo) ;

    fclose (archivo) ;

    return tamanio / sizeof (Cliente) ;

}

bool ClienteArchivo::validarCUIT (string cuit)
{

    Cliente cliente ;

    int const cantReg = getCantidadRegistros() ;

    int opcion;

    for (int i = 0; i < cantReg; i++)
    {

        cliente = leer(i) ;

        while (strcmp(cuit.c_str(), cliente.getCuit().c_str()) == 0 && cliente.getEstado() == true)   // == 0 significa si son iguales los dos strings, no si son iguales a 0
        {


            cout << "El CUIT ya corresponde a un cliente existente. Desea salir o introducir otro CUIT?: (1- Agregar otro CUIT, 2- Salir): " ;

            cin >> opcion ;

            switch (opcion)
            {

            case 1:

                cout << "Ingrese el nuevo CUIT: " ;

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

int ClienteArchivo::verificarID (int idcliente){

    Cliente reg ;

    int cantReg = getCantidadRegistros() ;

    for (int i = 0; i<cantReg; i++)
    {

        reg = leer(i) ;

        if (reg.getID() == idcliente)
        {
            return i ;
        }

    }
    return -1;
}


void ClienteArchivo::modificarCampo ()
{

    Cliente cliente;

    string datos;

    int datos2;

    cout << "Modificar un campo especifico de un cliente " << endl;

    cout << "-------------------------------------------" << endl;

    cout << "Ingrese el ID del cliente a modificar: ";

    cin >> datos2;

    int pos = buscarPosicion (datos2);

    if (pos == -1)
    {
        cout << "ERROR: ID de cliente no encontrado. " << endl;

        system ("pause");

        return;
    }

    cliente = leer (pos);

    do
    {

        system ("cls");

        cout << "Cliente a Modificar (ID: " << cliente.getID() << ")" << endl;

        cout << "-----------------------------" << endl ;

        cliente.mostrar();

        cout << "Seleccione una opcion o el campo a modificar: " << endl;

        cout << "1. Nombre" << endl;

        cout << "2. Apellido" << endl;

        cout << "3. Telefono" << endl;

        cout << "4. Direccion" << endl;

        cout << "5. CUIT" << endl;

        cout << "6. Mail" << endl;

        cout << "7. Tipo de cliente" << endl;

        cout << "8. Finalizar modificaciones y volver al menu anterior" << endl;

        cout << "Opcion: " << endl;

        cin >> datos2;

        cout << endl;

        switch (datos2)
        {

        case 1:   // Modificar nombre (string)
        {

            cout << "Modificar nombre: " << endl;

            cin >> datos;

            cliente.setNombre(datos);

            if (modificar(cliente) == true)
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

        case 2:   // Modificar apellido (string)
        {

            cout << "Modificar apellido: " << endl;

            cin >> datos;

            cliente.setApellido(datos);

            if (modificar(cliente) == true)
            {

                cout << "Apellido modificado correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar el apellido correctamente. " << endl;
            }

            system ("pause");

            break;
        }

        case 3:   // Modificar telefono (string)
        {

            cout << "Modificar telefono: " << endl;

            cin >> datos;

            cliente.setTelefono(datos);

            if (modificar(cliente) == true)
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

        case 4:   // Modificar direccion (string)
        {

            cout << "Modificar direccion: " << endl;

            datos = cargarCadena ();

            cliente.setDireccion (datos);

            if (modificar(cliente) == true)
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

        case 5:   // Modificar CUIT (string)
        {

            cout << "Modificar CUIT: " << endl;

            cin >> datos;

            bool const validado = validarCUIT (datos);

            if (validado == false)
            {

                return;
            }

            cliente = leer (pos);

            cliente.setCuit(datos);

            if (modificar(cliente) == true)
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

        case 6:   // Modificar Mail (string)
        {

            cout << "Modificar mail: " << endl;

            cin >> datos;

            cliente.setMail (datos);

            if (modificar(cliente) == true)
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

        case 7:   // Modificar tipo de cliente (int)
        {

            cout << "Modificar tipo de cliente: " << endl;

            cin >> datos2;

            cliente.setTipo_Cliente(datos2);

            if (modificar(cliente) == true)
            {

                cout << "Tipo de cliente modificado correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar el tipo de cliente correctamente. " << endl;
            }

            system ("pause");

            break;
        }

        case 8:   // Finalizar
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
    while (datos2 != 8);
}
