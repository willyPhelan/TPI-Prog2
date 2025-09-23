#pragma once
#include <string>

class Tarea {

     private:

        int _id ;
        char _descripcion[300] ;
        bool _estado ;
        bool _eliminado ;

    public:

        // constructor

        Tarea() ;

        Tarea(int id, std::string descripcion, bool estado = false) ;

        // getters //

        int getID() const ;
        bool getEstado() const ;
        std::string getDescripcion() const ; // uso std porque en .h no es conveniente usar namespace std

        bool getEliminado() const ;


        // setters //

        void setID(int id) ;
        void setEstado(bool estado)  ;
        void setDescripcion(std::string descripcion) ; // defino descripcion como un vector de char, para que los datos de almacenen en la estructura y no en la memoria heap pero lo trato como un string para poder utilicar todos los metodos de este tipo de dato

        void setEliminado(bool _eliminado) ;



    };
