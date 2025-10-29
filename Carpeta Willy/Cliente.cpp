#include "Cliente.h"
#include "ClienteArchivo.h"
#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std ;

// Constructores

Cliente::Cliente() : tipo_Cliente(0) { // constructor por defecto

    // Inicializo el array de caracteres 'mail'
    // La clase base Persona se inicializa con sus valores por defecto.

    strncpy(this->mail, "", 29) ;
}

Cliente::Cliente(string mail, int tipo_Cliente){

    setMail(mail) ;

    setTipo_Cliente(tipo_Cliente) ;
}

// Getters

string Cliente::getMail(){

    return string (mail) ;

}

int Cliente::getTipo_Cliente (){

    return tipo_Cliente ;

}

// Setters

void Cliente::setMail(string mail) {

    strncpy(this->mail, mail.c_str(), 29) ;
}

void Cliente::setTipo_Cliente (int tipo_Cliente){

    this->tipo_Cliente = tipo_Cliente ;
}

// Metodos

void Cliente::cargar(){

    ClienteArchivo reg ;

    string datos ;

    int tipo_Cliente ;

    Cliente::setID(reg.getCantidadRegistros() +1 )  ;

    cout << "ID del cliente: " << Cliente::getID() << endl ;

    cout << "Ingrese el CUIT del cliente: " ;

    cin >> datos ;

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


}

void Cliente::mostrar(){

    cout << endl << "Informacion del cliente: " << endl ;

    cout << "ID del cliente: " << Cliente::getID() << endl ;

    cout << "Nombre y apellido del cliente: " << Cliente::getNombre() << " " << Cliente::getApellido() << endl ;

    cout << "Telefono del cliente: " << Cliente::getTelefono() << endl ;

    cout << "Direccion del cliente: " << Cliente::getDireccion() << endl ;

    cout << "Cuit del cliente: " << Cliente::getCuit() << endl ;

    cout << "Mail del cliente: " << Cliente::getMail() << endl ;

    cout << "Tipo de cliente: " << Cliente::getTipo_Cliente() << endl ;

    if(Cliente::getEstado()) {

    cout << "Estado: Activo"  << endl ; } else { cout << "Estado: Dado de baja" << endl ; }

    cout << endl ;

}

