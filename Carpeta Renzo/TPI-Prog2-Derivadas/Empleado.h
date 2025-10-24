#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#pragma once
#include "Persona.h"

class Empleado : public Persona
{
private: // Atributos
    int ID_Puesto;
    int Horas_Trabajo;

public:
// Constructor

    Empleado (int ID_Puesto, int Horas_Trabajo);

// Getters

    int getID_Puesto();
    int getHoras_Trabajo();

// Setters

    void setID_Puesto(int ID_Puesto);
    void setHoras_Trabajo(int Horas_Trabajo);

// Metodos

    void Cargar ();
    void Mostrar ();
};

#endif // EMPLEADO_H_INCLUDED
