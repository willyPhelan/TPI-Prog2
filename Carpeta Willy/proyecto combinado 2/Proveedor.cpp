#include "Proveedor.h"
#include "ProveedorArchivo.h"
#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std ;

// Constructor


Proveedor::Proveedor() : tipo_proveedor(0)
{
}

Proveedor::Proveedor(int tipo_proveedor)
{

    setTipo_proveedor(tipo_proveedor) ;
}

// Getters

int Proveedor::getTipo_proveedor()
{

    return tipo_proveedor ;
}


string Proveedor::getMail() const
{

    return mail ;
}

// Setters

void Proveedor::setTipo_proveedor(int tipo_proveedor)
{

    this->tipo_proveedor = tipo_proveedor ;
}

void Proveedor::setMail(std::string mail)
{

    // strncpy para copiar la cadena al array char[30] de forma segura

    strncpy(this->mail, mail.c_str(), 29) ;

    this->mail[29] = '\0' ;
}

// Metodos

void Proveedor::cargar()
{

    string datos ;

    ProveedorArchivo archivo;

    int tipo_proveedor ;

//  int const cantReg = archivo.getCantidadRegistros() ;

    setID (archivo.getCantidadRegistros () + 1);

    cout << "ID del proveedor: " << getID () << endl;

    cout << "Ingrese el CUIT del proveedor: "  ;

    cin >> datos ;

//  bool const validado = archivo.validarCUIT (datos);

    if (archivo.validarCUIT (datos) == false)
    {

        return;
    }

    setCuit(datos) ;

    cout << "Ingrese el tipo de proveedor (1-Empresa, 2-Particular, 3-Servicios):  " ;

    cin >> tipo_proveedor ;

    setTipo_proveedor(tipo_proveedor) ;

    cout << "Ingrese el nombre del proveedor: " ;

    datos = cargarCadena() ;

    setNombre(datos) ;

    cout << "Ingrese el numero de telefono del proveedor: " ;

    cin >> datos ;

    setTelefono(datos) ;

    cout << "Ingrese la direccion del proveedor: "  ;

    datos = cargarCadena() ;

    setDireccion(datos) ;

    cout << "Ingrese el mail del proveedor: "  ;

    datos = cargarCadena() ;

    setMail(datos) ;

    setEstado(true) ;

    cout << endl << "El proveedor fue agregado con exito. " << endl ;

}

void Proveedor::mostrar()
{

    cout << "Informacion del proveedor: " << endl ;

    cout << endl ;

    cout << "ID del proveedor: " << getID() << endl ;

    cout << "CUIT del proveedor: " << getCuit() << endl ;

    cout << "Tipo de proveedor: " << getTipo_proveedor() << endl ;

    cout << "Nombre del proveedor: " << getNombre() << endl ;

    cout << "Telefono del proveedor: " << getTelefono() << endl ;

    cout << "Direccion del proveedor: " << getDireccion() << endl ;

    cout << "Mail del proveedor: " << getMail() << endl ;

    if(getEstado())
    {

        cout << "Estado del proveedor: Activo " << endl ;
    }
    else
    {
        cout << "Estado del proveedor: Inactivo " << endl ;
    }

    cout << endl;
}
