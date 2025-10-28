#pragma once
#include "Persona.h"

class Cliente : public Persona {

private: // Atributos

    char mail [30] ;

    int tipo_Cliente ;

public:


// Constructor

Cliente() ; // agrego constructor por defecto

Cliente (std::string mail, int tipo_Cliente) ;

// Getters

std::string getMail () ;

int getTipo_Cliente() ;

// Setters

void setMail (std::string mail) ;

void setTipo_Cliente (int tipo_Cliente) ;

// Metodos

void cargar() ;

void mostrar() ;

};

