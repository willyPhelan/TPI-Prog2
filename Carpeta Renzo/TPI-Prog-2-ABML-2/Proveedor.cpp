#include "Proveedor.h"
#include <iostream>
#include <cstring>
#include "Utils.h"
#include "Proveedor.h"
#include "ProveedorArchivo.h"

using namespace std ;

// Constructor


Proveedor::Proveedor() : tipo_proveedor(0) {
}

Proveedor::Proveedor(int tipo_proveedor) {

    setTipo_proveedor(tipo_proveedor) ;
}

// Getters

int Proveedor::getTipo_proveedor() {

    return tipo_proveedor ;
}

// Setters

void Proveedor::setTipo_proveedor(int tipo_proveedor) {

    this->tipo_proveedor = tipo_proveedor ;
}

// Metodos

void Proveedor::cargar() {

    string datos ;

    int tipo_proveedor ;

    ProveedorArchivo archivo;

    cout << "Ingrese el CUIT del proveedor: " << endl ;

    cin >> datos ;

    Proveedor::setCuit(datos) ;

    cout << "Ingrese el tipo de proveedor: " ;

    cin >> tipo_proveedor ;

    Proveedor::setTipo_proveedor(tipo_proveedor) ;

    cout << "Ingrese el nombre del proveedor: " << endl;
    datos = cargarCadena();
    Proveedor::setNombre(datos);

    cout << "Ingrese el numero de telefono del proveedor: " << endl;
    cin >> datos;
    Proveedor::setTelefono(datos);

    cout << "Ingrese la direccion del proveedor: " << endl;
    datos = cargarCadena();
    Proveedor::setDireccion(datos);

    Proveedor::setEstado(true);

    Proveedor::setID(archivo.getCantidadRegistros()+1);

    cout << endl << "El proveedor fue agregado con exito. " << endl ;

    system("pause") ;

    system("cls") ;

}

void Proveedor::mostrar(){

    cout << "Informacion del proveedor: " << endl ;

    cout << endl ;

    cout << "ID del proveedor: " << Proveedor::getID() << endl;

    cout << "Nombre del proveedor: " << Proveedor::getNombre() << endl ;

    cout << "Telefono del proveedor: " << Proveedor::getTelefono() << endl ;

    cout << "Direccion del proveedor: " << Proveedor::getDireccion() << endl ;

    cout << "CUIT del proveedor: " << Proveedor::getCuit() << endl ;

    cout << "Tipo de proveedor: " << Proveedor::getTipo_proveedor() << endl ;

        if (Proveedor::getEstado())
    {
        cout << "Estado: Activo " << endl;
    }else{

        cout << "Estado: Inactivo " << endl;
    }

    cout << endl;

 //   system ("pause") ;

 //   system ("cls") ;
}
