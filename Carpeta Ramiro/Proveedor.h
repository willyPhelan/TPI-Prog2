#pragma once
#include "Persona.h"

class Proveedor : public Persona {

private: // Atributos

    int tipo_proveedor ;

public:

// Constructor

Proveedor () ;

Proveedor (int tipo_proveedor) ;

// Getters

int getTipo_proveedor () ;

// Setters

void setTipo_proveedor (int tipo_proveedor) ;

// Metodos

void cargar () ;

void mostrar () ;

};
