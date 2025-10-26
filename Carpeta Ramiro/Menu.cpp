#include "Menu.h"
#include <iostream>
#include "Persona.h" // Necesario para usar la clase Persona
#include "Empleado.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "Producto.h"
#include "Ventas.h"

using namespace std ;

// MENU PERSONAS

void Menu::subMenuPersonas() {

    int opcion ;

    do {

        system("pause") ;

        system("cls") ;

        cout << "MENU ABML PERSONAS" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Clientes " << endl ;

        cout << "2. Empleados " << endl ;

        cout << "3. Proveedores " << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al Menu Principal" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl ;


        switch (opcion) {

            case 1: {

                subMenuABML_Clientes() ;

                break ;

            }

            case 2: {

                subMenuABML_Empleados()  ;

                break ; }

            case 3: {

                system("cls") ;

                subMenuABML_Proveedores() ;

                break ; }

            case 0: {

                cout << "Volviendo al menu principal..." << endl ;

                break ; }

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

        cout << "--------------------------" << endl ;

        cout << "1. ABML" << endl ;

        cout << "2. Reportes " << endl ;

        cout << "3. Copia de seguridad " << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. SALIR" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl << endl ;


        switch (opcion) {

            case 1:

                subMenuABML() ;

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

                cout << "Saliendo del sistema... " << endl ;

                break ;

            default :

                cout << "Opcion Invalida. Intente de nuevo." << endl ;

                system("pause") ;

                break ;
        }

    } while (opcion != 0) ;
}


void Menu::subMenuABML() {

    int opcion ;

    do {

        system("pause") ;

        system("cls") ;

        cout << "MENU ABML" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. ABML Personas " << endl ;      // Llama al submenu de Clientes/Empleados/Proveedores

        cout << "2. ABML Productos " << endl ;

        cout << "3. ABML Ventas " << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al Menu Principal" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl ;


        switch (opcion) {

            case 1:

                subMenuPersonas() ; // menú Personas

                break ;

            case 2:


                subMenuProductos();

                cout << "Funcionalidad ABML Productos no implementada." << endl ;

                break ;

            case 3:


                subMenuVentas();
                cout << "Funcionalidad ABML Ventas no implementada." << endl ;

                break ;

            case 0:

                cout << "Volviendo al menu principal..." << endl ;

                system("pause") ;

                break ;

            default:

                cout << "Opcion Invalida. Intente de nuevo." << endl ;

                break ;
        }

    } while (opcion != 0) ;
}



// SUB MENUS PARA ABMLSSS

// ==================================================================================
// NUEVO: ESTRUCTURA DE MENÚ CON 4 OPCIONES
// ==================================================================================

void Menu::subMenuABML_Clientes() {

    int opcion ;

    do {


        system("cls") ;

        cout << "ABML Clientes" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Cargar Cliente" << endl ;

        cout << "2. Eliminar Cliente" << endl ;

        cout << "3. Modificar Cliente" << endl ;

        cout << "4. Listar Clientes" << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al menu anterior" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cout << endl ;

        cin >> opcion ;


        switch (opcion) {

            case 1: {

                system("cls") ;

                cout << "Carga de Cliente" << endl ;

                cout << "-----------------------------------------" << endl ;

                Persona nuevaPersona ;  // Instancia de la clase Persona y llamada a cargar()

                nuevaPersona.cargar() ; // Carga los datos de la persona

                // a partir de aca cargo los datos especificos de la clase derivada

                Cliente nuevoCliente ;

                nuevoCliente.cargar() ;

                break ;
            }

            case 2: {

                // LOGICA PARA OPCION 2

                cout << "Eliminar un Cliente" << endl ;

                break ;

            }

            case 3: {

                // LOGICA PARA OPCION 3

                cout << "Modificar un Cliente" << endl ;

                break ;
            }

            case 4: {

                cout << "Listado de Clientes" << endl ;

                break ;
            }

            case 0: {

                cout << endl ;

                cout << "Volviendo al menu anterior..." << endl ;

                break ;
            }

            default:

                cout << "Opcion Invalida. Intente de nuevo." << endl ;

                break ;
        }

    } while (opcion != 0) ;

}

// SUB MENU ABML EMPLEADOS

void Menu::subMenuABML_Empleados() {

    int opcion ;

    do {

        system("cls") ;

        cout << "ABML Empleados" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Cargar Empleado" << endl ;

        cout << "2. Eliminar Empleado" << endl ;

        cout << "3. Modificar Empleado" << endl ;

        cout << "4. Listar Empleados" << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al menu anterior" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cout << endl ;

        cin >> opcion ;


        switch (opcion) {

            case 1: {

                system("cls") ;

                cout << "Carga de Empleado" << endl ;

                cout << "-----------------------------------------" << endl ;

                Persona nuevaPersona ;  // Instancia de la clase Persona y llamada a cargar()

                nuevaPersona.cargar() ; // Carga los datos de la persona

                // a partir de aca cargo los datos especificos de la clase derivada

                Empleado nuevoEmpleado ;

                nuevoEmpleado.cargar() ;

                break ;
            }

            case 2: {

                // LOGICA PARA OPCION 2

                cout << "Eliminar un Empleado" << endl ;

                break ;

            }

            case 3: {

                // LOGICA PARA OPCION 3

                cout << "Modificar un Empleado" << endl ;

                break ;
            }

            case 4: {


                cout << "Listado de Empleado" << endl ;

                break ;
            }

            case 0: {

                cout << endl ;

                cout << "Volviendo al menu anterior..." << endl ;

                break ;
            }

            default:

                cout << "Opcion Invalida. Intente de nuevo." << endl ;

                break ;
        }

    } while (opcion != 0) ;

}

// SUB MENU ABML PROVEEDORES

void Menu::subMenuABML_Proveedores() {

    int opcion ;

    do {

        system("cls") ;

        cout << "ABML Proveedores" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Cargar Proveedor" << endl ;

        cout << "2. Eliminar Proveedor" << endl ;

        cout << "3. Modificar Proveedor" << endl ;

        cout << "4. Listar Proveedores" << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al menu anterior" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cout << endl ;

        cin >> opcion ;


        switch (opcion) {

            case 1: {

                system("cls") ;

                cout << "Carga de Proveedor" << endl ;

                cout << "-----------------------------------------" << endl ;

                Persona nuevaPersona ;  // Instancia de la clase Persona y llamada a cargar()

                nuevaPersona.cargar() ; // Carga los datos de la persona

                // a partir de aca cargo los datos especificos de la clase derivada

                Proveedor nuevoProveedor ;

                nuevoProveedor.cargar() ;

                break ;
            }

            case 2: {

                // LOGICA PARA OPCION 2

                cout << "Eliminar un Proveedor" << endl ;

                break ;

            }

            case 3: {

                // LOGICA PARA OPCION 3

                cout << "Modificar un Proveedor" << endl ;

                break ;
            }

            case 4: {

                cout << "Listado de Proveedores" << endl ;

                break ;
            }

            case 0: {

                cout << endl ;

                cout << "Volviendo al menu anterior..." << endl ;

                break ;
            }

            default:

                cout << "Opcion Invalida. Intente de nuevo." << endl ;

                break ;
        }

    } while (opcion != 0) ;

}

void Menu::subMenuProductos(){
int opcion ;

    do {

        system("pause") ;

        system("cls") ;

        cout << "ABML PRODUCTOS" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Cargar Productos " << endl ;

        cout << "2. Eliminar Producto " << endl ;

        cout << "3. Modificar Producto " << endl ;

        cout << "4. Lista de Productos " << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al Menu Principal" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl ;


        switch (opcion) {

            case 1: {
                system("cls") ;
                cout << "Carga de Producto" << endl ;

                cout << "-----------------------------------------" << endl ;

                    Producto nuevoProducto;

                    nuevoProducto.cargar();

                break ;

            }

            case 2: {



                break ; }

            case 3: {

                system("cls") ;



                break ; }

            case 0: {

                cout << "Volviendo al menu principal..." << endl ;

                break ; }

            default:

                cout << "Opcion Invalida. Intente de nuevo." << endl ;

                system("pause") ;

                break ;
        }
    } while (opcion != 0) ;

}

void Menu::subMenuVentas(){
int opcion ;

    do {

        system("pause") ;

        system("cls") ;

        cout << "ABML VENTAS" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Cargar  Venta" << endl ;

        cout << "2. Eliminar Venta " << endl ;

        cout << "3. Modificar Venta " << endl ;

        cout << "4. Lista de Ventas " << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al Menu Principal" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl ;


        switch (opcion) {

            case 1: {
                system("cls") ;
                cout << "Carga de Venta" << endl ;

                cout << "-----------------------------------------" << endl ;

                    Venta nuevaVenta;

                    nuevaVenta.cargarVenta();

                break ;

            }

            case 2: {



                break ; }

            case 3: {

                system("cls") ;



                break ; }

            case 0: {

                cout << "Volviendo al menu principal..." << endl ;

                break ; }

            default:

                cout << "Opcion Invalida. Intente de nuevo." << endl ;

                system("pause") ;

                break ;
        }
    } while (opcion != 0) ;

}
