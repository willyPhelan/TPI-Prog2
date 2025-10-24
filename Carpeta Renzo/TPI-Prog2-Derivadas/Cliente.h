#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#pragma once
#include "Persona.h"

using namespace std;
class Cliente : public Persona {
private: // Atributos
    char Mail [30];
    int Tipo_Cliente;

public:
// Constructor

Cliente (string Mail, int Tipo_Cliente);

// Getters

string getMail ();
int getTipo_Cliente();

// Setters

void setMail (string Mail);
void setTipo_Cliente (int Tipo_Cliente);

// Metodos

void Cargar();
void Mostrar();
};


#endif // CLIENTE_H_INCLUDED
