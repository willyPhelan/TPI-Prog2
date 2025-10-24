#include "Cliente.h"
#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std;

// Constructor

Cliente::Cliente(string Mail, int Tipo_Cliente)
{
    setMail(Mail);
    setTipo_Cliente(Tipo_Cliente);
}
// Getters

string Cliente::getMail(){return string (Mail);}
int Cliente::getTipo_Cliente (){
return Tipo_Cliente;}

// Setters

void Cliente::setMail(string Mail)
{
    strncpy(this->Mail,Mail.c_str(),29);
}
void Cliente::setTipo_Cliente (int Tipo_Cliente)
{
    this->Tipo_Cliente=Tipo_Cliente;
}

// Metodos
void Cliente::Cargar()
{
    string datos;
    int tipo_Cliente;

    cout << "Ingrese el CUIT del cliente: " << endl;
    cin >> datos;
    Cliente::setCuit(datos);

    cout << "Ingrese el tipo de cliente: " << endl;
    cin >> tipo_Cliente;
    Cliente::setTipo_Cliente(tipo_Cliente);

    cout << "Ingrese el nombre del cliente: " << endl;
    cin >> datos;
    Cliente::setNombre(datos);

    cout << "Ingrese el apellido del cliente: " << endl;
    cin >> datos;
    Cliente::setApellido(datos);

    cout << "Ingrese el telefono del cliente: " << endl;
    cin >> datos;
    Cliente::setTelefono(datos);

    cout << "Ingrese la direccion del cliente: " << endl;
    datos = cargarCadena();
    Cliente::setDireccion(datos);

    cout << "Ingrese el mail del cliente: " << endl;
    cin >> datos;
    Cliente::setMail(datos);

    Cliente::setEstado(true);

    cout << "El cliente fue agregado con exito. " << endl;

    system("pause");
    system("cls");
}

void Cliente::Mostrar()
{
    cout << "Informacion del cliente: " << endl;

    cout << endl;

    cout << "Nombre y apellido del cliente: " << Cliente::getNombre() << " " << Cliente::getApellido() << endl;
    cout << "Telefono del cliente: " << Cliente::getTelefono() << endl;
    cout << "Direccion del cliente: " << Cliente::getDireccion() << endl;
    cout << "Cuit del cliente: " << Cliente::getCuit() << endl;
    cout << "Mail del cliente: " << Cliente::getMail() << endl;
    cout << "Tipo de cliente: " << Cliente::getTipo_Cliente() << endl;
    cout << "Estado: " << Cliente::getEstado() << endl;

    cout << endl;

    system ("pause");
    system ("cls");
}

