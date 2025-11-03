#pragma once
#include "Persona.h"


class Proveedor : public Persona
{

private: // Atributos

    int tipo_proveedor ;

    char mail [30] ;

public:

// Constructor

    Proveedor () ;

    Proveedor (int tipo_proveedor) ;

// Getters

    int getTipo_proveedor () ;

    std::string getMail () const ;

// Setters

    void setTipo_proveedor (int tipo_proveedor) ;

    void setMail (std::string mail) ;

// Metodos

    void cargar () ;

    void mostrar () ;

    void modificarCampo () ;

};


