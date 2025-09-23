#include <iostream>
#include "TareaArchivo.h"
using namespace std ;

TareaArchivo::TareaArchivo(std::string nombreArchivo)

: _nombreArchivo(nombreArchivo)  // constructor para asignar le nombre del archivo

{} ;


bool TareaArchivo::guardarArchivo(const Tarea &registro){

    FILE *pFile ;

    pFile = fopen(_nombreArchivo.c_str(), "ab") ; // recordar que _nombreArchivo es un string y lo que recibe el puntero file es un vec de char, por lo que uso c_str()

    if(pFile == nullptr) {

        return false ;
    }

    bool result = fwrite(&registro, sizeof(Tarea), 1, pFile) ; // si f write pudo guardar la tarea mandara la cantidad de regstros que pudo guardar, si yo le digo que gusrde 1 (tercer parametro) devolvera 1

    fclose(pFile) ;

    return result ;


}
 // SOBRECARGA DE FUNCIONES

bool TareaArchivo::guardarArchivo(int pos, const Tarea &registro){ // recibo la tarea por parametro


    bool result ;

    FILE *pFile ;

    pFile = fopen(_nombreArchivo.c_str(), "rb+") ; // RB+ porque lee y guarda

    if(pFile == nullptr) {



        return false ;
    }

    fseek(pFile, sizeof(Tarea)* pos, SEEK_SET) ; // al puntero file (primer parametro) lo muevo la cantidad de registros que tiene Tarea multiplicado por la posicion que recibo por parametro, desde le inicio (SEEK_SET

    result = fwrite(&registro, sizeof(Tarea), 1, pFile) ;// escribe sobre el registro segun la posicion recibida por parametro

    fclose(pFile) ;

    return result ;


}


Tarea TareaArchivo::leer(int pos) {

    Tarea registro ;

    bool result ;

    FILE *pFile ;

    pFile = fopen(_nombreArchivo.c_str(), "rb") ;

    if(pFile == nullptr) {

        registro.setID(-1) ;

        return registro ;
    }

    fseek(pFile, sizeof(Tarea)* pos, SEEK_SET) ; // al puntero file (primer parametro) lo muevo la cantidad de registros que tiene Tarea multiplicado por la posicion que recibo por parametro, desde le inicio (SEEK_SET

    result = fread(&registro, sizeof(Tarea), 1, pFile) ;

    fclose(pFile) ;

    return registro ;

}


int TareaArchivo::leerTodas(Tarea tareas[], int cantidad) {

    bool result ;

    FILE *pFile ;

    pFile = fopen(_nombreArchivo.c_str(), "rb") ;

    if(pFile == nullptr) {

        return 0 ;
    }

   result = fread(tareas, sizeof(Tarea), cantidad, pFile) ; // leo la cantidad de tareas y segun lo que le pase como cantidad le digo de leer registro por regisgtro o todos de una

    fclose(pFile) ;

    return result ;

}


int TareaArchivo::getCantidadRegistros(){

    Tarea registro ;
    int cantidad ;
    FILE *pFile ;

    pFile = fopen(_nombreArchivo.c_str(), "rb") ;

    if(pFile == nullptr){

        return 0 ;
    }

    fseek(pFile, 0, SEEK_END) ; // mueve el puntero al final del archivo el segundo parametro es cuanto lo quiero mover, el tercero es hasta donde, al final del archivo

    cantidad = ftell(pFile) / sizeof(Tarea) ;  // ftell(pfile) Devuelve la posición actual en bytes del puntero. Como está en el final, devuelve el tamaño total del archivo. depsues divido la cantidad de bytes totales del archivo por los bytes que ocupa un solo objeto Tarea.
                                                //El resultado es el número de registros Tarea grabados en ese archivo.
    fclose(pFile) ;

    return cantidad ;
}

int TareaArchivo::getNuevoID(){

    return getCantidadRegistros() + 1 ; }



int TareaArchivo::buscarId(int id){

 Tarea registro ;

    int pos = -1 ;
    int posActual = 0 ;

    FILE *pFile ;

    pFile = fopen(_nombreArchivo.c_str(), "rb") ;

    if(pFile == nullptr) {

        return pos ;
    }


    while(fread(&registro, sizeof(Tarea), 1, pFile)){

        if(registro.getID() == id){

            pos = posActual ;

            break ;

        }

        posActual++ ;
    }

    fclose(pFile) ;

    return pos ;

}


bool TareaArchivo::eliminar(int pos){ // elimino un registro segun su posicion

    Tarea registro = leer(pos) ;

    if(registro.getID() == -1){ return false ; }

    registro.setEliminado(true) ;  // cambio el estado

    return guardarArchivo(pos, registro) ;





}
