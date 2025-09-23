#pragma once
#include "TareaManager.h"

class TareaMenu{

    private:

        int _cantidadOpciones ;


    protected:

        TareaManager _tareaManager ; // TareaMenu tiene un miembro llamado _tareaManager de tipo TareaManager. -> COMPOSICION

        //  metodos para el menu, que estan en protected por si los deseo heredar en otras clases

        void mostrarOpciones();

        int seleccionarOpciones() ;

        void ejecutarOpcion(int opcion) ;

    public:

        TareaMenu() ; // constructor

        void mostrar() ;

};
