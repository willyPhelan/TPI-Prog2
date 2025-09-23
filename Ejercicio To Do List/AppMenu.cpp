#include "AppMenu.h"
#include <iostream>

using namespace std ;

AppMenu::AppMenu(){

    _cantidadOpciones = 1 ; } ;




void AppMenu::mostrar(){

    int opcion ;

    do {

        opcion = seleccionarOpciones() ;

        ejecutarOpcion(opcion) ; } while (opcion != 0) ;
    }




void AppMenu::mostrarOpciones(){

     cout << "--- MENU PRINCIPAL --------------" << endl ;
     cout << "1 - Tareas " << endl ;
     cout << "---------------------------------" << endl ;
     cout << "0 - Salir " << endl ;
     cout << "---------------------------------" << endl ;

} ;

int AppMenu::seleccionarOpciones(){

    int opcion ;

    mostrarOpciones() ;

    cout << endl << "Opcion: " ;
    cin >> opcion  ;

    while (opcion < 0 || opcion > _cantidadOpciones){

        cout << "Opcion incorrecta" << endl ;

        cout << "Vuelva a ingresar una opcion valida:" << endl ;

        cin >> opcion ;

    }

    return opcion ;

} ;

void AppMenu::ejecutarOpcion(int opcion){

    switch(opcion) {

    case 1:

        system ("cls") ;

         _tareaMenu.mostrar() ;

        cout << endl << "Ingrese cualquier tecla para volver al menu:" << endl ;

        system ("pause") ;

        system ("cls") ;


    break ;



    }
} ;
