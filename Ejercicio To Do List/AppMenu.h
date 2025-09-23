#pragma once
#include "TareaMenu.h"


class AppMenu {

  private:

        int _cantidadOpciones ;


    protected:

        TareaMenu  _tareaMenu ;

        //  metodos para el menu, que estan en protected por si los deseo heredar en otras clases

        void mostrarOpciones();

        int seleccionarOpciones() ;

        void ejecutarOpcion(int opcion) ;

    public:

        AppMenu() ; // constructor

        void mostrar() ;

        } ;
