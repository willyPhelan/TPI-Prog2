#pragma once
#include "Tarea.h"

class TareaArchivo{

    public:

        TareaArchivo(std::string nombreArchivo = "tareas.dat") ;

        bool guardarArchivo(const Tarea &registro) ;

        bool guardarArchivo(int pos, const Tarea &registro) ; // necesito la posicion el registro y la direccion del objeto que quiero modificar (&registro) // tiene el mismo nombre -> se diferencia por parametros de la fn de arriba (sobrecarga de fns)

        int getCantidadRegistros() ;

        int getNuevoID() ;

        int buscarId(int id) ;

        bool eliminar(int pos) ;

        Tarea leer(int pos) ;

        int leerTodas(Tarea tareas[], int cantidad) ;

    private:

        std::string _nombreArchivo ; // aca si uso un string como tipo de dato y no char porque no necesito guardar el nombre solo lo voy amostrar por lo tanto no tengo que manipular el dato

};
