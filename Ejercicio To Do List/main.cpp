#include <iostream>
#include "Tarea.h"
#include "AppMenu.h"

using namespace std;

int main()
{
   /*  TareaArchivo tarea1 ;

    Tarea t (tarea1.getNuevoID(), "Cambia ID") ;

    tarea1.guardarArchivo(t) ;

    for(int i = 0 ; i < tarea1.getCantidadRegistros() ; i++ ) {

        Tarea registro = tarea1.leer(i) ;

        cout << "Numero de tarea: " <<registro.getID() << " -> " << "Tarea: " << registro.getDescripcion() << endl ;
    } */

   /* TareaManager tarea1 ;

    tarea1.cargarTarea() ;
    tarea1.mostrarTareas() ; */

   /*  TareaMenu tareaMenu ;

    tareaMenu.mostrar() ; */

    AppMenu app ;

    app.mostrar() ;

    return 0 ;
}
