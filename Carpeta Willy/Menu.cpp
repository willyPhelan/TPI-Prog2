#include "Menu.h"
#include <iostream>
#include "Persona.h" // Necesario para usar la clase Persona

using namespace std ;

// lógica para el submenu de Personas

void Menu::subMenuPersonas() {

    int opcion ;

    do {

        system("pause") ;

        system("cls") ;


        cout << "MENU PERSONAS" << endl ;
        cout << "--------------------------" << endl ;

        cout << "1. Cargar Nueva Persona" << endl ;

        cout << "2. Mostrar Personas (Listar todos)" << endl ;

        cout << "3. Buscar Persona por ID" << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al Menu Principal" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;


        cin >> opcion ;

        cout << endl ;


        switch (opcion) {

            case 1: {

                 system("cls") ;


                Persona nuevaPersona ;  // Instancia de la clase Persona y llamada a cargar()

                nuevaPersona.cargar() ; // Carga los datos de la persona


                break ;
            }
            case 2:

                // Aca va la lógica para leer y listar todas las Personas desde un archivo

                cout << "Funcionalidad no implementada: Listar Personas." << endl ;

                system("pause") ;

                break ;

            case 3:

                // Aca va la lógica para buscar una Persona por ID

                cout << "Funcionalidad no implementada: Buscar Persona." << endl ;

                system("pause") ;

                break ;

            case 0:

                cout << "Volviendo al menu principal..." << endl ;

                break ;

            default:

                cout << "Opcion Invalida. Intente de nuevo." << endl ;

                system("pause") ;

                break ;
        }
    } while (opcion != 0) ;
}

// MENU PRINCIPAL

void Menu::mostrar() {

    int opcion ;

    do {

        system("cls") ;

        cout << "MENU PRINCIPAL DE GESTION" << endl ;

        cout << "1. PERSONAS" << endl ;

        cout << "2. PRODUCTOS" << endl ;

        cout << "3. VENTAS" << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. SALIR" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl << endl ;


        switch (opcion) {

            case 1:

                subMenuPersonas() ; // Llama al submenú de Personas

                break ;

            case 2:

                // aca llamo a subMenuProductos() cuando este

                cout << "MENU PRODUCTOS" << endl ;

                cout << "Funcionalidad no implementada (Se requiere la clase Producto)." << endl ;

                system("pause") ;

                break ;

            case 3:

                // aca llamo subMenuVentas() cuando este

                cout << "MENU VENTA" << endl ;

                cout << "Funcionalidad no implementada (Se requiere la clase Venta)." << endl ;

                system("pause") ;

                break ;

            case 0:

                cout << "Saliendo del sistema... ¡Chau!" << endl ;

                break ;

            default :

                cout << "Opcion Invalida. Intente de nuevo." << endl ;

                system("pause") ;

                break ;
        }

    } while (opcion != 0) ;
}
