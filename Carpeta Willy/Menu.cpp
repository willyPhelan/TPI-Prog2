#include "Menu.h"
#include <iostream>
#include "Persona.h" // Necesario para usar la clase Persona
#include "Empleado.h"
#include "Cliente.h"
#include "Proveedor.h"

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

                // Lógica de ABML Productos

                subMenuABML_Productos() ;

                break ;

            case 3:

                // Lógica de ABML Ventas (

                subMenuABML_Ventas() ;

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

// SUBMENU ABML PRODUCTOS

void Menu::subMenuABML_Productos(){

    int opcion  ;

    ProductoArchivo archivo1 ;

    do {

        system("pause") ;

        system("cls") ;

        cout << "MENU ABML DE PRODUCTOS" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "1. Cargar producto" << endl ;

        cout << "2. Modificar producto (por ID)" << endl ;

        cout << "3. Eliminar producto (Baja logica por ID)" << endl ;

        cout << "4. Listar todos los Productos" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "0. Volver al menu ABML" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cout << endl ;

        cin >> opcion ;

        switch (opcion) {

            case 1: {

                // Lógica Cargar Producto

                system("cls") ;

                cout << "Carga de producto" << endl ;

                cout << "--------------------------------------------" << endl ;

                Producto producto1 ; // Instancia de clase Producto

                // ASIGNO ID AUTOINCREMENTAL

                int nuevoID = archivo1.obtenerID() ;

                producto1.setID_Producto(nuevoID) ;

                cout << "ID de Producto: " << nuevoID << " (Autogenerado)" << endl;

                producto1.cargar(); // Usamos el método cargar que definiste en Producto.cpp

                // 2. Guardar en el archivo

                if (archivo1.guardar(producto1)) {

                        cout << endl << "Producto cargado con exito." << endl ; } else {

                        cout << "ERROR: No se pudo guardar el producto en el archivo." << endl ; }

                break ;
            }

            case 2: {

                // MODIFICAR PRODUCTO

                system("cls") ;

                int idBuscar ;

                cout << "MODIFICAR PRODUCTO" << endl ;

                cout << "--------------------------------------------" << endl ;

                cout << "Ingrese el ID del producto a modificar: " ;

                cin >> idBuscar ;

                cout << endl ;

                // Busco la posicion del registro

                int pos = archivo1.buscarPosicion(idBuscar) ;

                if (pos == -1) {

                    cout << "ERROR: No se encontro ningun producto con ID " << idBuscar << endl ;

                } else {

                    // leo el registro actual

                    Producto regModificar = archivo1.leer(pos) ;

                    cout << "Producto Actual (ID " << idBuscar << ")" << endl ;

                    regModificar.mostrar() ;

                    cout << "--------------------------------------------" << endl ;

                    // 3. Pedir los nuevos datos

                    cout << "Ingrese los nuevos datos del producto (el ID se mantendra):" << endl ;

                    regModificar.cargar() ; // Carga todos los atributos excepto el ID

                    // 4. Aseguro que el ID autoincremental no se pierda al sobreescribir

                    regModificar.setID_Producto(idBuscar) ;

                    // Escribo el registro modificado en la misma posición

                    if (archivo1.modificar(regModificar)) {

                        cout << endl << "Producto (ID " << idBuscar << ") modificado con exito." << endl ;

                    } else {

                        cout << endl << "ERROR: No se pudo escribir la modificacion en el archivo." << endl ;
                    }
                }

                break;
            }


            case 3: {

                // BAJA LÓGICA

                system("cls") ;

                int idBaja ;

                cout << "DAR DE BAJA UN PRODUCTO" << endl ;

                cout << "--------------------------------------------" << endl ;

                cout << "Ingrese el ID del producto a dar de baja: " ;

                cin >> idBaja ;

                cout << endl ;

                //Llamo a la fn bajaLogica

                if (archivo1.bajaLogica(idBaja)) {

                    cout << "Producto (ID " << idBaja << ") dado de baja logicamente (Estado: INACTIVO)." << endl ;

                } else {

                    cout << "ERROR: No se pudo completar la baja." << endl ;

                    cout << "Posibles razones: El ID " << idBaja << " no existe, o el producto ya esta inactivo." << endl ;
                }

                break ;
            }


            case 4: {

                system("cls") ;

                int cantidad = archivo1.getCantidadRegistros() ;

                if (cantidad == 0) {

                    cout << "No hay productos cargados en el sistema." << endl ;

                    break ;

                } else {

                cout << "LISTADO DE PRODUCTOS" << endl ;

                cout << "---------------------------------------------" << endl ;

                cout << "Cantidad de registros: " << cantidad << endl ;

                for (int i = 0; i < cantidad; i++) {

                    Producto reg = archivo1.leer(i) ;

                        cout << "---------------------------------------------" << endl ;

                        reg.mostrar() ;

                }

                        cout << "---------------------------------------------" << endl ;

                break ; }
            }

            case 0:

                cout << endl << "Volviendo al menu ABML..." << endl ;

                break ;

            default:

                cout << "Opcion invalida. Intente de nuevo." << endl ;

                break ;
        }

    } while (opcion != 0) ;
}

// SUB MENU VENTAS

void Menu::subMenuABML_Ventas() {

    int opcion ;

    Venta venta1 ; // Instancia de Venta

    do {

        system("pause") ;

        system("cls") ;

        cout << "MENU ABML DE VENTAS" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "1. Cargar venta" << endl ;

        cout << "2. Modificar venta (por ID)" << endl ;

        cout << "3. Anular venta (Baja logica por ID)" << endl ;

        cout << "4. Listar todas las ventas" << endl ;

         cout << "--------------------------------------------" << endl ;

        cout << "0. Volver al menu ABML" << endl ;

         cout << "--------------------------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cout << endl ;

        cin >> opcion ;

        switch (opcion) {

            case 1: {

                // Lógica Cargar Venta

                system("cls") ;

                venta1.cargarVenta() ;

                cout << endl << "Venta cargada con exito (simulada). Pendiente guardar en archivo." << endl ;

                break ;
            }

            case 2: {

                // Lógica Modificar Venta

                cout << "Funcionalidad modificar venta no implementada." << endl ;

                break ;
            }

            case 3: {

                // Lógica Anular Venta (Baja Lógica)

                cout << "Funcionalidad anular venta no implementada." << endl ;

                break ;
            }

            case 4: {

                // Lógica Listar TODAS las Ventas

                cout << "Funcionalidad listar todas las ventas no implementada." << endl ;

                break ;
            }

            case 0:

                cout << "Volviendo al menu ABML..." << endl ;

                break ;

            default:

                cout << "Opcion invalida. Intente de nuevo." << endl ;

                break ;
        }

    } while (opcion != 0) ;
}
