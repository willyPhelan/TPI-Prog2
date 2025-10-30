#include "Cliente.h"
#include <iostream>
#include <cstring>
#include "Utils.h"
#include "ClienteArchivo.h"

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

    string datos ;
    int datos2 ;

    Cliente cliente;

    ClienteArchivo reg;

    int const cantReg = reg.getCantidadRegistros();

    cout << "Ingrese el CUIT del cliente: " << endl ;

    cin >> datos ;

    for (int i = 0; i<cantReg; i++)
    {
        cliente = reg.leer(i);

        while (strcmp(datos.c_str(), cliente.getCuit().c_str()) == 0 && cliente.getEstado() == true) // == 0 significa si son iguales los dos strings, no si son iguales a 0
        {


            cout << "El CUIT que usted ingreso ya fue asignado. Desea salir o introducir otro CUIT?: 1: (Agregar otro CUIT), 2: (Salir)" << endl;

            cin >> datos2;

            switch (datos2)
            {
            case 1:
                cout << "Ingrese el nuevo CUIT: " << endl;

                cin >> datos;

                break;

            case 2:

                cout << "Saliendo..." << endl;

                system ("pause");

                system ("cls");

                return;

                break;

            default:

                cout << "La opcion que eligio es invalida. Intentelo de nuevo. " << endl;

                break;
            }

        }
    }
    Cliente::setCuit(datos) ;

    cout << "Ingrese el tipo de cliente: " ;

    cin >> datos2 ;

    Cliente::setTipo_Cliente(datos2) ;



    cout << "Ingrese el nombre del cliente: " << endl ;

    cin >> datos ;

    Cliente::setNombre(datos) ;

    cout << "Ingrese el apellido del cliente: " << endl ;

    cin >> datos ;

    Cliente::setApellido(datos) ;

    cout << "Ingrese el telefono del cliente: " << endl ;

    cin >> datos ;

    Cliente::setTelefono(datos) ;

    cout << "Ingrese la direccion del cliente: " << endl ;

    datos = cargarCadena() ;

    Cliente::setDireccion(datos) ;

    cout << "Ingrese el mail del cliente: "  ;

    cin >> datos ;

    Cliente::setMail(datos) ;

    Cliente::setEstado(true) ;

    Cliente::setID(reg.getCantidadRegistros()+1);

    cout << endl ;

    cout << "El cliente fue agregado exitosamente. Se le asigno el ID: " << getID() << endl;

    system ("pause");

    system("cls") ;
}

void Cliente::mostrar()
{

    cout << "Informacion del cliente: " << endl ;

    cout << endl ;

    cout << "ID del cliente: " << Cliente::getID() << endl;

    cout << "Nombre y apellido del cliente: " << Cliente::getNombre() << " " << Cliente::getApellido() << endl ;

    cout << "Telefono del cliente: " << Cliente::getTelefono() << endl ;

    cout << "Direccion del cliente: " << Cliente::getDireccion() << endl ;

    cout << "Cuit del cliente: " << Cliente::getCuit() << endl ;

    cout << "Mail del cliente: " << Cliente::getMail() << endl ;

    cout << "Tipo de cliente: " << Cliente::getTipo_Cliente() << endl ;

    if (Cliente::getEstado())
    {
        cout << "Estado: Activo " << endl;
    }
    else
    {

        cout << "Estado: Inactivo " << endl;
    }

    cout << endl ;

//   system ("pause") ;

    //  system ("cls") ;
}

