#include "Tarea.h"
#include <iostream>
#include <cstring>


using namespace std ;

    Tarea::Tarea()  // constructor por defecto

        : _id(0), _descripcion(""), _estado(false){} // asigno valores por defecto mediante lista de inicializacion

    Tarea::Tarea(int id, string descripcion, bool estado){ // como recibo los valores por parametro, necesito utilizar los setters para asignarselos a las porpiedades sin romper el encapsulamineto

        setID(id) ;
        setDescripcion(descripcion) ;
        setEstado(estado) ;

    }

    //////////////////////////

    int Tarea::getID () const{

    return _id ;

    } ;

    void Tarea::setID(int id){

    _id = id ;

    } ;

    /////////////////////////

    bool Tarea::getEstado () const {

        return _estado ;

    } ;


    void Tarea::setEstado(bool estado){

        _estado = estado ;


    }  ;

    /////////////////////////

    std::string Tarea::getDescripcion () const {

        return _descripcion ; } ;


    void Tarea::setDescripcion(std::string descripcion){

        strncpy(_descripcion, descripcion.c_str(), 299) ; // _descripcion lo definimos en private com char, pero desde el usuario se lo trata como string, por lo que usamos c_str para que nos devuelva el puntero con para saber donde esta alamcenada la info en la HEAP y con strcpy lo copiamos a nuestro vector de char que es la prop del objeto ;
                                                         // 299 es el numero de caracteres que voy a copar con strcpy, el vec de char llega a 300 pero ponemos 299 para no copiar el caracterterminador /0


    } ;


    bool Tarea::getEliminado() const { return _eliminado ; } ;

    void Tarea::setEliminado(bool eliminado){

        _eliminado = eliminado ;



    } ;
