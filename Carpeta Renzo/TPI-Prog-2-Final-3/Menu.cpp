#include "Menu.h"
#include <iostream>
#include "Persona.h"
#include "Empleado.h"
#include "Cliente.h"
#include "Proveedor.h"
#include "ProveedorArchivo.h"
#include "EmpleadoArchivo.h"


using namespace std ;


void Menu::mostrar()
{

    int opcion ;

    do
    {

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

        cout << endl ;


        switch (opcion)
        {

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

            subMenuReportes() ;

            break ;

        case 9:

            subMenuBackups ();

            break ;

        case 0:

            system ("cls");

            cout << "Saliendo del sistema... " << endl ;

            system ("pause");

            break ;

        default :

            system ("cls");

            cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl ;

            system("pause") ;

            break ;
        }

    }
    while (opcion != 0) ;
}


void Menu::subMenuABML_Clientes()
{

    ClienteArchivo reg ;

    int opcion ;

    do
    {


        system("cls") ;

        cout << "Menu de clientes" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Cargar cliente" << endl ;

        cout << "2. Dar de baja cliente" << endl ;

        cout << "3. Dar de alta un cliente" << endl ;

        cout << "4. Modificar cliente" << endl ;

        cout << "5. Modificar un campo especifico del cliente" << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al menu anterior" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl;

        switch (opcion)
        {

        case 1:
        {

            system("cls") ;

            cout << "Esta seguro de que desea cargar un nuevo cliente? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea cargar un nuevo cliente? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }

            cout << "Carga de Cliente" << endl ;

            cout << "-----------------------------------------" << endl ;

            ClienteArchivo reg ;

            Cliente nuevoCliente ;

            nuevoCliente.setID (reg.getCantidadRegistros () + 1);

            nuevoCliente.cargar () ;

            if (nuevoCliente.getTipo_Cliente() != 0)

            {



                if(reg.guardar(nuevoCliente))
                {
                    cout  << endl << "Cliente cargado con exito. " << endl ;
                }
                else
                {
                    cout << "El cliente no se pudo cargar" << endl ;
                }


            }



            system("pause") ;

            break ;
        }

        case 2:
        {

            system("cls") ;

            cout << "Eliminar un Cliente" << endl ;

            cout << "-----------------------------------------" << endl ;

            int id_persona ;

            cout << "Ingrese el ID del cliente que desee borrar: " ;

            cin >> id_persona ;

            cout << endl ;

            ClienteArchivo reg ;

            if (reg.bajaLogica(id_persona))
            {
                cout << "Cliente (ID " << id_persona << ") dado de baja." << endl ;
            }
            else
            {
                cout << "ERROR: No se pudo completar la baja." << endl ;

                cout << "Posibles razones: El ID " << id_persona << " no existe, o el cliente ya esta inactivo." << endl ;

            }

            system("pause") ;

            break ;

        }

        case 3:
        {

            system("cls") ;

            cout << "Dar de alta un Cliente" << endl ;

            cout << "-----------------------------------------" << endl ;

            int id_persona ;

            cout << "Ingrese el ID del cliente que desee dar de alta: " ;

            cin >> id_persona ;

            ClienteArchivo reg ;

            if (reg.altaLogica(id_persona))
            {

                cout << "Cliente (ID " << id_persona << ") dado de alta." << endl ;

            }
            else
            {

                cout << "ERROR: No se pudo completar la alta." << endl ;

                cout << "Posibles razones: El ID " << id_persona << " no existe, o el cliente ya esta activo." << endl ;

            }

            system("pause") ;

            break ;

        }

        case 4:
        {

            system("cls") ;

            cout << "Esta seguro de que desea modificar un cliente? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea modificar un cliente? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }


            cout << "Modificar un Cliente" << endl ;

            cout << "--------------------------------------------" << endl;

            int idBuscar ;

            cout << "Ingrese el ID del cliente a modificar: " ;

            cin >> idBuscar ;

            ClienteArchivo archivo ;

            Cliente reg ;

            int pos = archivo.buscarPosicion (idBuscar) ;

            if (pos == -1)
            {

                cout << "ERROR: No se encontro un cliente con ese ID. " << endl ;

            }
            else
            {

                reg = archivo.leer(pos) ;

                reg.mostrar() ;

                cout << "--------------------------------------------" << endl ;

                cout << "Ingrese los nuevos datos del cliente (el ID se mantendra): " << endl << endl ;

                reg.cargar() ;

                reg.setID(idBuscar) ;

                int opc;

                cout << "Esta seguro de que desea guardar los cambios? (1- Si, 2- No): ";

                cin >> opc;

                while (opc != 1 && opc != 2)
                {

                    cout << "La opcion que ingreso es invalida. Intentelo de nuevo. " << endl;

                    cout << "Esta seguro de que desea guardar los cambios? (1- Si, 2- No): ";

                    cin >> opc;

                }

                if (opc == 1)
                {

                    if (archivo.modificar(reg))
                    {

                        cout << endl << "Cliente modificado con exito. " << endl ;

                    }
                    else
                    {

                        cout << endl << "ERROR: No se pudo escribir la modificacion en el archivo. " << endl ;

                    }
                }
            }

            system("pause") ;

            break ;
        }

        case 5:
        {

            system ("cls");

            cout << "Esta seguro de que desea modificar campo(s) de un cliente? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea modificar campo(s) de un cliente? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }

            ClienteArchivo archivo;

            archivo.modificarCampo ();

            system ("pause");

            break;

        }

        case 0:
        {
            system("cls") ;

            cout << "Volviendo al menu anterior..." << endl ;

            system ("pause");

            break ;
        }

        default:

            system("cls") ;

            cout << "La opcion que ingreso es invalida. Intentelo de nuevo. " << endl;

            system ("pause");

            break ;
        }

    }
    while (opcion != 0) ;

}



void Menu::subMenuABML_Empleados()
{

    int opcion ;

    do
    {

        system("cls") ;

        cout << "Menu de empleados" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Cargar empleado" << endl ;

        cout << "2. Dar de baja empleado" << endl ;

        cout << "3. Dar de alta un empleado" << endl ;

        cout << "4. Modificar empleado" << endl ;

        cout << "5. Modificar un campo especifico del empleado" << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al menu anterior" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl ;


        switch (opcion)
        {

        case 1:
        {

            system("cls") ;

            cout << "Esta seguro de que desea cargar un nuevo empleado? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea cargar un nuevo empleado? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }

            cout << "Carga de Empleado" << endl ;

            cout << "-----------------------------------------" << endl ;

            EmpleadoArchivo reg;

            Empleado nuevoEmpleado ;

            nuevoEmpleado.setID (reg.getCantidadRegistros () + 1);

            nuevoEmpleado.cargar() ;

            if (nuevoEmpleado.getID_Puesto () != 0)
            {

                if(reg.guardar(nuevoEmpleado))
                {
                    cout  << endl << "Empleado cargado con exito. " << endl ;
                }
                else
                {
                    cout << "El empleado no se pudo cargar" << endl ;
                }

            }

            system("pause") ;

            break ;
        }

        case 2:
        {

            system("cls") ;

            cout << "Eliminar un Empleado" << endl ;

            cout << "-----------------------------------------" << endl ;

            int id_persona ;

            cout << "Ingrese el id del empleado que desee borrar: "  ;

            cin >> id_persona ;

            EmpleadoArchivo reg ;

            if (reg.bajaLogica(id_persona))
            {

                cout << endl << "Empleado (ID " << id_persona << ") dado de baja." << endl ;

            }
            else
            {

                cout << "ERROR: No se pudo completar la baja." << endl ;

                cout << "Posibles razones: El ID " << id_persona << " no existe, o el empleado ya esta inactivo." << endl ;
            }

            system("pause") ;

            break ;

        }

        case 3:
        {

            system("cls") ;

            cout << "Reactivar un Empleado" << endl ;

            cout << "-----------------------------------------" << endl ;

            int id_persona;

            cout << "Ingrese el id del empleado que desee reactivar: " ;

            cin >> id_persona ;

            EmpleadoArchivo reg ;

            if (reg.altaLogica(id_persona))
            {

                cout << endl << "Empleado (ID " << id_persona << ") dado de alta." << endl ;

            }
            else
            {

                cout << "ERROR: No se pudo completar el alta." << endl ;

                cout << "Posibles razones: El ID " << id_persona << " no existe, o el empleado ya esta activo." << endl ;
            }

            system("pause") ;

            break ;

        }

        case 4:
        {

            system("cls") ;

            cout << "Esta seguro de que desea modificar un empleado? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea modificar un empleado? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }


            cout << "Modificar un Empleado" << endl ;

            cout << "-----------------------------------------" << endl ;

            int idBuscar ;

            cout << "Ingrese el ID del empleado a modificar: " ;

            cin >> idBuscar ;

            cout << endl ;

            EmpleadoArchivo archivo;

            Empleado reg;

            int pos = archivo.buscarPosicion(idBuscar) ;

            if (pos == -1)
            {

                cout << "ERROR: No se encontro ningun empleado con ese ID. " << endl;

            }
            else
            {

                reg = archivo.leer(pos) ;

                reg.mostrar();

                cout << "--------------------------------------------" << endl ;

                cout << endl << "Ingrese los nuevos datos del empleado (el ID se mantendra):" << endl ;

                reg.cargar() ;

                reg.setID(idBuscar) ;

                int opc;

                cout << "Esta seguro de que desea guardar los cambios? (1- Si, 2- No): ";

                cin >> opc;

                while (opc != 1 && opc != 2)
                {

                    cout << "La opcion que ingreso es invalida. Intentelo de nuevo. " << endl;

                    cout << "Esta seguro de que desea guardar los cambios? (1- Si, 2- No): ";

                    cin >> opc;

                }

                if (opc == 1)
                {

                    if (archivo.modificar(reg))
                    {

                        cout << endl << "Empleado modificado con exito. " << endl ;

                    }
                    else
                    {

                        cout << endl << "ERROR: No se pudo escribir la modificacion en el archivo." << endl ;
                    }
                }

            }


            system("pause") ;

            break ;

        }

        case 5:
        {

            system ("cls");

            cout << "Esta seguro de que desea modificar campo(s) de un empleado? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea modificar campo(s) de un empleado? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }


            EmpleadoArchivo reg;

            reg.modificarCampo ();

            system ("pause");

            break;

        }


        case 0:
        {

            system("cls") ;

            cout << "Volviendo al menu anterior..." << endl ;

            system ("pause");

            break ;
        }

        default:

            system("cls") ;

            cout << "La opcion que ingreso es invalida. Intentelo de nuevo. " << endl ;

            system ("pause");

            break ;
        }

    }
    while (opcion != 0) ;

}


void Menu::subMenuABML_Proveedores()
{

    int opcion ;

    do
    {

        system("cls") ;

        cout << "Menu de proveedores" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Cargar proveedor" << endl ;

        cout << "2. Dar de baja proveedor" << endl ;

        cout << "3. Dar de alta un proveedor" << endl ;

        cout << "4. Modificar proveedor" << endl ;

        cout << "5. Modificar un campo especifico del proveedor" << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al menu anterior" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cout << endl ;

        cin >> opcion ;


        switch (opcion)
        {

        case 1:
        {

            system("cls") ;

            cout << "Esta seguro de que desea cargar un nuevo proveedor? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea cargar un nuevo proveedor? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }

            cout << "Carga de Proveedor" << endl ;

            cout << "-----------------------------------------" << endl ;

            ProveedorArchivo reg;

            Proveedor nuevoProveedor ;

            nuevoProveedor.setID (reg.getCantidadRegistros () + 1);

            nuevoProveedor.cargar() ;


            if (nuevoProveedor.getTipo_proveedor () != 0)
            {

                if(reg.guardar(nuevoProveedor))
                {
                    cout  << endl << "Proveedor cargado con exito. " << endl ;
                }
                else
                {
                    cout << "El proveedor no se pudo cargar" << endl ;
                }



            }

            system("pause") ;

            break ;
        }

        case 2:
        {

            system("cls") ;

            cout << "Eliminar un Proveedor" << endl ;

            cout << "-----------------------------------------" << endl ;

            int id_proveedor ;

            cout << "Ingrese el ID del proveedor a dar de baja: " ;

            cin >> id_proveedor ;

            ProveedorArchivo archivo ;

            if (archivo.bajaLogica(id_proveedor))
            {
                cout << "Proveedor (ID " << id_proveedor << ") dado de baja." << endl ;
            }
            else
            {
                cout << "ERROR: No se pudo completar la baja." << endl ;

                cout << "Posibles razones: El ID " << id_proveedor << " no existe, o el proveedor ya esta inactivo." << endl ;

            }

            system("pause") ;

            break ;



        }

        case 3:
        {

            system("cls") ;

            cout << "Dar de alta a un Proveedor" << endl ;

            cout << "-----------------------------------------" << endl ;

            int id_proveedor ;

            cout << "Ingrese el ID del proveedor a dar de alta: " ;

            cin >> id_proveedor ;

            ProveedorArchivo archivo ;

            if (archivo.altaLogica(id_proveedor))
            {
                cout << "Proveedor (ID " << id_proveedor << ") dado de alta." << endl ;
            }
            else
            {
                cout << "ERROR: No se pudo completar la baja." << endl ;

                cout << "Posibles razones: El ID " << id_proveedor << " no existe, o el proveedor ya esta activo." << endl ;

            }

            system("pause") ;

            break ;



        }

        case 4:
        {

            system("cls") ;

            cout << "Esta seguro de que desea modificar un proveedor? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea modificar un proveedor? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }


            cout << "Modificar un Proveedor" << endl ;

            cout << "--------------------------------------------" << endl;

            int idBuscar ;

            cout << "Ingrese el ID del proveedor a modificar: " ;

            cin >> idBuscar ;

            ProveedorArchivo archivo ;

            Proveedor reg ;

            int pos = archivo.buscarPosicion(idBuscar) ;

            if (pos == -1)
            {

                cout << "ERROR: No se encontro un proveedor con ese ID. " << endl ;

                system("pause") ;

            }
            else
            {

                reg = archivo.leer(pos) ;

                reg.mostrar() ;

                cout << "--------------------------------------------" << endl ;

                cout << endl << "Ingrese los nuevos datos del proveedor (el ID se mantendra): " << endl << endl ;

                reg.cargar() ;

                reg.setID(idBuscar) ;

                int opc;

                cout << "Esta seguro de que desea guardar los cambios? (1- Si, 2- No): ";

                cin >> opc;

                while (opc != 1 && opc != 2)
                {

                    cout << "La opcion que ingreso es invalida. Intentelo de nuevo. " << endl;

                    cout << "Esta seguro de que desea guardar los cambios? (1- Si, 2- No): ";

                    cin >> opc;

                }

                if (opc == 1)
                {

                    if (archivo.modificar(reg))
                    {

                        cout << endl << "Proveedor modificado con exito. " << endl ;

                    }
                    else
                    {

                        cout << endl << "ERROR: No se pudo escribir la modificacion en el archivo. " << endl ;

                    }


                }

            }

            system("pause") ;

            break ;
        }



        case 5:
        {

            system ("cls");

            cout << "Esta seguro de que desea modificar campo(s) de un proveedor? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea modificar campo(s) un proveedor? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }


            ProveedorArchivo reg;

            reg.modificarCampo ();

            system ("pause");

            break;

        }


        case 0:
        {

            system("cls") ;

            cout << "Volviendo al menu anterior..." << endl ;

            system ("pause");

            break ;
        }

        default:

            system("cls") ;

            cout << "Opcion Invalida. Intente de nuevo." << endl ;

            system ("pause");

            break ;
        }

    }
    while (opcion != 0) ;

}

void Menu::subMenuABML_Productos()
{

    int opcion  ;

    ProductoArchivo archivo1 ;

    do
    {

        system("cls") ;

        cout << "Menu productos" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "1. Cargar producto" << endl ;

        cout << "2. Dar de baja un producto" << endl ;

        cout << "3. Dar de alta un producto" << endl ;

        cout << "4. Modificar producto (por ID)" << endl ;

        cout << "5. Modificar un campo especifico del producto" << endl ;


        cout << "--------------------------------------------" << endl ;

        cout << "0. Volver al menu anterior" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        switch (opcion)
        {

        case 1:
        {

            system("cls") ;

            cout << "Esta seguro de que desea cargar un nuevo producto? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea cargar un nuevo producto? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }

            cout << "Carga de producto" << endl ;

            cout << "--------------------------------------------" << endl ;

            Producto producto1 ;

            int nuevoID = archivo1.obtenerID() ;

            producto1.setID_Producto(nuevoID) ;

            cout << "ID de Producto: " << nuevoID << " (Autogenerado)" << endl;

            producto1.cargar();

            system("pause") ;

            break ;

        }


        case 2:
        {



            system("cls") ;

            int idBaja ;

            cout << "Dar de baja un producto" << endl ;

            cout << "--------------------------------------------" << endl ;

            cout << "Ingrese el ID del producto a dar de baja: " ;

            cin >> idBaja ;

            cout << endl ;

            if (archivo1.bajaLogica(idBaja))
            {

                cout << "Producto (ID " << idBaja << ") dado de baja." << endl ;

            }
            else
            {

                cout << "ERROR: No se pudo completar la baja." << endl ;

                cout << "Posibles razones: El ID " << idBaja << " no existe, o el producto ya esta inactivo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 3:
        {


            system("cls") ;

            int idAlta ;

            cout << "Dar de alta un producto" << endl ;

            cout << "--------------------------------------------" << endl ;

            cout << "Ingrese el ID del producto a dar de alta: " ;

            cin >> idAlta ;

            cout << endl ;

            if (archivo1.altaLogica(idAlta))
            {

                cout << "Producto (ID " << idAlta << ") dado de alta." << endl ;

            }
            else
            {

                cout << "ERROR: No se pudo completar la alta." << endl ;

                cout << "Posibles razones: El ID " << idAlta << " no existe, o el producto ya esta activo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 4:
        {

            system("cls") ;

            cout << "Esta seguro de que desea modificar un producto? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea modificar un producto? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }

            int idBuscar ;

            cout << "Modificar producto" << endl ;

            cout << "--------------------------------------------" << endl ;

            cout << "Ingrese el ID del producto a modificar: " ;

            cin >> idBuscar ;

            cout << endl ;

            int pos = archivo1.buscarPosicion(idBuscar) ;

            if (pos == -1)
            {

                cout << "ERROR: No se encontro ningun producto con ID " << idBuscar << endl ;

            }
            else
            {

                Producto regModificar = archivo1.leer(pos) ;

                cout << "Producto Actual (ID " << idBuscar << ")" << endl ;

                regModificar.mostrar() ;

                cout << "--------------------------------------------" << endl ;

                cout << "Ingrese los nuevos datos del producto (el ID se mantendra):" << endl ;

                regModificar.cargar() ;

                regModificar.setID_Producto(idBuscar) ;

                if (archivo1.modificar(regModificar))
                {

                    cout << endl << "Producto (ID " << idBuscar << ") modificado con exito." << endl ;

                }
                else
                {

                    cout << endl << "ERROR: No se pudo escribir la modificacion en el archivo." << endl ;
                }
            }

            system("pause") ;

            break;
        }

        case 5:
        {

            system("cls") ;

            cout << "Esta seguro de que desea modificar campo(s) de un producto? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea modificar campo(s) de un producto? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }

            ProductoArchivo reg;

            reg.modificarCampos ();

            system("pause") ;

            break ;

        }




        case 0:

            system ("cls");

            cout << "Volviendo al menu anterior..." << endl ;

            system ("pause");

            break ;

        default:

            system ("cls");

            cout << "La opcion que ingreso en invalida. Intentelo de nuevo. " << endl ;

            system ("pause");

            break ;
        }

    }
    while (opcion != 0) ;
}

void Menu::subMenuABML_Ventas()
{

    int opcion ;

    VentaArchivo archivoVenta ;

    EnvioArchivo archivoEnvio ;

    DetalleVentaArchivo archivoDetalleVenta;

    ProductoArchivo archivoP;

    do
    {

        system("cls") ;

        cout << "Menu Ventas" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "1. Cargar venta" << endl ;

        cout << "2. Dar de baja una venta" << endl ;

        cout << "3. Dar de alta una venta" << endl ;

        cout << "4. Modificar venta" << endl ;

        cout << "5. Modificar un campo especifico de una venta" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "0. Volver al menu anterior" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl ;


        switch (opcion)
        {

        case 1:
        {

            system("cls") ;

            cout << "Esta seguro de que desea cargar una nueva venta? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea cargar una nueva venta? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }

            cout<< "Carga de Venta" << endl ;

            cout << "--------------------------------------------------------------" << endl ;

            Venta nuevaVenta ;

            int nuevoID = archivoVenta.obtenerID() ;

            nuevaVenta.setID_Venta(nuevoID) ;

            cout << "ID de Venta: " << nuevoID << endl ;

            nuevaVenta.cargarVenta() ;

            if (nuevaVenta.getMontoTotal () != 0.0)
            {

                if(archivoVenta.guardar(nuevaVenta))
                {

                    cout << endl << "Venta cargada con exito (ID: "<< nuevoID <<")." << endl ;

                    if (nuevaVenta.getTipoEnvio() == 1 )
                    {

                        cout << "--------------------------------------------------------------" << endl ;

                        cout << "Creando registro de envio..." << endl ;

                        Envio nuevoEnvio ;

                        int nuevoID_Envio = archivoEnvio.obtenerID() ;

                        nuevoEnvio.setID_Envio(nuevoID_Envio) ;

                        nuevoEnvio.setID_Venta(nuevoID) ;

                        nuevoEnvio.cargar() ;

                        if(nuevaVenta.getMontoTotal() > 50000)
                        {

                            nuevoEnvio.setValor_Envio(0.0) ;

                            cout << "El envio no se cobra porque la compra supero los $50000" << endl ;

                        }

                        nuevaVenta.setMontoTotal(nuevaVenta.getSubTotal() + nuevoEnvio.getValor_Envio()) ;

                        archivoVenta.modificar (nuevaVenta) ;

                        if (archivoEnvio.guardar(nuevoEnvio))
                        {


                            cout << "Envio cargado con exito (ID_Envio: " << nuevoID_Envio << ")." << endl ;

                            cout << endl << "-----------------------------------------------------------------------"  ;

                            cout << endl  << "MONTO TOTAL CON ENVIO INCLUIDO $: " << nuevaVenta.getMontoTotal()  << endl ;



                            cout << "-----------------------------------------------------------------------" << endl ;

                        }
                        else
                        {

                            cout << "ERROR: No se pudo guardar el Envio." << endl;
                        }

                    }
                    else
                    {

                        cout << "La venta no requiere cargar registro de envio porque se retira por el local" << endl ;
                    }

                }
                else
                {

                    cout << "No se pudo guardar la venta en el archivo." << endl ;
                }



            }

            system ("pause");

            break ;
        }


        case 2:

        {

            system("cls") ;

            int idBaja ;

            cout << "Anular una venta" << endl ;

            cout << "--------------------------------------------" << endl ;

            cout << "Ingrese el ID de la venta a dar de baja: " ;

            cin >> idBaja ;

            cout << endl ;

            archivoDetalleVenta.bajaLogica(idBaja);

            if(archivoVenta.bajaLogica(idBaja))
            {

                cout << "Venta (ID " << idBaja << ") dada de baja." << endl ;

            }
            else
            {

                cout << "ERROR: No se pudo completar la baja." << endl ;

                cout << "Posibles razones: El ID " << idBaja << " no existe, o la venta ya estaba dada de baja." << endl ;
            }

            system ("pause");

            break ;
        }

        case 3:
        {

            system("cls") ;

            int idAlta ;

            cout << "Dar de alta una venta" << endl ;

            cout << "--------------------------------------------" << endl ;

            cout << "Ingrese el ID de la venta a dar de alta: " ;

            cin >> idAlta ;

            cout << endl ;

            archivoVenta.altaLogica(idAlta) ;

            if(archivoVenta.altaLogica(idAlta))
            {

                cout << "Venta (ID " << idAlta << ") dada de alta." << endl ;

            }
            else
            {

                cout << "ERROR: No se pudo completar el alta." << endl ;

                cout << "Posibles razones: El ID " << idAlta << " no existe, o la venta ya estaba activa." << endl ;
            }

            system ("pause");

            break ;
        }



        case 4:
        {

            system("cls")  ;

            cout << "Esta seguro de que desea modificar una venta? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea modificar una venta? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }


            int idBuscar ;

            cout << "Modificar una Venta" << endl ;

            cout << "--------------------------------------------------------------" << endl ;

            cout << "Ingrese el ID de la Venta a modificar: " ;

            cin >> idBuscar ;

            cout << endl ;

            int pos = archivoVenta.buscarPosicion(idBuscar) ;

            if(pos == -1)
            {

                cout << "ERROR: No se encontro ninguna Venta con ID "<< idBuscar << endl ;

            }
            else
            {

                Venta regModificar = archivoVenta.leer(pos) ;

                Producto regP = archivoP.leer(pos) ;

                Detalle_Venta detalle2 = archivoDetalleVenta.leer(pos) ;

                int nuevo_stock = regP.getCantStock() + detalle2.getCantidad() ;

                regP.setCantidadStock(nuevo_stock) ;

                archivoP.modificar(regP) ;

                cout << endl ;

                cout << "Venta Actual: " << endl ;

                cout << "--------------------------------------------------------------" << endl ;

                regModificar.mostrarVenta() ;

                cout << "--------------------------------------------------------------" << endl ;

                cout << "Ingrese los nuevos datos de la venta (el ID se mantendra):" << endl ;

                bool envioAnterior ;

                if(regModificar.getTipoEnvio() == 1)
                {

                    envioAnterior = true ;

                }
                else
                {

                    envioAnterior = false ;

                }

                regModificar.cargarVenta() ;

                cout << endl << "--------------------------------------------------------------" << endl ;

                cout << endl << "Nueva informacion de la venta: " << endl ;

                regModificar.mostrarVenta() ;

                cout << endl ;

                system("pause") ;


                regModificar.setID_Venta(idBuscar) ;



                if(archivoVenta.modificar(regModificar))

                {

                    cout << endl << "Venta (ID "<< idBuscar << ") modificada con exito." << endl ;

                }

                else
                {

                    cout << endl << "ERROR: No se pudo escribir la modificacion en el archivo." << endl ;
                }


                if(regModificar.getTipoEnvio() == 1)
                {

                    Envio nuevo_envio ;

                    cout << endl <<  "Ha seleccionado envio a domicilio, cargue los siguientes datos: "  ;


                    if(envioAnterior == true)
                    {



                        system("cls") ;

                        int pos = archivoEnvio.buscarPosicionPorID_Venta(nuevo_envio.getID_Venta()) ;

                        archivoEnvio.leer(pos) ;

                        cout << endl ;

                        nuevo_envio = archivoEnvio.leer(pos) ;


                        nuevo_envio.setID_Venta(regModificar.getID_Venta()) ;

                        nuevo_envio.cargar() ;


                        nuevo_envio.setID_Envio(idBuscar) ;

                        if (archivoEnvio.modificar(nuevo_envio))
                        {

                            cout << "Envio (ID " << idBuscar << ") modificado con exito." << endl ;

                        }

                        else
                        {

                            cout << "ERROR al modificar el registro." << endl ;
                        }


                    }

                    else if (envioAnterior == false)

                    {


                        nuevo_envio.setID_Venta(regModificar.getID_Venta()) ;

                        nuevo_envio.cargar() ;

                        nuevo_envio.setID_Envio(archivoEnvio.getCantidadRegistros()+1) ;

                        archivoEnvio.guardar(nuevo_envio) ;


                    }

                }
            }



            system ("pause");


            break ;
        }

        case 5:
        {

            system("cls") ;

            cout << "Esta seguro de que desea modificar campo(s) de una venta? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea modificar campo(s) de una venta? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }


            VentaArchivo archivoVenta1 ;

            archivoVenta1.modificarCampos() ;

            system ("pause");

            break ;



        }


        case 0:
        {

            system ("cls");

            cout << "Volviendo al menu anterior..." << endl ;

            system ("pause");

            break ;
        }

        default:

            system ("cls");

            cout << "La opcion que ingreso es invalida. Intentelo de nuevo. " << endl ;

            system ("pause");

            break ;
        }

    }
    while (opcion != 0) ;
}


void Menu::subMenuABML_Envios()
{

    int opcion ;

    EnvioArchivo archivoEnvio ;

    do
    {

        system("cls") ;

        cout << "Menu envios" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "1. Dar de baja un envio" << endl ;

        cout << "2. Dar de alta un envio" << endl ;

        cout << "3. Modificar un envio" << endl ;

        cout << "4. Modificar un campo especifico del envio" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "0. Volver al menu anterior" << endl ;

        cout << "--------------------------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl ;


        switch (opcion)
        {

        case 1:
        {

            system("cls") ;

            int idBaja ;

            cout << "Dar de baja un envio" << endl ;

            cout << "Ingrese el ID de Envio a dar de baja: " ;

            cin >> idBaja ;

            if (archivoEnvio.bajaLogica(idBaja))
            {

                cout << "Envio (ID " << idBaja << ") dado de baja." << endl ;

            }
            else
            {

                cout << "ERROR: No se pudo dar de baja el envio." << endl ;

                cout << "Posibles razones: El ID " << idBaja << " no existe, o el envio ya esta dado de baja." << endl ;
            }

            system ("pause");

            break ;
        }

        case 2:
        {

            system("cls") ;

            int idAlta ;

            cout << "Dar de alta un envio" << endl ;

            cout << "Ingrese el ID de envio a dar de alta: " ;

            cin >> idAlta ;

            if (archivoEnvio.altaLogica(idAlta))
            {

                cout << "Envio (ID " << idAlta << ") dado de alta." << endl ;

            }
            else
            {

                cout << "ERROR: No se pudo dar de alta el envio." << endl ;

                cout << "Posibles razones: El ID " << idAlta << " no existe, o el envio ya esta activo." << endl ;
            }

            system ("pause");

            break ;
        }

        case 3:
        {

            system("cls") ;

            cout << "Esta seguro de que desea modificar un envio? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea modificar un envio? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }


            int idBuscar ;

            cout << "Modificar envio" << endl ;

            cout << "--------------------------------------------------------------" << endl ;

            cout << "Ingrese el ID de envio a modificar: " ;

            cin >> idBuscar ;

            cout << endl ;

            int pos = archivoEnvio.buscarPosicion(idBuscar) ;

            if (pos == -1)
            {

                cout << "No se encontro envio con ID " << idBuscar << endl ;

                break ;
            }

            Envio regModificar = archivoEnvio.leer(pos) ;

            regModificar.mostrar() ;

            cout << endl << endl << "Ingrese los nuevos datos del envio: " << endl ;

            regModificar.cargar() ;

            regModificar.setID_Envio(idBuscar) ;

            if (archivoEnvio.modificar(regModificar))
            {

                cout << "Envio (ID " << idBuscar << ") modificado con exito." << endl ;

            }
            else
            {

                cout << "ERROR al modificar el registro." << endl ;
            }

            system ("pause");

            break ;
        }

        case 4:
        {

            system("cls") ;

            cout << "Esta seguro de que desea modificar campo(s) de un envio? (1- Si, 2- No): " << endl;

            cin >> opcion;

            while (opcion != 1 && opcion != 2)
            {

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Esta seguro de que desea modificar campo(s) de un envio? (1- Si, 2- No): " << endl;

                cin >> opcion;

            }

            if (opcion == 2)
            {
                break;
            }
            else
            {
                system("cls");
            }


            EnvioArchivo envio1 ;

            envio1.modificarCampos() ;

            system ("pause");

            break ;



        }

        case 0:
        {

            system ("cls");

            cout << "Volviendo al menu anterior..." << endl ;

            system ("pause");

            break ;
        }

        default:

            system ("cls");

            cout << "La opcion que ingreso es invalida. Intentelo de nuevo. " << endl ;

            system ("pause");

            break ;
        }

    }
    while (opcion != 0);
}


void Menu::subMenuABML_Listados()
{

    int opcion ;

    ProductoArchivo archivo1 ;

    VentaArchivo archivoVenta ;

    EnvioArchivo archivoEnvio ;

    ProveedorArchivo archivoProveedor ;

    DetalleVentaArchivo archivoDetalle ;

    do
    {


        system("cls") ;

        cout << "Menu de listados" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Listado de Clientes" << endl ;

        cout << "2. Listado de Proveedores" << endl ;

        cout << "3. Listado de Empleados" << endl ;

        cout << "4. Listado de Productos" << endl ;

        cout << "5. Listado de Ventas" << endl ;

        cout << "6. Listado de Detalle de Ventas" << endl ;

        cout << "7. Listado de Envios" << endl ;

        cout << "8. Listado de Activos" << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al menu anterior" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;


        switch (opcion)
        {

        case 1:
        {

            system("cls") ;

            cout << "Listado de Clientes" << endl ;

            cout << "-------------------------------------------------------------------" << endl ;

            Cliente nuevoCliente;

            ClienteArchivo reg;

            int cantRegistros = reg.getCantidadRegistros();

            if (cantRegistros <= 0)
            {

                cout << "Error. No hay clientes cargados en el sistema" << endl ;


            }

            for (int i = 0; i<cantRegistros; i++)
            {


                nuevoCliente = reg.leer(i) ;

                nuevoCliente.mostrar() ;

                cout << "-------------------------------------------------------------------" << endl ;


            }

            system("pause") ;

            break ;
        }

        case 2:
        {

            system("cls") ;

            cout  << "Listado completo de proveedores (Activos e Inactivos)" << endl ;

            cout << "-------------------------------------------------------------------" << endl ;

            Proveedor nuevoProveedor ;

            int cantRegistros = archivoProveedor.getCantidadRegistros() ;

            if (cantRegistros <= 0)
            {

                cout << "Error. No hay proveedores cargados en el sistema" << endl ;


            }

            else

            {

                cout << "Cantidad total de proveedores: " << cantRegistros << endl ;

                cout << "-------------------------------------------------------------------" << endl ;

                for (int i = 0; i < cantRegistros; i++)
                {

                    nuevoProveedor = archivoProveedor.leer(i) ;

                    nuevoProveedor.mostrar() ;

                    cout << "-------------------------------------------------------------------" << endl ;
                }
            }

            system("pause") ;

            break ;
        }

        case 3:
        {

            system ("cls") ;

            cout << "Listado de Empleados" << endl ;

            cout << "-------------------------------------------------------------------" << endl ;

            Empleado nuevoEmpleado ;

            EmpleadoArchivo reg ;

            int cantRegistros = reg.getCantidadRegistros() ;

            if (cantRegistros <= 0)
            {

                cout << "Error. No hay empleados cargados en el sistema" << endl ;
            }

            for (int i = 0; i<cantRegistros; i++)
            {
                cout << endl;

                cout << "-------------------------------------------------------------------" << endl ;

                nuevoEmpleado = reg.leer (i);

                nuevoEmpleado.mostrar ();

                cout << "-------------------------------------------------------------------" << endl ;

                cout << endl;
            }

            system ("pause");

            break ;


        }

        case 4 :
        {

            system("cls") ;

            cout << "Listado de productos" << endl ;

            cout << "-------------------------------------------------------------------" << endl ;

            int cantidad = archivo1.getCantidadRegistros() ;

            if (cantidad == 0)
            {

                cout << "Error. No hay productos cargados en el sistema." << endl ;

                system("pause") ;

                break ;

            }
            else
            {

                cout << "Cantidad de registros: " << cantidad << endl ;

                for (int i = 0; i < cantidad; i++)
                {

                    Producto reg = archivo1.leer(i) ;

                    cout << "-------------------------------------------------------------------" << endl ;

                    reg.mostrar() ;

                }

                cout << "---------------------------------------------" << endl ;

                system("pause") ;

                break ;
            }
        }


        case 5:
        {

            system("cls") ;

            cout << "Listado de ventas" << endl ;

            cout << "-------------------------------------------------------------------" << endl ;

            int cantidad = archivoVenta.getCantidadRegistros() ;

            if (cantidad == 0)
            {

                cout << endl << "Error. No hay ventas cargadas en el sistema." << endl ;

                system("pause") ;

                break ;
            }



            cout << "Cantidad de registros: " << cantidad << endl ;

            for (int i=0; i<cantidad; i++)
            {

                Venta reg = archivoVenta.leer(i) ;

                cout << "-------------------------------------------------------------------" << endl ;

                reg.mostrarVenta() ;

            }

            cout << "-------------------------------------------------------------------" << endl ;

            system("pause") ;

            break ;
        }

        case 6:
        {
            system("cls") ;

            cout << "Listado de Detalle de Ventas" << endl ;

            cout << "-------------------------------------------------------------------" << endl ;

            int cantidad = archivoDetalle.getCantidadRegistros() ;


            if (cantidad == 0)
            {

                cout << endl << "Error. No hay detalles de ventas cargados en el sistema." << endl ;

                system("pause") ;

                break ;

            }
            else
            {



                cout << "Cantidad de registros: " << cantidad << endl ;

                for (int i = 0; i < cantidad; i++)
                {

                    Detalle_Venta reg = archivoDetalle.leer(i) ;

                    cout << "-------------------------------------------------------------------" << endl ;

                    reg.mostrar() ;

                }

                cout << "-------------------------------------------------------------------" << endl ;

                system("pause") ;

                break ;
            }



        }



        case 7:
        {

            system("cls") ;

            cout << "Listado de todos los envios" << endl ;

            cout << "-------------------------------------------------------------------" << endl ;

            int cantidad = archivoEnvio.getCantidadRegistros() ;

            if (cantidad == 0)
            {
                cout << "Error. No hay envios cargados dn el sistema." << endl ;

                system("pause") ;

                break ;
            }

            for (int i = 0; i < cantidad; i++)
            {

                Envio reg = archivoEnvio.leer(i) ;

                reg.mostrar() ;
            }

            system("pause") ;


            break ;
        }

        case 8:
        {

            system ("cls") ;

            subMenuABML_Listados_Activos() ;


        }


        case 0:

            system ("cls");

            cout << "Volviendo al menu anterior..." << endl ;

            system("pause") ;

            break ;


        default:

            system ("cls");

            cout << "La opcion que ingreso es invalida. Intentelo de nuevo. " << endl ;

            system("pause") ;

            break ;
        }

    }
    while (opcion != 0) ;

}


void Menu::subMenuABML_Listados_Activos()
{

    int opcion ;

    ProductoArchivo archivo1 ;

    VentaArchivo archivoVenta ;

    EnvioArchivo archivoEnvio ;

    ProveedorArchivo archivoProveedor ;

    DetalleVentaArchivo archivoDealleVenta;

    do
    {


        system("cls") ;

        cout << "Menu de listados Activos" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Listado de clientes activos" << endl ;

        cout << "2. Listado de proveedores activos" << endl ;

        cout << "3. Listado de empleados activos" << endl ;

        cout << "4. Listado de productos activos" << endl ;

        cout << "5. Listado de ventas activas" << endl ;

        cout << "6. Listado de detalle de ventas activas" << endl ;

        cout << "7. Listado de envios activos" << endl ;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al menu anterior" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;


        switch (opcion)
        {

        case 1:
        {

            system("cls") ;

            cout << "Listado de clientes activos" << endl ;

            cout << "-------------------------------------------------------------------" << endl ;

            Cliente nuevoCliente;

            ClienteArchivo reg;

            int cantRegistros = reg.getCantidadRegistros();

            if (cantRegistros == 0)
            {

                cout << "No hay clientes activos cargados en el sistema." << endl ;

            }

            for (int i = 0; i<cantRegistros; i++)
            {

                nuevoCliente = reg.leer(i) ;

                if(nuevoCliente.getEstado() == true)
                {

                    nuevoCliente.mostrar() ;

                    cout << "--------------------------" << endl ;
                }

            }

            system("pause") ;

            break ;
        }



        case 2:
        {

            system("cls") ;

            cout << "Listado de proveedores activos" << endl ;

            cout << "-------------------------------------------------------------------" << endl ;

            Proveedor nuevoProveedor ;

            int cantRegistros = archivoProveedor.getCantidadRegistros() ;

            if (cantRegistros == 0)
            {

                cout << "No hay proveedores activos cargados en el sistema." << endl ;

            }
            else
            {

                cout << "Cantidad total de proveedores: " << cantRegistros << endl ;

                cout << "---------------------------------------------" << endl ;

                for (int i = 0; i < cantRegistros; i++)
                {

                    nuevoProveedor = archivoProveedor.leer(i) ;

                    if(nuevoProveedor.getEstado() == true)
                    {

                        nuevoProveedor.mostrar() ;

                        cout << "---------------------------------------------" << endl ;
                    }
                }
            }

            system("pause") ;

            break ;
        }

        case 3:
        {

            system ("cls") ;

            cout << "Listado de empleados activos" << endl ;

            cout << "-------------------------------------------------------------------" << endl ;

            Empleado nuevoEmpleado ;

            EmpleadoArchivo reg ;

            int cantRegistros = reg.getCantidadRegistros();

            if (cantRegistros <= 0)
            {
                cout << "No hay empleados activos cargados en el sistema" << endl ;
            }

            for (int i = 0; i<cantRegistros; i++)
            {

                cout << endl;

                cout << "------------------------------" << endl;

                nuevoEmpleado = reg.leer (i);

                if(nuevoEmpleado.getEstado() == true)
                {
                    nuevoEmpleado.mostrar ();
                }

                cout << "------------------------------" << endl;

                cout << endl;
            }

            system ("pause");

            break ;


        }

        case 4:
        {

            system("cls") ;

            cout << "Listado de productos activos" << endl ;

            cout << "-------------------------------------------------------------------" << endl ;

            int cantidad = archivo1.getCantidadRegistros() ;

            if (cantidad == 0)
            {

                cout << "No hay productos cargados en el sistema." << endl ;

                system("pause") ;

                break ;

            }
            else
            {



                cout << "Cantidad de registros: " << cantidad << endl ;

                for (int i = 0; i < cantidad; i++)
                {

                    Producto reg = archivo1.leer(i) ;
                    if(reg.getEstado() == true)
                    {

                        cout << "---------------------------------------------" << endl ;

                        reg.mostrar() ;

                    }

                }

                cout << "---------------------------------------------" << endl ;

                system("pause") ;

                break ;
            }
        }


        case 5:
        {

            system("cls") ;

            cout << "Listado de todas las ventas activas" << endl ;

            cout << "-------------------------------------------------------------------" << endl ;

            int cantidad = archivoVenta.getCantidadRegistros() ;

            if (cantidad == 0)
            {

                cout << endl << "No hay ventas activas cargadas en el sistema." << endl ;

                system("pause") ;

                break ;
            }

            cout << "Cantidad de registros: " << cantidad << endl ;

            for (int i=0; i<cantidad; i++)
            {

                Venta reg = archivoVenta.leer(i) ;

                if(reg.getEstado() == true)
                {

                    cout << "---------------------------------------------" << endl ;

                    reg.mostrarVenta() ;


                }

            }

            cout << "---------------------------------------------" << endl ;

            system("pause") ;

            break ;
        }


        case 6:
        {
            system("cls") ;

            cout << "Listado de todas los Detalles de las ventas activas" << endl ;

            cout << "-------------------------------------------------------------------" << endl ;

            int cantidad = archivoDealleVenta.getCantidadRegistros() ;

            if (cantidad == 0)
            {

                cout << endl << "No hay detalles de ventas activas cargadas en el sistema." << endl ;

                system("pause") ;

                break ;
            }



            cout << "Cantidad de registros: " << cantidad << endl ;

            for (int i=0; i<cantidad; i++)
            {

                Detalle_Venta reg = archivoDealleVenta.leer(i) ;

                if(reg.getEstado() == true)
                {

                    cout << "---------------------------------------------" << endl ;

                    reg.mostrar() ;


                }

            }

            cout << "---------------------------------------------" << endl ;

            system("pause") ;

            break ;



        }



        case 7:
        {

            system("cls") ;

            cout << "Listado de todos los envios activos" << endl ;

            cout << "-------------------------------------------------------------------" << endl ;

            int cantidad = archivoEnvio.getCantidadRegistros() ;

            if (cantidad == 0)
            {
                cout << "No hay envios activos cargados." << endl ;

                system("pause") ;

                break ;
            }

            for (int i = 0; i < cantidad; i++)
            {

                Envio reg = archivoEnvio.leer(i) ;

                if(reg.getEstado()== true)
                {

                    reg.mostrar() ;

                }

            }

            system("pause") ;

            break ;
        }


        case 0:

            system ("cls");

            cout << "Volviendo al menu anterior..." << endl ;

            break ;


        default:

            system ("cls");

            cout << "La opcion que ingreso es invalida. Intentelo de nuevo. " << endl ;

            system("pause") ;

            break ;
        }

    }
    while (opcion != 0) ;

}


void Menu::subMenuReportes()
{

    int opcion ;

    VentaArchivo archivoVenta ;

    int anio;

    do
    {

        system("cls") ;

        cout << "Menu de reportes" << endl ;

        cout << "--------------------------" << endl ;

        cout << "1. Recaudacion por cliente" << endl;

        cout << "2. Empleados ordenados por horas de trabajo semanales" << endl;

        cout << "3. Cantidad de unidades vendidas por marca" << endl;

        cout << "4. Cantidad de ventas por medio de pago" << endl;

        cout << "5. Recaudacion detallada por anio" << endl;

        cout << "6. Recaudacion historica por producto" << endl;

        cout << "7. Recaudacion historica por tipo de producto" << endl;

        cout << "--------------------------" << endl ;

        cout << "0. Volver al menu principal" << endl ;

        cout << "--------------------------" << endl ;

        cout << "Ingrese una opcion: " ;

        cin >> opcion ;

        cout << endl ;

        switch (opcion)
        {

        case 1:
        {

            system ("cls");

            VentaArchivo reg;

            reg.calcularRecaudacionPorCliente();

            system("pause") ;

            break ;
        }
        case 2:
        {

            system ("cls");

            EmpleadoArchivo reg;

            reg.calcularEmpleadosConMasHoras();

            system("pause") ;

            break;
        }

        case 3:
        {

            system ("cls");

            DetalleVentaArchivo archivoDetalle;

            archivoDetalle.reportePorMarca ();

            system("pause") ;

            break;
        }

        case 4:
        {

            system ("cls");

            VentaArchivo venta;

            venta.reporteCantidadPorMedioPago ();

            system("pause") ;

            break;

        }

        case 5:
        {

            system ("cls");

            VentaArchivo archivoVenta ;

            cout << "Ingrese el anio a consultar: " ;

            cin >> anio ;

            system("cls") ;

            archivoVenta.calcularRecaudacion(anio) ;

            system("pause") ;

            break ;
        }

        case 6:
        {

            system ("cls");

            DetalleVentaArchivo reg;

            reg.generarReporteRecaudacionPorProducto ();

            system ("pause");

            break;

        }

        case 7:
        {

            system ("cls");

            DetalleVentaArchivo reg;

            reg.generarReporteRecaudacionPorTipoProducto ();

            system ("pause");

            break;

        }

        case 0:

            system ("cls");

            cout << "Volviendo al menu anterior..." << endl ;

            system ("pause");

            break ;

        default:

            system ("cls");

            cout << "La opcion que ingreso es invalida. Intentelo de nuevo. " << endl ;

            system("pause") ;

            break ;
        }

    }
    while (opcion != 0) ;
}


void Menu::subMenuBackups ()
{

    int opc;

    do
    {

        system ("cls");

        cout << "Menu de copias de seguridad" << endl;

        cout << "----------------------------------" << endl;

        cout << "1. Realizar una copia de seguridad" << endl;

        cout << "2. Restaurar una copia de seguridad" << endl;

        cout << "----------------------------------" << endl;

        cout << "0. Volver al menu anterior" << endl;

        cout << "----------------------------------" << endl;

        cout << "Ingrese una opcion: ";

        cin >> opc;

        switch (opc)
        {

        case 1:
        {

            int opc1;

            do
            {

                system ("cls");

                cout << "Realizar una copia de seguridad" << endl;

                cout << "----------------------------------" << endl;

                cout << "1. Clientes" << endl;

                cout << "2. Proveedores" << endl;

                cout << "3. Empleados" << endl;

                cout << "4. Productos" << endl;

                cout << "5. Ventas" << endl;

                cout << "6. Detalle de ventas" << endl;

                cout << "7. Envios" << endl;

                cout << "8. Todos los archivos" << endl;

                cout << "----------------------------------" << endl;

                cout << "0. Volver al menu anterior" << endl;

                cout << "----------------------------------" << endl;

                cout << "Ingrese una opcion: ";

                cin >> opc1;

                switch (opc1)
                {

                case 1:
                {

                    system ("cls");

                    ClienteArchivo reg;

                    if (reg.hacerBackup () == true)
                    {

                        cout << "Copia de seguridad de clientes realizada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo realizar la copia de seguridad de clientes correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 2:
                {

                    system ("cls");

                    ProveedorArchivo reg;

                    if (reg.hacerBackup () == true)
                    {

                        cout << "Copia de seguridad de proveedores realizada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo realizar la copia de seguridad de proveedores correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 3:
                {

                    system ("cls");

                    EmpleadoArchivo reg;

                    if (reg.hacerBackup () == true)
                    {

                        cout << "Copia de seguridad de empleados realizada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo realizar la copia de seguridad de empleados correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 4:
                {

                    system ("cls");

                    ProductoArchivo reg;

                    if (reg.hacerBackup () == true)
                    {

                        cout << "Copia de seguridad de productos realizada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo realizar la copia de seguridad de productos correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 5:
                {

                    system ("cls");

                    VentaArchivo reg;

                    if (reg.hacerBackup () == true)
                    {

                        cout << "Copia de seguridad de ventas realizada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo realizar la copia de seguridad de ventas correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 6:
                {

                    system ("cls");

                    DetalleVentaArchivo reg;

                    if (reg.hacerBackup () == true)
                    {

                        cout << "Copia de seguridad de detalles de venta realizada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo realizar la copia de seguridad de detalles de venta correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 7:
                {

                    system ("cls");

                    EnvioArchivo reg;

                    if (reg.hacerBackup () == true)
                    {

                        cout << "Copia de seguridad de envios realizada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo realizar la copia de seguridad de envios correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 8:
                {

                    system ("cls");

                    ClienteArchivo reg1;

                    ProveedorArchivo reg2;

                    EmpleadoArchivo reg3;

                    ProductoArchivo reg4;

                    VentaArchivo reg5;

                    DetalleVentaArchivo reg6;

                    EnvioArchivo reg7;

                    if (reg1.hacerBackup () == true)
                    {

                        cout << "Copia de seguridad de clientes realizada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo realizar la copia de seguridad de clientes correctamente. " << endl;

                    }

                    if (reg2.hacerBackup () == true)
                    {

                        cout << "Copia de seguridad de proveedores realizada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo realizar la copia de seguridad de proveedores correctamente. " << endl;

                    }

                    if (reg3.hacerBackup () == true)
                    {

                        cout << "Copia de seguridad de empleados realizada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo realizar la copia de seguridad de empleados correctamente. " << endl;

                    }

                    if (reg4.hacerBackup () == true)
                    {

                        cout << "Copia de seguridad de productos realizada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo realizar la copia de seguridad de productos correctamente. " << endl;

                    }

                    if (reg5.hacerBackup () == true)
                    {

                        cout << "Copia de seguridad de ventas realizada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo realizar la copia de seguridad de ventas correctamente. " << endl;

                    }

                    if (reg6.hacerBackup () == true)
                    {

                        cout << "Copia de seguridad de detalles de venta realizada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo realizar la copia de seguridad de detalles de venta correctamente. " << endl;

                    }

                    if (reg7.hacerBackup () == true)
                    {

                        cout << "Copia de seguridad de envios realizada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo realizar la copia de seguridad de envios correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 0:
                {

                    system ("cls");

                    cout << "Volviendo al menu anterior..." << endl;

                    system ("pause");

                    break;

                }

                default:
                {

                    system ("cls");

                    cout << "La opcion que ingreso es invalida. Intentelo de nuevo. " << endl;

                    system ("pause");

                    break;

                }
                }

            }
            while (opc1 != 0);

            break;

        }

        case 2:
        {

            int opc2;

            do
            {

                system ("cls");

                cout << "Restaurar una copia de seguridad" << endl;

                cout << "----------------------------------" << endl;

                cout << "1. Clientes" << endl;

                cout << "2. Proveedores" << endl;

                cout << "3. Empleados" << endl;

                cout << "4. Productos" << endl;

                cout << "5. Ventas" << endl;

                cout << "6. Detalle de ventas" << endl;

                cout << "7. Envios" << endl;

                cout << "8. Todos los archivos" << endl;

                cout << "----------------------------------" << endl;

                cout << "0. Volver al menu anterior" << endl;

                cout << "----------------------------------" << endl;

                cout << "Ingrese una opcion: ";

                cin >> opc2;

                switch (opc2)
                {

                case 1:
                {

                    system ("cls");

                    ClienteArchivo reg;

                    if (reg.restaurarBackup () == true)
                    {

                        cout << "Copia de seguridad de clientes restaurada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo restaurar la copia de seguridad de clientes correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 2:
                {

                    system ("cls");

                    ProveedorArchivo reg;

                    if (reg.restaurarBackup () == true)
                    {

                        cout << "Copia de seguridad de proveedores restaurada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo restaurar la copia de seguridad de proveedores correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 3:
                {

                    system ("cls");

                    EmpleadoArchivo reg;

                    if (reg.restaurarBackup () == true)
                    {

                        cout << "Copia de seguridad de empleados restaurada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo restaurar la copia de seguridad de empleados correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 4:
                {

                    system ("cls");

                    ProductoArchivo reg;

                    if (reg.restaurarBackup () == true)
                    {

                        cout << "Copia de seguridad de productos restaurada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo restaurar la copia de seguridad de productos correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 5:
                {

                    VentaArchivo reg;

                    system ("cls");

                    if (reg.restaurarBackup () == true)
                    {

                        cout << "Copia de seguridad de ventas restaurada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo restaurar la copia de seguridad de ventas correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 6:
                {

                    system ("cls");

                    DetalleVentaArchivo reg;

                    if (reg.restaurarBackup () == true)
                    {

                        cout << "Copia de seguridad de detalles de venta restaurada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo restaurar la copia de seguridad de detalles de venta correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 7:
                {

                    system ("cls");

                    EnvioArchivo reg;

                    if (reg.restaurarBackup () == true)
                    {

                        cout << "Copia de seguridad de envios restaurada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo restaurar la copia de seguridad de envios correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 8:
                {

                    system ("cls");

                    ClienteArchivo reg1;

                    ProveedorArchivo reg2;

                    EmpleadoArchivo reg3;

                    ProductoArchivo reg4;

                    VentaArchivo reg5;

                    DetalleVentaArchivo reg6;

                    EnvioArchivo reg7;

                    if (reg1.restaurarBackup () == true)
                    {

                        cout << "Copia de seguridad de clientes restaurada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo restaurar la copia de seguridad de clientes correctamente. " << endl;

                    }

                    if (reg2.restaurarBackup () == true)
                    {

                        cout << "Copia de seguridad de proveedores restaurada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo restaurar la copia de seguridad de proveedores correctamente. " << endl;

                    }

                    if (reg3.restaurarBackup () == true)
                    {

                        cout << "Copia de seguridad de empleados restaurada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo restaurar la copia de seguridad de empleados correctamente. " << endl;

                    }

                    if (reg4.restaurarBackup () == true)
                    {

                        cout << "Copia de seguridad de productos restaurada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo restaurar la copia de seguridad de productos correctamente. " << endl;

                    }

                    if (reg5.restaurarBackup () == true)
                    {

                        cout << "Copia de seguridad de ventas restaurada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo restaurar la copia de seguridad de ventas correctamente. " << endl;

                    }

                    if (reg6.restaurarBackup () == true)
                    {

                        cout << "Copia de seguridad de detalles de venta restaurada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo restaurar la copia de seguridad de detalles de venta correctamente. " << endl;

                    }

                    if (reg7.restaurarBackup () == true)
                    {

                        cout << "Copia de seguridad de envios restaurada correctamente. " << endl;

                    }
                    else
                    {

                        cout << "ERROR: No se pudo restaurar la copia de seguridad de envios correctamente. " << endl;

                    }

                    system ("pause");

                    break;

                }

                case 0:
                {

                    system ("cls");

                    cout << "Volviendo al menu anterior..." << endl;

                    system ("pause");

                    break;

                }

                default:
                {

                    system ("cls");

                    cout << "La opcion que ingreso es invalida. Intentelo de nuevo. " << endl;

                    system ("pause");

                    break;

                }

                }

            }
            while (opc2 != 0);

            break;

        }

        case 0:
        {

            system ("cls");

            cout << "Volviendo al menu anterior..." << endl;

            system ("pause");

            break;

        }

        default:
        {

            system ("cls");

            cout << "La opcion que ingreso es invalida. Intentelo de nuevo. " << endl;

            system ("pause");

            break;
        }

        }

    }
    while (opc !=0);

}
