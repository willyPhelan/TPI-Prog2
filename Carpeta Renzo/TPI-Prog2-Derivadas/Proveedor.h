#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED
#pragma once
#include "Persona.h"

using namespace std;

class Proveedor : public Persona
{
private: // Atributos
    int Tipo_proveedor;

public:
// Constructor

Proveedor (int Tipo_proveedor);

// Getters

int getTipo_proveedor ();

// Setters

void setTipo_proveedor (int Tipo_proveedor);

// Metodos

void Cargar ();
void Mostrar ();
};

#endif // PROVEEDOR_H_INCLUDED
