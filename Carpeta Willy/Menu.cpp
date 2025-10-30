#include "Menu.h"
#include <iostream>
#include "Persona.h" // Necesario para usar la clase Persona
#include "Empleado.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "ProveedorArchivo.h"
#include "EmpleadoArchivo.h"

using namespace std ;


// MENU PRINCIPAL

void Menu::mostrar() {

    int opcion ;

    do {

        system("cls") ;

        cout << "MENU PRINCIPAL DE GESTION" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Clientes" << endl ;

        cout << "2. Proveedores" << endl ;

        cout << "3. Empleados" << endl ;

        cout << "4. Productos" << endl ;

        cout << "5. Ventas" << endl ;

        cout << "6. Envios" << endl ;

        cout << "7. Listados" << endl ;

        cout << "8. Reportes " << endl ;

        cout << "9. Copia de seguridad " << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. SALIR" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl << endl ;


        switch (opcion) {

            case 1:

                subMenuABML_Clientes() ;

                break ;

            case 2:

                subMenuABML_Proveedores() ;

                break ;

            case 3:

                subMenuABML_Empleados() ;

                break ;

             case 4:

                subMenuABML_Productos() ;

                break ;

             case 5:

                subMenuABML_Ventas() ;

                break ;

             case 6:

                subMenuABML_Envios() ;

                break ;

             case 7:

                subMenuABML_Listados() ;

                break ;

             case 8:

                cout << "REPORTES ACA" << endl ;

                break ;

             case 9:

                cout << "COPIA SEGURIDAD ACA" << endl ;

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

// SUB MENU CLIENTES

void Menu::subMenuABML_Clientes() {

    int opcion ;

    do {


        system("cls") ;

        cout << "Menu de clientes" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Cargar cliente" << endl ;

        cout << "2. Eliminar cliente" << endl ;

        cout << "3. Dar de alta un cliente" << endl ;

        cout << "4. Modificar cliente" << endl ;

        cout << "5. Modificar un campo especifico del cliente" << endl ;

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

                Cliente nuevoCliente ;

                nuevoCliente.cargar() ;

                ClienteArchivo reg ;

                reg.guardar(nuevoCliente) ;

                cout << "El cliente fue agregado con exito. " << endl ;

                system("pause") ;

                break ; }

            case 2: {

                system("cls") ;

                cout << "Eliminar un Cliente" << endl ;

                cout << "-----------------------------------------" << endl ;

                int id_persona ;

                cout << "Ingrese el ID del cliente que desee borrar: " ;

                cin >> id_persona ;

                ClienteArchivo reg ;

                reg.bajaLogica(id_persona) ;

                 cout << "Cliente dado de baja" << endl ;

                system("pause") ;

                break ;

            }

            case 3: {

            system("cls") ;

                cout << "Dar de alta un Cliente" << endl ;

                cout << "-----------------------------------------" << endl ;

                int id_persona ;

                cout << "Ingrese el ID del cliente que desee dar de alta: " ;

                cin >> id_persona ;

                ClienteArchivo reg ;

                reg.altaLogica(id_persona) ;

                 cout << endl << "Cliente dado de alta" << endl ;

                system("pause") ;

                break ;

            }

            case 4:  {

                system("cls") ;

                cout << "Modificar un Cliente" << endl ;

                cout << "--------------------------------------------" << endl;

                int idBuscar ;

                cout << "Ingrese el ID del cliente a modificar: " ;

                cin >> idBuscar ;

                ClienteArchivo archivo ;

                Cliente reg ;

                int pos = archivo.buscarPosicion (idBuscar) ;

                if (pos == -1){

                    cout << "ERROR: No se encontro un cliente con ese ID. " << endl ;

                } else {

                    reg = archivo.leer(pos) ;

                    reg.mostrar() ;

                    cout << "--------------------------------------------" << endl ;

                    cout << "Ingrese los nuevos datos del cliente (el ID se mantendra): " << endl << endl ;

                    reg.cargar() ;

                    reg.setID(idBuscar) ;

                    if (archivo.modificar(reg)){

                        cout << endl << "Cliente modificado con exito. " << endl ;

                    } else {

                        cout << endl << "ERROR: No se pudo escribir la modificacion en el archivo. " << endl ;

                    }
                }

                system("pause") ;

                break ;
            }

            case 5: {}

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

        cout << "Menu de empleados" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Cargar empleado" << endl ;

        cout << "2. Eliminar empleado" << endl ;

        cout << "3. Dar de alta un empleado" << endl ;

        cout << "4. Modificar empleado" << endl ;

        cout << "5. Modificar un campo especifico del empleado" << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al menu anterior" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl ;

        system("pause") ;


        switch (opcion) {

            case 1: {

                system("cls") ;

                cout << "Carga de Empleado" << endl ;

                cout << "-----------------------------------------" << endl ;

                EmpleadoArchivo reg ;

                Empleado nuevoEmpleado ;

                int nuevoID = reg.getCantidadRegistros() + 1;

                nuevoEmpleado.setID(nuevoID) ;

                cout << "ID del empleado: " << nuevoID << endl ;

                nuevoEmpleado.cargar() ;

                reg.guardar(nuevoEmpleado) ;

                system("pause") ;

                break ;
            }

            case 2: {

                // LOGICA PARA OPCION 2

                system("cls") ;

                cout << "Eliminar un Empleado" << endl ;

                int id_persona ;

                cout << "Ingrese el id del empleado que desee borrar: "  ;

                cin >> id_persona ;

                EmpleadoArchivo reg ;

                if (reg.bajaLogica(id_persona)) {

                    cout << endl << "Empleado (ID " << id_persona << ") dado de baja (Estado: INACTIVO)." << endl ;

                } else {

                    cout << endl << "ERROR: No se pudo completar la baja." << endl ;
                }



                system("pause") ;

                break ;

            }

            case 3: {

                system("cls") ;

                cout << "Reactivar un Empleado" << endl ;

                int id_persona;

                cout << "Ingrese el id del empleado que desee reactivar: " ;

                cin >> id_persona ;

                EmpleadoArchivo reg ;

                 if (reg.altaLogica(id_persona)) {

                    cout << endl << "Empleado (ID " << id_persona << ") dado de alta (Estado: ACTIVO)." << endl ;

                } else {

                    cout << endl << "ERROR: No se pudo completar el alta." << endl ;
                }

                system("pause") ;

                break ;

            }

            case 4: {

                system("cls") ;

                cout << "Modificar un Empleado" << endl ;

                cout << endl ;

                int idBuscar ;

                cout << "Ingrese el ID del empleado a modificar: " ;

                cin >> idBuscar ;

                cout << endl ;

                EmpleadoArchivo archivo;

                Empleado reg;

                int pos = archivo.buscarPosicion(idBuscar) ;

                if (pos == -1) {

                    cout << "ERROR: No se encontro ningun empleado con ese ID. " << endl;

                } else {

                    reg = archivo.leer(pos) ;

                    reg.mostrar();

                    cout << "--------------------------------------------" << endl ;

                    cout << endl << "Ingrese los nuevos datos del empleado (el ID se mantendra):" << endl ;

                    cout << "ID del empleado: " << idBuscar << endl ;

                    reg.cargar() ;

                    reg.setID(idBuscar) ;

                    if (archivo.modificar(reg)) {

                        cout << endl << "Empleado modificado con exito. " << endl ;

                    } else {

                        cout << endl << "ERROR: No se pudo escribir la modificacion en el archivo." << endl ;
                    }
                }

                system("pause") ;

                break ;

            }

            case 5: {}


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

        cout << "Menu de proveedores" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Cargar proveedor" << endl ;

        cout << "2. Eliminar proveedor" << endl ;

        cout << "3. Dar de alta un proveedor" << endl ;

        cout << "4. Modificar proveedor" << endl ;

        cout << "5. Modificar un campo especifico del proveedor" << endl ;

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

                ProveedorArchivo archivo ;

                Proveedor nuevoProveedor ;

                int nuevoID = archivo.getCantidadRegistros() + 1 ;

                nuevoProveedor.setID(nuevoID) ;

                cout << "ID del proveedor: " << nuevoID << endl ;

                nuevoProveedor.cargar() ;

                ProveedorArchivo reg;

                reg.guardar(nuevoProveedor) ;

                cout << endl << "El proveedor fue agregado con exito. " << endl ;

                system("pause") ;

                break ;
            }

            case 2: {

                // Eliminar Proveedor

                system("cls") ;

                cout << "Eliminar un Proveedor" << endl ;

                cout << "-----------------------------------------" << endl ;

                int id_proveedor ;

                cout << "Ingrese el ID del proveedor a dar de baja: " ;

                cin >> id_proveedor ;

                ProveedorArchivo archivo ;

                // Se llama a la función de baja

                if (archivo.bajaLogica(id_proveedor)) {

                    cout << endl << "Proveedor (ID " << id_proveedor << ") dado de baja (Estado: INACTIVO)." << endl ;

                } else {

                    cout << endl << "ERROR: No se pudo completar la baja." << endl ;
                }

                system("pause") ;

                break ;



            }

            case 3: {

                // Eliminar Proveedor

                system("cls") ;

                cout << "Dar de alta a un Proveedor" << endl ;

                cout << "-----------------------------------------" << endl ;

                int id_proveedor ;

                cout << "Ingrese el ID del proveedor a dar de alta: " ;

                cin >> id_proveedor ;

                ProveedorArchivo archivo ;

                // Se llama a la función de baja

                if (archivo.altaLogica(id_proveedor)) {

                    cout << endl << "Proveedor (ID " << id_proveedor << ") dado de alta (Estado: ACTIVO)." << endl ;

                } else {

                    cout << endl << "ERROR: No se pudo completar el alta" << endl ;
                }

                system("pause") ;

                break ;



            }

            case 4: {

                system("cls") ;

                cout << "Modificar un Proveedor" << endl ;

                cout << "--------------------------------------------" << endl;

                int idBuscar ;

                cout << "Ingrese el ID del proveedor a modificar: " ;

                cin >> idBuscar ;

                ProveedorArchivo archivo ;

                Proveedor reg ;

                // 1. Busco la posición del registro

                int pos = archivo.buscarPosicion(idBuscar) ;

                if (pos == -1){

                    cout << "ERROR: No se encontro un proveedor con ese ID. " << endl ;

                    system("pause") ;

                } else {

                    // 2. Leo el registro actual

                    reg = archivo.leer(pos) ;

                    reg.mostrar() ; // Muestra el estado actual del proveedor

                    cout << "--------------------------------------------" << endl ;

                    // 3. Pido los nuevos datos

                    cout << endl << "Ingrese los nuevos datos del proveedor (el ID se mantendra): " << endl << endl ;

                    cout << "ID del proveedor: " << idBuscar << endl ;

                    reg.cargar() ; // Carga todos los atributos excepto el ID

                    // 4. Aseguro que el ID se mantenga

                    reg.setID(idBuscar) ;

                    // 5. Escribo el registro modificado en la misma posición

                    if (archivo.modificar(reg)){

                        cout << endl << "Proveedor modificado con exito. " << endl ;

                    } else {

                        cout << endl << "ERROR: No se pudo escribir la modificacion en el archivo. " << endl ;

                    }
                }



                system("pause") ;


                break ;
            }



            case 5: {}


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

        cout << "Menu productos" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "1. Cargar producto" << endl ;

        cout << "2. Modificar producto (por ID)" << endl ;

        cout << "3. Modificar un campo especifico del producto" << endl ;

        cout << "4. Dar de baja un producto" << endl ;

        cout << "5. Dar de alta un producto" << endl ;

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

                cout << "Modificar producto" << endl ;

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

                system("cls") ;

                Producto regModificar ;

                regModificar.modificarCampos() ;

                break ;

            }


            case 4: {

                // BAJA LÓGICA

                system("cls") ;

                int idBaja ;

                cout << "Dar de baja un producto" << endl ;

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

            case 5: {

                // BAJA LÓGICA

                system("cls") ;

                int idAlta ;

                cout << "Dar de alta un producto" << endl ;

                cout << "--------------------------------------------" << endl ;

                cout << "Ingrese el ID del producto a dar de alta: " ;

                cin >> idAlta ;

                cout << endl ;

                //Llamo a la fn bajaLogica

                if (archivo1.altaLogica(idAlta)) {

                    cout << "Producto (ID " << idAlta << ") dado de alta." << endl ;

                } else {

                    cout << "ERROR: No se pudo completar la alta." << endl ;

                    cout << "Posibles razones: El ID " << idAlta << " no existe, o el producto ya esta inactivo." << endl ;
                }

                break ;
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

    // Declaro e instancio el obj de gestión de archivos

    VentaArchivo archivoVenta ;

    EnvioArchivo archivoEnvio ;

    do {

        system("pause") ;

        system("cls") ;

        cout << "Menu Ventas" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "1. Cargar venta" << endl ;

        cout << "2. Modificar venta" << endl ;

        cout << "3. Anular venta" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "0. Volver al menu ABML" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl ;


        switch (opcion) {

            case 1: { // Cargar Venta

                system("cls") ;

                cout<< "Carga de Venta" << endl ;

                cout << "--------------------------------------------------------------" << endl ;

                Venta nuevaVenta ; // instancio obj

                // Obtengo ID autoincremental

                int nuevoID = archivoVenta.obtenerID() ;

                nuevaVenta.setID_Venta(nuevoID); //  Asigno el ID

                cout << "ID de Venta: " << nuevoID << " (Autogenerado)" << endl ;

                // Carga de datos restantes

                nuevaVenta.cargarVenta() ;

                // 3. Guardar en el archivo

                if(archivoVenta.guardar(nuevaVenta)){

                    cout << endl << "Venta cargada con exito (ID: "<< nuevoID <<")." << endl ;

                    if (nuevaVenta.getTipoEnvio() == 1) {

                    cout << "--------------------------------------------------------------" << endl ;

                    cout << "Creando registro de envio..." << endl ;

                    Envio nuevoEnvio ;

                    // Asigno IDS

                        int nuevoID_Envio = archivoEnvio.obtenerID() ; // Obtengo el ID autoincremental para Envio

                        nuevoEnvio.setID_Envio(nuevoID_Envio) ;   // ID del Envio

                        nuevoEnvio.setID_Venta(nuevoID) ;        // ID de la Venta recien creada

                        // 2. Cargar datos del Envio

                        nuevoEnvio.cargar() ; // Llama al metodo cargar() en Envio.cpp

                        // 3. Guardar el Envío en su archivo

                        if (archivoEnvio.guardar(nuevoEnvio)) {

                            cout << "Envio cargado con exito (ID_Envio: " << nuevoID_Envio << ")." << endl ;

                        } else {

                            cout << "ERROR: No se pudo guardar el Envio." << endl;
                        }

                    } else {

                        cout << "Venta no requiere envio (Retiro en local). No se creo registro de Envio." << endl ;
                    }

                } else {

                    cout << "No se pudo guardar la venta en el archivo." << endl ;
                }

                break ;
            }

            case 2: { // Modificar Venta

                system("cls")  ;

                int idBuscar ;

                cout << "Modificar una Venta" << endl ;

                cout << "--------------------------------------------------------------" << endl ;

                cout << "Ingrese el ID de la Venta a modificar: " ;

                cin >> idBuscar ;

                cout << endl ;

                // 1. Buscar la posición

                int pos = archivoVenta.buscarPosicion(idBuscar) ;

                if(pos == -1){

                    cout << "ERROR: No se encontro ninguna Venta con ID "<< idBuscar << endl ;

                } else {

                    Venta regModificar = archivoVenta.leer(pos) ; // 2. Leo el registro actual

                    cout << "Venta Actual: " << endl ;

                    cout << "--------------------------------------------------------------" << endl ;

                    regModificar.mostrarVenta() ;

                    cout << "--------------------------------------------------------------" << endl ;

                    cout << "Ingrese los nuevos datos de la venta (el ID se mantendra):" << endl ;

                    regModificar.cargarVenta() ; // Carga de los datos nuevos

                    regModificar.setID_Venta(idBuscar) ; // Aseguro que el ID se mantenga

                    // Modifico en el archivo

                    if(archivoVenta.modificar(regModificar)){

                        cout << endl << "Venta (ID "<< idBuscar << ") modificada con exito." << endl ;

                    } else {

                        cout << endl << "ERROR: No se pudo escribir la modificacion en el archivo." << endl ;
                    }
                }

                break ;
            }

            case 3: { // Anular Venta (Baja Lógica)

                system("cls") ;

                int idBaja ;

                cout << "Anular una venta" << endl ;

                cout << "--------------------------------------------" << endl ;

                cout << "Ingrese el ID de la venta a anular: " ;

                cin >> idBaja ;

                cout << endl ;

                // llamo a la función bajaLogica

                if(archivoVenta.bajaLogica(idBaja)){

                    cout << "Venta (ID " << idBaja << ") anulada logicamente (Estado: INACTIVO)." << endl ;

                } else {

                    cout << "ERROR: No se pudo completar la anulacion." << endl ;

                    cout << "Posibles razones: El ID " << idBaja << " no existe, o la venta ya estaba inactiva." << endl ;
                }

                break ;
            }

            case 0: {

                cout << "Volviendo al menu ABML..." << endl ;

                break ;
            }

            default:

                cout << "Opcion invalida. Intente de nuevo." << endl ;

                break ;
        }

    } while (opcion != 0) ;
}

// MENU ENVIOS

void Menu::subMenuABML_Envios() {

    int opcion ;

    // Se asume que has incluido "EnvioArchivo.h"

    EnvioArchivo archivoEnvio ;

    do {

        system("pause") ;

        system("cls") ;

        cout << "Menu envios" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "1. Modificar un envio" << endl ;

        cout << "2. Anular un envio" << endl ;

        cout << "3. Dar de alta un envio que fue dado de baja" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "0. Volver al menu ABML" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl ;


        switch (opcion) {

            case 1: { // Modificar Envío

                system("cls") ;

                int idBuscar ;

                cout << "Modificar envio" << endl ;

                cout << "--------------------------------------------------------------" << endl ;

                cout << "Ingrese el ID de envio a modificar: " ;

                cin >> idBuscar ;

                cout << endl ;

                int pos = archivoEnvio.buscarPosicion(idBuscar) ; // Busca por ID_Envío

                if (pos == -1) {

                    cout << "No se encontro envio con ID " << idBuscar << endl ;

                    break ;
                }

                Envio regModificar = archivoEnvio.leer(pos) ;

                regModificar.mostrar() ; // Asumimos que tienes este método

                cout << endl << endl << "Ingrese los nuevos datos del envio: " << endl ;

                regModificar.cargar() ;

                regModificar.setID_Envio(idBuscar) ;

                if (archivoEnvio.modificar(regModificar)) {

                    cout << "Envio (ID " << idBuscar << ") modificado con exito." << endl ;

                } else {

                    cout << "ERROR al modificar el registro." << endl ;
                }

                break ;
            }

            case 2: { // Anular Envio

                system("cls") ;

                int idBaja ;

                cout << "Anular un envio" << endl ;

                cout << "Ingrese el ID de Envio a anular: " ;

                cin >> idBaja ;

                if (archivoEnvio.bajaLogica(idBaja)) { // Usa ID_Envío

                    cout << "Envio (ID " << idBaja << ") anulado logicamente." << endl ;

                } else {

                    cout << "ERROR: No se pudo anular el envio o ya estaba inactivo." << endl ;
                }

                break ;
            }

              case 3: { // Activar Envio

                system("cls") ;

                int idAlta ;

                cout << "Activar un envio dado de baja anteriormente" << endl ;

                cout << "Ingrese el ID de Envio a dar de alta: " ;

                cin >> idAlta ;

                if (archivoEnvio.altaLogica(idAlta)) { // Usa ID_Envío

                    cout << "Envio (ID " << idAlta << ") anulado logicamente." << endl ;

                } else {

                    cout << "ERROR: No se pudo dar de alta el envio." << endl ;
                }

                break ;
            }

            case 0: {

                cout << "Volviendo al menu ABML..." << endl ;

                break ;
            }

            default:

                cout << "Opcion invalida. Intente de nuevo." << endl ;

                break ;
        }

    } while (opcion != 0);
}

// SUB MENU LISTADOS

void Menu::subMenuABML_Listados() {

    int opcion ;

    ProductoArchivo archivo1 ;
    VentaArchivo archivoVenta ;
    EnvioArchivo archivoEnvio ;
    ProveedorArchivo archivoProveedor ;

    do {


        system("cls") ;

        cout << "Menu de listados" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Listado de Clientes" << endl ;

        cout << "2. Listado de Empleados" << endl ;

        cout << "3. Listado de Proveedores" << endl ;

        cout << "4. Listado de Ventas" << endl ;

        cout << "5. Listado de Productos" << endl ;

        cout << "6. Listado de Envios" << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al menu anterior" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cout << endl ;

        cin >> opcion ;


        switch (opcion) {

            case 1: {

                system("cls") ;

                cout << "Listado de Clientes" << endl ;

                cout << "--------------------------" << endl ;

                Cliente nuevoCliente;

                ClienteArchivo reg;

                int cantRegistros = reg.getCantidadRegistros();

                for (int i = 0; i<cantRegistros; i++) {

                    nuevoCliente = reg.leer(i) ;

                    if(nuevoCliente.getEstado() == true){

                        nuevoCliente.mostrar() ;

                        cout << "--------------------------" << endl ;
                    }

                }

                system("pause") ;

                break ;
            }

            case 2: {

                // LOGICA PARA OPCION 2

                system ("cls") ;

                cout << "Listado de Empleados" << endl ;

                Empleado nuevoEmpleado ;

                EmpleadoArchivo reg ;

                int cantRegistros = reg.getCantidadRegistros();

                for (int i = 0; i<cantRegistros; i++)
                {
                    cout << endl;

                    cout << "------------------------------" << endl;

                    nuevoEmpleado = reg.leer (i);

                    nuevoEmpleado.mostrar ();

                    cout << "------------------------------" << endl;

                    cout << endl;
                }

                system ("pause");

                break ;


            }

            case 3: { // Listado de Proveedores

                system("cls") ;

                cout << endl << "Listado completo de proveedores (Activos e Inactivos)" << endl ;

                cout << "---------------------------------------------" << endl ;

                Proveedor nuevoProveedor ;

                int cantRegistros = archivoProveedor.getCantidadRegistros() ;

                if (cantRegistros == 0) {

                    cout << "No hay proveedores cargados en el sistema." << endl ;

                } else {

                    cout << "Cantidad total de proveedores: " << cantRegistros << endl ;

                    cout << "---------------------------------------------" << endl ;

                    for (int i = 0; i < cantRegistros; i++) {

                        nuevoProveedor = archivoProveedor.leer(i) ;

                        nuevoProveedor.mostrar() ;

                        cout << "---------------------------------------------" << endl ;
                    }
                }

                system("pause") ;

                break ;
            }


            case 4:  { // Listar Ventas

                system("cls") ;

                int cantidad = archivoVenta.getCantidadRegistros() ;

                if (cantidad == 0){

                    cout << "No hay ventas cargadas en el sistema." << endl ;

                    break ;
                }

                cout << "Listado de ventas" << endl ;

                cout << "---------------------------------------------" << endl ;

                cout << "Cantidad de registros: " << cantidad << endl ;

                for (int i=0; i<cantidad; i++){

                    Venta reg = archivoVenta.leer(i) ;

                    cout << "---------------------------------------------" << endl ;

                    reg.mostrarVenta() ;

                }

                cout << "---------------------------------------------" << endl ;

                system("pause") ;

                break ;
            }

            case 5:  { // listado productos

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

                        system("pause") ;

                break ; }
            }

            case 6: {

                system("cls") ;

                cout << "Listado de todos los envios" << endl ;

                cout << "-------------------------------" << endl ;

                int cantidad = archivoEnvio.getCantidadRegistros() ;

                if (cantidad == 0) { cout << "No hay envios cargados." << endl ; break ; }

                for (int i = 0; i < cantidad; i++) {

                    Envio reg = archivoEnvio.leer(i) ;

                    reg.mostrar() ;
                }

                system("pause") ;

                break ;
            }


            case 0:

                cout << endl ;

                cout << "Volviendo al menu anterior..." << endl ;

                break ;


            default:

                cout << "Opcion Invalida. Intente de nuevo." << endl ;

                break ;
        }

    } while (opcion != 0) ;

}
