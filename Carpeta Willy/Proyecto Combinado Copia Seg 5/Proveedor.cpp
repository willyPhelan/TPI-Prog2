#include "Proveedor.h"
#include "ProveedorArchivo.h"
#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std ;


Proveedor::Proveedor() : tipo_proveedor(0)
{
}

Proveedor::Proveedor(int tipo_proveedor)
{

    setTipo_proveedor(tipo_proveedor) ;
}


int Proveedor::getTipo_proveedor()
{

    return tipo_proveedor ;
}


string Proveedor::getMail() const
{

    return mail ;
}


void Proveedor::setTipo_proveedor(int tipo_proveedor)
{

    this->tipo_proveedor = tipo_proveedor ;
}

void Proveedor::setMail(std::string mail)
{


    strncpy(this->mail, mail.c_str(), 29) ;

    this->mail[29] = '\0' ;
}


void Proveedor::cargar()
{

    string datos ;

    ProveedorArchivo archivo;

    int tipo_proveedor ;

    cout << "El proveedor sera guardado con el siguiente ID: " << getID () << endl;

    cout << "Ingrese el CUIT del proveedor: "  ;

    cin >> datos ;

    if (archivo.validarCUIT (datos) == false)
    {

        return;

    }

    setCuit(datos) ;

    cout << "Ingrese el tipo de proveedor (1-Particular, 2-Empresa):  " ;

    cin >> tipo_proveedor ;

    while (tipo_proveedor != 1 && tipo_proveedor != 2)
    {

        cout << "El tipo de proveedor que ingreso es incorrecto. Intentelo de nuevo. " << endl;

        cout << "Ingrese el tipo de proveedor (1-Particular, 2-Empresarial):  " ;

        cin >> tipo_proveedor ;

    }

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

}

void Proveedor::mostrar()
{

    cout << "Informacion del proveedor: " << endl ;

    cout << endl ;

    cout << "ID del proveedor: " << getID() << endl ;

    cout << "CUIT del proveedor: " << getCuit() << endl ;

    cout << "Nombre del proveedor: " << getNombre() << endl ;

    cout << "Telefono del proveedor: " << getTelefono() << endl ;

    cout << "Direccion del proveedor: " << getDireccion() << endl ;

    cout << "Mail del proveedor: " << getMail() << endl ;

    if (getTipo_proveedor () == 1)
    {

        cout << "Tipo de proveedor: Particular (1)" << endl ;

    }
    else
    {

        cout << "Tipo de proveedor: Empresarial (2)" << endl;

    }

    if(getEstado())
    {

        cout << "Estado del proveedor: Activo" << endl ;

    }
    else
    {

        cout << "Estado del proveedor: Dado de baja" << endl ;

    }

    cout << endl;
}
