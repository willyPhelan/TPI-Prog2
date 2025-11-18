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

    ClienteArchivo reg;

    string datos ;

    int tipo_Cliente ;

//  int const cantReg = reg.getCantidadRegistros();

    cout << "El cliente sera guardado con el siguiente ID: " << getID() << endl ;

    cout << "Ingrese el CUIT del cliente: " ;

    cin >> datos ;

//  bool const validado = reg.validarCUIT (datos) ;

    if (reg.validarCUIT(datos) == false)
    {

        return;

    }

    setCuit(datos) ;

    cout << "Ingrese el tipo de cliente (1- Particular, 2- Empresarial): " ;

    cin >> tipo_Cliente ;

    while (tipo_Cliente != 1 && tipo_Cliente != 2)
    {

        cout << "El tipo de cliente que ingreso es invalido. Intentelo de nuevo. " << endl;

        cout << "Ingrese el tipo de cliente (1- Particular, 2- Empresarial): " ;

        cin >> tipo_Cliente ;

    }

    setTipo_Cliente(tipo_Cliente) ;

    cout << "Ingrese el nombre del cliente: " ;

    cin >> datos ;

    setNombre(datos) ;

    cout << "Ingrese el apellido del cliente: " ;

    cin >> datos ;

    setApellido(datos) ;

    cout << "Ingrese el telefono del cliente: " ;

    cin >> datos ;

    setTelefono(datos) ;

    cout << "Ingrese la direccion del cliente: " ;

    datos = cargarCadena() ;

    setDireccion(datos) ;

    cout << "Ingrese el mail del cliente: "  ;

    cin >> datos ;

    setMail(datos) ;

    setEstado(true) ;

}

void Cliente::mostrar()
{

    cout << "Informacion del cliente: " << endl ;

    cout << endl;

    cout << "ID del cliente: " << getID() << endl ;

    cout << "CUIT del cliente: " << getCuit() << endl ;

    cout << "Nombre y apellido del cliente: " << getNombre() << " " << getApellido() << endl ;

    cout << "Telefono del cliente: " << getTelefono() << endl ;

    cout << "Direccion del cliente: " << getDireccion() << endl ;

    cout << "Mail del cliente: " << getMail() << endl ;

    if (getTipo_Cliente () == 1)
    {

        cout << "Tipo de cliente: Particular (1)" << endl;

    }
    else
    {

        cout << "Tipo de cliente: Empresarial (2)" << endl;

    }

    if(getEstado() == true)
    {

        cout << "Estado del cliente: Activo"  << endl ;

    }
    else
    {

        cout << "Estado del cliente: Dado de baja" << endl ;

    }

    cout << endl ;

}

