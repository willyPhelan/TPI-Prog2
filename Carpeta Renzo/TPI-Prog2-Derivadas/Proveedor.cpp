#include "Proveedor.h"
#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std;

// Constructor

Proveedor::Proveedor(int Tipo_proveedor)
{
    setTipo_proveedor(Tipo_proveedor);
}

// Getters

int Proveedor::getTipo_proveedor()
{
    return Tipo_proveedor;
}

// Setters

void Proveedor::setTipo_proveedor(int Tipo_proveedor)
{
    this->Tipo_proveedor=Tipo_proveedor;
}

// Metodos

void Proveedor::Cargar()
{
    string datos;
    int Tipo_proveedor;

    cout << "Ingrese el CUIT del proveedor: " << endl;
    cin >> datos;
    Proveedor::setCuit(datos);

    cout << "Ingrese el tipo de proveedor: " << endl;
    cin >> Tipo_proveedor;
    Proveedor::setTipo_proveedor(Tipo_proveedor);

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

    cout << "El proveedor fue agregado con exito. " << endl;

    system("pause");
    system("cls");

}

void Proveedor::Mostrar()
{
    cout << "Informacion del proveedor: " << endl;

    cout << endl;

    cout << "Nombre del proveedor: " << Proveedor::getNombre() << endl;
    cout << "Telefono del proveedor: " << Proveedor::getTelefono() << endl;
    cout << "Direccion del proveedor: " << Proveedor::getDireccion() << endl;
    cout << "CUIT del proveedor: " << Proveedor::getCuit() << endl;
    cout << "Tipo de proveedor: " << Proveedor::getTipo_proveedor() << endl;
    cout << "Estado del proveedor: " << Proveedor::getEstado() << endl;

    cout << endl;

    system ("pause");
    system ("cls");
}
