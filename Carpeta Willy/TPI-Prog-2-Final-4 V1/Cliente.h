#pragma once
#include "Persona.h"


class Cliente : public Persona
{

private:

    char mail [30] ;

    int tipo_Cliente ;

public:

    Cliente() ;

    Cliente (std::string mail, int tipo_Cliente) ;

    std::string getMail () ;

    int getTipo_Cliente() ;

    void setMail (std::string mail) ;

    void setTipo_Cliente (int tipo_Cliente) ;

    void cargar() ;

    void mostrar() ;



};

