#include "Empleado.h"
#include "EmpleadoArchivo.h"
#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std ;

Empleado::Empleado() : ID_Puesto(0), horas_Trabajo(0) {}

Empleado::Empleado(int ID_Puesto, int horas_Trabajo){

    setID_Puesto (ID_Puesto) ;

    setHoras_Trabajo (horas_Trabajo) ;
}

int Empleado::getID_Puesto(){ return ID_Puesto ; }

int Empleado::getHoras_Trabajo(){ return horas_Trabajo ; }

void Empleado::setID_Puesto(int ID_Puesto){

    this->ID_Puesto = ID_Puesto ;
}

void Empleado::setHoras_Trabajo(int horas_Trabajo){

    this->horas_Trabajo = horas_Trabajo ;
}

void Empleado::cargar(){

    EmpleadoArchivo reg ;

    string datos ;

    int datos2 ;

    cout << "El empleado sera guardado con el siguiente ID: " << getID () << endl;

    cout << "Ingrese el CUIT del empleado: " ;

    cin >> datos ;

    if (reg.validarCUIT(datos) == false){ return ; }

    setCuit(datos) ;

    cout << "Ingrese el tipo de empleado (1- Empleado en el local, 2- Empleado repartidor): " ;

    cin >> datos2 ;

    while (datos2 != 1 && datos2 != 2){

        cout << "El tipo de empleado que ingreso es incorrecto. Intentelo de nuevo. " << endl ;

        cout << "Ingrese el tipo de empleado (1- Empleado en el local, 2- Empleado repartidor): " ;

        cin >> datos2 ; }

    setID_Puesto(datos2) ;

    cout << "Ingrese la cantidad de horas trabajadas por semana del empleado: " ;

    cin >> datos2 ;

    setHoras_Trabajo(datos2) ;

    cout << "Ingrese el nombre del empleado: "  ;

    cin >> datos ;

    setNombre(datos) ;

    cout << "Ingrese el apellido del empleado: " ;

    cin >> datos ;

    setApellido(datos) ;

    cout << "Ingrese el telefono del empleado: " ;

    cin >> datos ;

    setTelefono(datos) ;

    cout << "Ingrese la direccion del empleado: "  ;

    datos = cargarCadena() ;

    setDireccion(datos) ;

    setEstado(true) ;

}

void Empleado::mostrar(){

    cout << "Informacion del empleado: " << endl ;

    cout << endl ;

    cout << "ID del empleado: " << getID() << endl ;

    cout << "CUIT del empleado: " << getCuit() << endl ;

    cout << "Nombre y apellido del empleado: " << getNombre() << " " << getApellido() << endl ;

    cout << "Telefono del empleado: " << getTelefono() << endl ;

    cout << "Direccion del empleado: " << getDireccion() << endl ;

    cout << "Horas trabajadas por semana del empleado: " << getHoras_Trabajo() << endl ;

    if (getID_Puesto () == 1){

        cout << "Tipo de empleado: Local (1)" << endl ; } else {

        cout << "Tipo de empleado: Repartidor (2)" << endl ; }

    if (getEstado () == true){

        cout << "Estado del empleado: Activo" << endl ; } else {

        cout << "Estado del empleado: Dado de baja" << endl;

    }

    cout << endl ;
}
