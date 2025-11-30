#pragma once
#include "Persona.h"


class Proveedor : public Persona
{

private:

    int tipo_proveedor ;

    char mail [30] ;

public:


    Proveedor () ;

    Proveedor (int tipo_proveedor) ;

    int getTipo_proveedor () ;

    std::string getMail () const ;

    void setTipo_proveedor (int tipo_proveedor) ;

    void setMail (std::string mail) ;

    void cargar () ;

    void mostrar () ;

};


