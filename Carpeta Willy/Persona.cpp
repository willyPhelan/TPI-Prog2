#include "Persona.h"
#include <iostream>
#include <cstring> // para strncpy
#include "Utils.h" // para funciones auxiliares


using namespace std ;


// 1. CONSTRUCTOR

// Constructor con lista de inicialización para parametros por defecto

Persona::Persona(int id, const std::string &nombre, const std::string &apellido, const std::string &telefono, const std::string &direccion, const std::string &cuit, bool estado)
 : idPersona(id), nombre{}, apellido{}, telefono{}, direccion{}, cuit{}, estado(estado)      // Inicializa el estado y los arrays de char a cero para seguridad
{
    // setters para asignar las cadenas, lo que asegura el uso de strncpy
    // setID y setEstado ya se hicieron en la lista de inicialización

    setNombre(nombre) ;

    setApellido(apellido) ;

    setTelefono(telefono) ;

    setDireccion(direccion) ;

    setCuit(cuit) ;

}


//GETTERS


int Persona::getID() const {

    return idPersona ;
}

std::string Persona::getNombre() const {

    return std::string(nombre) ; // Convierte char[] a std::string para el retorno
}

std::string Persona::getApellido() const {

    return std::string(apellido) ;
}

std::string Persona::getTelefono() const {

    return std::string(telefono) ;
}

std::string Persona::getDireccion() const {

    return std::string(direccion) ;
}

std::string Persona::getCuit() const {

    return std::string(cuit) ;
}

bool Persona::getEstado() const {

    return estado ;
}


// SETTERS


void Persona::setID(int id) {

    idPersona = id ;
}

//strncpy para copiar std::string (c_str()) al char[]
// El tamaño máximo tinee que ser N-1 para dejar espacio al carácter terminador '\0'

void Persona::setNombre(const std::string &nombre) {

    strncpy(this->nombre, nombre.c_str(), 29) ; // 30 (tamaño) - 1 = 29
}

void Persona::setApellido(const std::string &apellido) {

    strncpy(this->apellido, apellido.c_str(), 29) ;
}

void Persona::setTelefono(const std::string &telefono) {

    strncpy(this->telefono, telefono.c_str(), 19) ;
}

void Persona::setDireccion(const std::string &direccion) {

    strncpy(this->direccion, direccion.c_str(), 49) ;
}

void Persona::setCuit(const std::string &cuit) {

    strncpy(this->cuit, cuit.c_str(), 12) ;
}

void Persona::setEstado(bool estado) {

    this->estado = estado ;
}


// METODO CARGAR

void Persona::cargar() {

    int id ;
    string str ;


    //ID

    cout << "CARGA DE PERSONA " << endl ;

    cout << "-------------------------------------" << endl ;

    cout << "ACA TIENE QUE IR ID AUTOINCREMENTAL: " << endl ; // tiene que se autoincremental!!!

    system("pause") ;

    setID(id) ;

    cout << endl ;

    // Nombre

    cout << "Ingrese su nombre: " ;

    str = cargarCadena() ; // Usa tu función para leer strings con espacios

    setNombre(str) ;

    // Apellido

    cout << "Apellido: " ;

    str = cargarCadena() ;

    setApellido(str) ;

    // Teléfono

    cout << "Telefono: " ;

    str = cargarCadena() ;

    setTelefono(str) ;

    //Dirección

    cout << "Direccion: " ;

    str = cargarCadena() ;

    setDireccion(str) ;

    //CUIT

    cout << "CUIT: " ;

    str = cargarCadena() ;

    setCuit(str) ;





    cout << "Registro creado con exito. " ;

    cout << endl << endl ;
}


//MÉTODO MOSTRAR


void Persona::mostrar() const {

    cout << "ID: " << getID() << endl ;

    cout << "Nombre y Apellido: " << getNombre() << " " << getApellido() << endl ;

    cout << "CUIT: " << getCuit() << endl ;

    cout << "Telefono: " << getTelefono() << endl ;

    cout << "Direccion: " << getDireccion() << endl ;

    cout << "Estado (Activo): " << (getEstado() ? "Si" : "No") << endl << endl ; // muestro el estado mediante un ternario
}
