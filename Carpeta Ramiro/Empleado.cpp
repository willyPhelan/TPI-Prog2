#include "Empleado.h"
#include "EmpleadoArchivo.h"
#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std ;

// Constructor

Empleado::Empleado() : ID_Puesto(0), horas_Trabajo(0){}

Empleado::Empleado(int ID_Puesto, int horas_Trabajo){

    setID_Puesto (ID_Puesto) ;

    setHoras_Trabajo (horas_Trabajo) ;
}

// Getters

int Empleado::getID_Puesto(){

    return ID_Puesto ;
}

int Empleado::getHoras_Trabajo(){

    return horas_Trabajo ;
}

// Setters

void Empleado::setID_Puesto(int ID_Puesto){

    this->ID_Puesto = ID_Puesto ;
}

void Empleado::setHoras_Trabajo(int horas_Trabajo){

    this->horas_Trabajo = horas_Trabajo ;
}

// Metodos

void Empleado::cargar(){

    EmpleadoArchivo reg ;

    Empleado empleado1 ;

    string datos ;

    int datos2 ;

    int const cantReg = reg.getCantidadRegistros() ;

    cout << "Ingrese el CUIT del empleado: " ;

    cin >> datos ;

      for (int i = 0; i<cantReg; i++){

        empleado1 = reg.leer(i) ;

        while (strcmp(datos.c_str(), empleado1.getCuit().c_str()) == 0 && empleado1.getEstado() == true) {

            cout << "El CUIT ya corresponde a un empleado existente. Desea salir o introducir otro CUIT?: (1- Agregar otro CUIT, 2- Salir)" ;

            cin >> datos2 ;

            switch (datos2){

            case 1:

                cout << "Ingrese el nuevo CUIT: " ;

                cin >> datos ;

                break ;

            case 2:

                cout << "Saliendo..." << endl ;

                return ;

                break ;

            default:

                cout << "La opcion que eligio es invalida. Intentelo de nuevo. " << endl ;

                break;
            }

        }
    }

    Empleado::setCuit(datos) ;

    cout << "Ingrese el tipo de empleado: " ;

    cin >> datos2 ;

    Empleado::setID_Puesto(datos2) ;

    cout << "Ingrese la cantidad de horas trabajadas por semana del empleado: " ;

    cin >> datos2 ;

    Empleado::setHoras_Trabajo(datos2) ;

    cout << "Ingrese el nombre del empleado: "  ;

    cin >> datos ;

    Empleado::setNombre(datos) ;

    cout << "Ingrese el apellido del empleado: " ;

    cin >> datos ;

    Empleado::setApellido(datos) ;

    cout << "Ingrese el telefono del empleado: " ;

    cin >> datos ;

    Empleado::setTelefono(datos) ;

    cout << "Ingrese la direccion del empleado: "  ;

    datos = cargarCadena() ;

    Empleado::setDireccion(datos) ;

    Empleado::setEstado(true) ;

    cout << endl << "El empleado fue agregado con exito. " << endl ;

}

void Empleado::mostrar(){

    cout << "Informacion del empleado: " << endl ;

    cout << "ID del empleado: " << Empleado::getID() << endl ;

    cout << "Nombre y apellido del empleado: " << Empleado::getNombre() << " " << Empleado::getApellido() << endl ;

    cout << "Telefono del empleado: " << Empleado::getTelefono() << endl ;

    cout << "Direccion del empleado: " << Empleado::getDireccion() << endl ;

    cout << "CUIT del empleado: " << Empleado::getCuit() << endl ;

    cout << "ID de puesto del empleado: " << Empleado::getID_Puesto() << endl ;

    cout << "Horas trabajadas por semana del empleado: " << Empleado::getHoras_Trabajo() << endl ;

    cout << "Estado: " << Empleado::getEstado() << endl ;

    cout << endl ;
}
