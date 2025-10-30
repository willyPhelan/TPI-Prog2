#include "Empleado.h"
#include <iostream>
#include <string>
#include <cstring>
#include "Utils.h"
#include "EmpleadoArchivo.h"

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

    string datos ;
    int datos2 ;


    EmpleadoArchivo reg;

    int const cantReg = reg.getCantidadRegistros();

    Empleado empleado1;

    cout << "Ingrese el CUIT del empleado: " << endl ;
    cin >> datos;

    for (int i = 0; i<cantReg; i++)
    {
        empleado1 = reg.leer(i);

        while (strcmp(datos.c_str(), empleado1.getCuit().c_str()) == 0 && empleado1.getEstado() == true)
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

    Empleado::setCuit(datos);

    cout << "Ingrese el tipo de empleado: " ;

    cin >> datos2 ;

    Empleado::setID_Puesto(datos2) ;

    cout << "Ingrese la cantidad de horas trabajadas por semana del empleado: " ;

    cin >> datos2 ;

    Empleado::setHoras_Trabajo(datos2) ;

    cout << "Ingrese el nombre del empleado: " << endl;
    cin >> datos;
    Empleado::setNombre(datos);

    cout << "Ingrese el apellido del empleado: " << endl;
    cin >> datos;
    Empleado::setApellido(datos);

    cout << "Ingrese el telefono del empleado: " << endl;
    cin >> datos;
    Empleado::setTelefono(datos);

    cout << "Ingrese la direccion del empleado: " << endl;
    datos = cargarCadena();
    Empleado::setDireccion(datos);

    Empleado::setEstado(true);

    Empleado::setID(reg.getCantidadRegistros()+1);

    cout << "El empleado fue agregado exitosamente. Se le asigno el ID: " << getID() << endl;

    system ("pause");

    system("cls") ;

}

void Empleado::mostrar(){

    cout << "Informacion del empleado: " << endl ;

    cout << endl ;

    cout << "ID del empleado: " << Empleado::getID() << endl;

    cout << "Nombre y apellido del empleado: " << Empleado::getNombre() << " " << Empleado::getApellido() << endl ;

    cout << "Telefono del empleado: " << Empleado::getTelefono() << endl ;

    cout << "Direccion del empleado: " << Empleado::getDireccion() << endl ;

    cout << "CUIT del empleado: " << Empleado::getCuit() << endl ;

    cout << "ID de puesto del empleado: " << Empleado::getID_Puesto() << endl ;

    cout << "Horas trabajadas por semana del empleado: " << Empleado::getHoras_Trabajo() << endl ;

    if (Empleado::getEstado())
    {
        cout << "Estado: Activo " << endl;
    }else{

        cout << "Estado: Inactivo " << endl;
    }

    //cout << "Estado: " << Empleado::getEstado() << endl ;

    cout << endl ;

  //  system("pause") ;

   // system("cls") ;

}
