#pragma once
#include "Persona.h"

class Empleado : public Persona{

private:

    int ID_Puesto ;

    int horas_Trabajo ;

public:

    Empleado() ;

    Empleado (int ID_Puesto, int horas_Trabajo) ;

    int getID_Puesto() ;

    int getHoras_Trabajo() ;

    void setID_Puesto(int ID_Puesto) ;

    void setHoras_Trabajo(int horas_Trabajo) ;

    void cargar() ;

    void mostrar() ;
} ;


