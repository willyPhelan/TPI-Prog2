#include "Cliente.h"
#include "ClienteArchivo.h"
#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std ;

// Constructores

Cliente::Cliente() : tipo_Cliente(0)   // constructor por defecto
{

    // Inicializo el array de caracteres 'mail'
    // La clase base Persona se inicializa con sus valores por defecto.

    strncpy(this->mail, "", 29) ;
}

Cliente::Cliente(string mail, int tipo_Cliente)
{

    setMail(mail) ;

    setTipo_Cliente(tipo_Cliente) ;
}

// Getters

string Cliente::getMail()
{

    return string (mail) ;

}

int Cliente::getTipo_Cliente ()
{

    return tipo_Cliente ;

}

// Setters

void Cliente::setMail(string mail)
{

    strncpy(this->mail, mail.c_str(), 29) ;
}

void Cliente::setTipo_Cliente (int tipo_Cliente)
{

    this->tipo_Cliente = tipo_Cliente ;
}

// Metodos

void Cliente::cargar()
{

    Cliente cliente ;

    ClienteArchivo reg ;

    string datos ;

    int datos2 ; // para validacion

    int tipo_Cliente ;

    Cliente::setID(reg.getCantidadRegistros() +1 )  ;

    int const cantReg = reg.getCantidadRegistros();

    cout << "ID del cliente: " << Cliente::getID() << endl ;

    cout << "Ingrese el CUIT del cliente: " ;

    cin >> datos ;

    for (int i = 0; i < cantReg; i++)
    {

        cliente = reg.leer(i) ;

        while (strcmp(datos.c_str(), cliente.getCuit().c_str()) == 0 && cliente.getEstado() == true)   // == 0 significa si son iguales los dos strings, no si son iguales a 0
        {


            cout << "El CUIT ya corresponde a un cliente existente. Desea salir o introducir otro CUIT?: (1- Agregar otro CUIT, 2- Salir): " ;

            cin >> datos2 ;

            switch (datos2)
            {

            case 1:

                cout << "Ingrese el nuevo CUIT: " ;

                cin >> datos ;

                break ;

            case 2:

                cout << endl << "Saliendo..." << endl ;

                return ;

                break ;

            default:

                cout << "La opcion que eligio es invalida. Intentelo de nuevo. " << endl ;

                break ;
            }

        }
    }

    Cliente::setCuit(datos) ;

    cout << "Ingrese el tipo de cliente: " ;

    cin >> tipo_Cliente ;

    Cliente::setTipo_Cliente(tipo_Cliente) ;

    cout << "Ingrese el nombre del cliente: " ;

    cin >> datos ;

    Cliente::setNombre(datos) ;

    cout << "Ingrese el apellido del cliente: " ;

    cin >> datos ;

    Cliente::setApellido(datos) ;

    cout << "Ingrese el telefono del cliente: " ;

    cin >> datos ;

    Cliente::setTelefono(datos) ;

    cout << "Ingrese la direccion del cliente: " ;

    datos = cargarCadena() ;

    Cliente::setDireccion(datos) ;

    cout << "Ingrese el mail del cliente: "  ;

    cin >> datos ;

    Cliente::setMail(datos) ;

    Cliente::setEstado(true) ;

    cout << endl ;

    cout << endl << "El cliente fue agregado con exito. " << endl ;


}

void Cliente::mostrar()
{

    cout << endl << "Informacion del cliente: " << endl ;

    cout << "ID del cliente: " << Cliente::getID() << endl ;

    cout << "Nombre y apellido del cliente: " << Cliente::getNombre() << " " << Cliente::getApellido() << endl ;

    cout << "Telefono del cliente: " << Cliente::getTelefono() << endl ;

    cout << "Direccion del cliente: " << Cliente::getDireccion() << endl ;

    cout << "Cuit del cliente: " << Cliente::getCuit() << endl ;

    cout << "Mail del cliente: " << Cliente::getMail() << endl ;

    cout << "Tipo de cliente: " << Cliente::getTipo_Cliente() << endl ;

    if(Cliente::getEstado())
    {

        cout << "Estado: Activo"  << endl ;
    }
    else
    {
        cout << "Estado: Dado de baja" << endl ;
    }

    cout << endl ;

}

void Cliente::modificarCampo ()
{
    ClienteArchivo archivo;

    string datos;

    int datos2;

    cout << "Modificar un campo especifico de un cliente " << endl;

    cout << "-------------------------------------------" << endl;

    cout << "Ingrese el ID del cliente a modificar: ";

    cin >> datos2;

    int pos = archivo.buscarPosicion (datos2);

    if (pos == -1)
    {
        cout << "ERROR: ID de cliente no encontrado. " << endl;

        system ("pause");

        return;
    }

    *this = archivo.leer (pos);

    do
    {

        system ("cls");

        cout << "Cliente a Modificar (ID: " << this->getID() << ")" << endl;

        cout << "-----------------------------" << endl ;

        this->mostrar();

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

            this->setNombre(datos);

            if (archivo.modificar(*this) == true)
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

            this->setApellido(datos);

            if (archivo.modificar(*this) == true)
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

            this->setTelefono(datos);

            if (archivo.modificar(*this) == true)
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

            this->setDireccion (datos);

            if (archivo.modificar(*this) == true)
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

            int const cantReg = archivo.getCantidadRegistros();

            for (int i = 0; i<cantReg; i++)
            {

                *this = archivo.leer(i);

                while (strcmp(datos.c_str(), this->getCuit().c_str()) == 0 && this->getEstado() == true)   // == 0 significa si son iguales los dos strings, no si son iguales a 0
                {

                    cout << "El CUIT ya corresponde a un cliente existente. Desea salir o introducir otro CUIT?: (1- Agregar otro CUIT, 2- Salir): " ;

                    cin >> datos2 ;

                    switch (datos2)
                    {

                    case 1:

                        cout << "Ingrese el nuevo CUIT: " ;

                        cin >> datos ;

                        break ;

                    case 2:

                        cout << endl << "Saliendo..." << endl ;

                        return ;

                        break ;

                    default:

                        cout << "La opcion que eligio es invalida. Intentelo de nuevo. " << endl ;

                        break ;
                    }

                }
            }

            *this = archivo.leer (pos);

            this->setCuit(datos);

            if (archivo.modificar(*this) == true)
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

            this->setMail (datos);

            if (archivo.modificar(*this) == true)
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

            this->setTipo_Cliente(datos2);

            if (archivo.modificar(*this) == true)
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
