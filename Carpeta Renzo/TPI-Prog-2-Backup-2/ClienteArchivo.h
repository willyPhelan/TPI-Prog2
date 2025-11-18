#pragma once
#include "Cliente.h"
#include <cstdio>

class ClienteArchivo
{

private: /// Atributos

    const char *archivo_Cliente = "Clientes.dat" ;

    const char *archivo_Cliente_Backup = "Clientes_Backup.bkp";

public: /// Metodos

/// FUNCIONES ABML

    bool guardar (const Cliente &reg) ;

    bool bajaLogica (int id_persona) ;

    bool altaLogica(int id_persona) ;

    Cliente leer (int pos) ;

    bool modificar (const Cliente &reg) ;

    void modificarCampo ();

/// FUNCIONES AUXILIARES

    int getCantidadRegistros () ;

    int buscarPosicion (int id_persona) ;

    bool validarCUIT (std::string cuit) ;

    int verificarID (int idcliente);

/// BACKUPS

    bool hacerBackup ();

    bool restaurarBackup ();

} ;


