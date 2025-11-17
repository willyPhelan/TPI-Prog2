#pragma once
#include "Cliente.h"
#include <cstdio>

class ClienteArchivo
{

private: /// Atributos

    const char *archivo_Cliente = "Clientes.dat" ;

    const char *archivo_Clientesbkp = "Clientes.bkp" ;

public: /// Metodos

/// FUNCIONES ABML

    bool guardar (const Cliente &reg) ;

    bool bajaLogica (int id_persona) ;

    bool altaLogica(int id_persona) ;

    Cliente leer (int pos) ;

    bool modificar (const Cliente &reg) ;

    int getCantidadRegistros () ;

    int buscarPosicion (int id_persona) ;

    bool validarCUIT (std::string cuit) ;

    void modificarCampo ();

    bool hacerBackup() ;

    bool restaurarBackup() ;

} ;


