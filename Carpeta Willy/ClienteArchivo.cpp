#include "ClienteArchivo.h"
#include "Cliente.h"
#include <iostream>
#include <cstdio>

using namespace std ;

/// FUNCIONES ABML

bool ClienteArchivo::guardar(const Cliente &reg){

    FILE *archivo ;

    archivo = fopen (archivo_Cliente, "ab") ;

    if (archivo == nullptr){

        cout << "NO SE PUDO CREAR EL ARCHIVO. " << endl ;

        return false ;
    }

    int escribio = fwrite (&reg, sizeof (Cliente), 1, archivo) ;

    fclose (archivo) ;

    return escribio ;
}

bool ClienteArchivo::bajaLogica (int id_persona){

    int pos = buscarPosicion (id_persona) ;

    if (pos == -1){

        cout << "El ID que ingreso es incorrecto. " << endl ;

        system ("pause") ;

        return false ;

    }
    Cliente reg = leer (pos) ;

    reg.setEstado (false) ;

    FILE *archivo ;

    archivo = fopen (archivo_Cliente, "rb+") ;

    if (archivo == nullptr){ return false ; }

    fseek (archivo, pos * sizeof (Cliente), SEEK_SET) ;

    int escrito = fwrite (&reg, sizeof (Cliente), 1, archivo) ;

    fclose (archivo) ;

    return escrito ;

}

bool ClienteArchivo::altaLogica (int id_persona) {

     int pos = buscarPosicion (id_persona);

    if (pos == -1)
    {
        cout << "El ID que ingreso es incorrecto. " << endl;
        system ("pause");
        return false;
    }
    Cliente reg = leer (pos);

    reg.setEstado (true);

    FILE *archivo;

    archivo = fopen (archivo_Cliente, "rb+");

    if (archivo == nullptr)
    {
        return false;
    }

    fseek (archivo, pos * sizeof (Cliente), SEEK_SET);

    int escrito = fwrite (&reg, sizeof (Cliente), 1, archivo);

    fclose (archivo);

    return escrito;

}

Cliente ClienteArchivo::leer (int pos){

    Cliente reg ;

    FILE *archivo ;

    archivo = fopen (archivo_Cliente, "rb") ;

    if (archivo == nullptr){ return reg ; }

    fseek (archivo, pos * sizeof (Cliente), SEEK_SET) ;

    fread (&reg, sizeof (Cliente), 1, archivo) ;

    fclose (archivo) ;

    return reg ;
}

bool ClienteArchivo::modificar (const Cliente &reg){

    int pos = buscarPosicion (reg.getID()) ;

    if (pos == -1){

        cout << "El ID ingresado es incorrecto. " << endl ;

        return false ;
    }

    FILE *archivo;

    archivo = fopen (archivo_Cliente, "rb+") ;

    if (archivo == nullptr){ return false ; }

    fseek (archivo, pos * sizeof (Cliente), SEEK_SET) ;

    int escribio = fwrite (&reg, sizeof (Cliente), 1, archivo) ;

    fclose (archivo) ;

    return escribio ;
}
/// FUNCIONES AUXILIARES

int ClienteArchivo::buscarPosicion (int id_persona){

    Cliente reg ;

    int cantReg = getCantidadRegistros() ;

    for (int i = 0; i<cantReg; i++){

        reg = leer(i) ;

        if (reg.getID() == id_persona){ return i ; }

    }
    return -1 ;
}

int ClienteArchivo::getCantidadRegistros (){

    FILE *archivo ;

    archivo = fopen (archivo_Cliente, "rb") ;

    if (archivo == nullptr){ return 0 ; }

    fseek (archivo, 0, SEEK_END) ;

    int tamanio = ftell (archivo) ;

    fclose (archivo) ;

    return tamanio / sizeof (Cliente) ;

}
