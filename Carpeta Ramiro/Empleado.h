#pragma once
#include "Persona.h"

class Empleado : public Persona{

private: // Atributos

    int ID_Puesto ;

    int horas_Trabajo ;

public:

// Constructor

    Empleado() ;

    Empleado (int ID_Puesto, int horas_Trabajo) ;

// Getters

    int getID_Puesto() ;

    int getHoras_Trabajo() ;

// Setters

    void setID_Puesto(int ID_Puesto) ;

    void setHoras_Trabajo(int horas_Trabajo) ;

// Metodos

    void cargar () ;

    void mostrar () ;
};
