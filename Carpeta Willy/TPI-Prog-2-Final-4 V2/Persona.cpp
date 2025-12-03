#include "Persona.h"
#include <iostream>
#include <cstring>
#include "Utils.h"


using namespace std ;


Persona::Persona(int id, const std::string &nombre, const std::string &apellido, const std::string &telefono, const std::string &direccion, const std::string &cuit, bool estado)

: idPersona(id), nombre{}, apellido{}, telefono{}, direccion{}, cuit{}, estado(estado){

    setNombre(nombre) ;

    setApellido(apellido) ;

    setTelefono(telefono) ;

    setDireccion(direccion) ;

    setCuit(cuit) ;

}

int Persona::getID() const { return idPersona ; }


std::string Persona::getNombre() const {

    return std::string(nombre) ;
}

std::string Persona::getApellido() const {

    return std::string(apellido) ;
}

std::string Persona::getTelefono() const {

    return std::string(telefono) ;
}

std::string Persona::getDireccion() const {

    return std::string(direccion) ; }

std::string Persona::getCuit() const {

    return std::string(cuit) ; }

bool Persona::getEstado() const {

    return estado ; }


void Persona::setID(int id){

    idPersona = id ;
}


void Persona::setNombre(const std::string &nombre){

    strncpy(this->nombre, nombre.c_str(), 29) ; }


void Persona::setApellido(const std::string &apellido){

    strncpy(this->apellido, apellido.c_str(), 29) ;
}

void Persona::setTelefono(const std::string &telefono){

    strncpy(this->telefono, telefono.c_str(), 19) ;
}

void Persona::setDireccion(const std::string &direccion){

    strncpy(this->direccion, direccion.c_str(), 49) ;
}

void Persona::setCuit(const std::string &cuit){

    strncpy(this->cuit, cuit.c_str(), 12) ;
}

void Persona::setEstado(bool estado){

    this->estado = estado ;
}

void Persona::mostrar() const {

    cout << "ID: " << getID() << endl ;

    cout << "Nombre y Apellido: " << getNombre() << " " << getApellido() << endl ;

    cout << "CUIT: " << getCuit() << endl ;

    cout << "Telefono: " << getTelefono() << endl ;

    cout << "Direccion: " << getDireccion() << endl ;

    cout << "Estado (Activo): " << (getEstado() ? "Si" : "No") << endl << endl ; // muestro el estado mediante un ternario
}
