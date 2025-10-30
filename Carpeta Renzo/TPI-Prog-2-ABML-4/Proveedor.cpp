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

    int datos2 ;

    Proveedor proveedor1;

    ProveedorArchivo archivo;

    int const cantReg = archivo.getCantidadRegistros();

    cout << "Ingrese el CUIT del proveedor: " << endl ;

    cin >> datos ;

    for (int i = 0; i<cantReg; i++)
    {
        proveedor1 = archivo.leer(i);

        while (strcmp(datos.c_str(), proveedor1.getCuit().c_str()) == 0 && proveedor1.getEstado() == true)
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

    Proveedor::setCuit(datos) ;

    cout << "Ingrese el tipo de proveedor: " ;

    cin >> datos2 ;

    Proveedor::setTipo_proveedor(datos2) ;

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
