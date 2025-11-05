#include "Utils.h"
#include <iostream>
#include <cctype>

using namespace std ;


string cargarCadena()
{

    std::string texto ;

    if(std::cin.peek() == '\n')
    {

        std::cin.ignore() ;
    }

    std::getline(std::cin, texto) ;

    return texto ;

}

string aMinusculas(string s)
{

    int longitud = s.length();

    for (int i = 0; i < longitud; ++i)
    {

        // tolower() convierte el carácter a minúscula

        s[i] = tolower(s[i]) ;
    }

    return s ;
}
