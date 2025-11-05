#include "Empleado.h"
#include "EmpleadoArchivo.h"
#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std ;

// Constructor

Empleado::Empleado() : ID_Puesto(0), horas_Trabajo(0) {}

Empleado::Empleado(int ID_Puesto, int horas_Trabajo)
{

    setID_Puesto (ID_Puesto) ;

    setHoras_Trabajo (horas_Trabajo) ;
}

// Getters

int Empleado::getID_Puesto()
{

    return ID_Puesto ;
}

int Empleado::getHoras_Trabajo()
{

    return horas_Trabajo ;
}

// Setters

void Empleado::setID_Puesto(int ID_Puesto)
{

    this->ID_Puesto = ID_Puesto ;
}

void Empleado::setHoras_Trabajo(int horas_Trabajo)
{

    this->horas_Trabajo = horas_Trabajo ;
}

// Metodos

void Empleado::cargar()
{

    EmpleadoArchivo reg ;

    Empleado empleado1 ;

    string datos ;

    int datos2 ;

    int const cantReg = reg.getCantidadRegistros() ;

    cout << "Ingrese el CUIT del empleado: " ;

    cin >> datos ;

    for (int i = 0; i<cantReg; i++)
    {

        empleado1 = reg.leer(i) ;

        while (strcmp(datos.c_str(), empleado1.getCuit().c_str()) == 0 && empleado1.getEstado() == true)
        {

            cout << "El CUIT ya corresponde a un empleado existente. Desea salir o introducir otro CUIT?: (1- Agregar otro CUIT, 2- Salir)" ;

            cin >> datos2 ;

            switch (datos2)
            {

            case 1:

                cout << "Ingrese el nuevo CUIT: " ;

                cin >> datos ;

                break ;

            case 2:

                cout << "Saliendo..." << endl ;

                return ;

                break ;

            default:

                cout << "La opcion que eligio es invalida. Intentelo de nuevo. " << endl ;

                break;
            }

        }
    }

    Empleado::setCuit(datos) ;

    cout << "Ingrese el tipo de empleado: " ;

    cin >> datos2 ;

    Empleado::setID_Puesto(datos2) ;

    cout << "Ingrese la cantidad de horas trabajadas por semana del empleado: " ;

    cin >> datos2 ;

    Empleado::setHoras_Trabajo(datos2) ;

    cout << "Ingrese el nombre del empleado: "  ;

    cin >> datos ;

    Empleado::setNombre(datos) ;

    cout << "Ingrese el apellido del empleado: " ;

    cin >> datos ;

    Empleado::setApellido(datos) ;

    cout << "Ingrese el telefono del empleado: " ;

    cin >> datos ;

    Empleado::setTelefono(datos) ;

    cout << "Ingrese la direccion del empleado: "  ;

    datos = cargarCadena() ;

    Empleado::setDireccion(datos) ;

    Empleado::setEstado(true) ;

    cout << endl << "El empleado fue agregado con exito. " << endl ;

}

void Empleado::mostrar()
{

    cout << "Informacion del empleado: " << endl ;

    cout << "ID del empleado: " << Empleado::getID() << endl ;

    cout << "Nombre y apellido del empleado: " << Empleado::getNombre() << " " << Empleado::getApellido() << endl ;

    cout << "Telefono del empleado: " << Empleado::getTelefono() << endl ;

    cout << "Direccion del empleado: " << Empleado::getDireccion() << endl ;

    cout << "CUIT del empleado: " << Empleado::getCuit() << endl ;

    cout << "ID de puesto del empleado: " << Empleado::getID_Puesto() << endl ;

    cout << "Horas trabajadas por semana del empleado: " << Empleado::getHoras_Trabajo() << endl ;

    cout << "Estado: " << Empleado::getEstado() << endl ;

    cout << endl ;
}

void Empleado::modificarCampo ()
{

    EmpleadoArchivo archivo;

    string datos;

    int datos2;

    cout << "Modificar un campo especifico de un empleado " << endl;

    cout << "-------------------------------------------" << endl;

    cout << "Ingrese el ID del empleado a modificar: ";

    cin >> datos2;

    int pos = archivo.buscarPosicion (datos2);

    if (pos == -1)
    {

        cout << "ERROR: ID de empleado no encontrado. " << endl;

        system ("pause");

        return;
    }

    *this = archivo.leer (pos);

    do
    {

        system ("cls");

        cout << "Empleado a modificar (ID: " << this->getID() << ")" << endl;

        cout << "-----------------------------" << endl ;

        this->mostrar();

        cout << "Seleccione una opcion o el campo a modificar: " << endl;

        cout << "1. Nombre" << endl;

        cout << "2. Apellido" << endl;

        cout << "3. Telefono" << endl;

        cout << "4. Direccion" << endl;

        cout << "5. CUIT" << endl;

        cout << "6. ID de puesto" << endl;

        cout << "7. Horas trabajadas a la semana" << endl;

        cout << "8. Finalizar modificaciones y volver al menu anterior" << endl;

        cout << "Opcion: " << endl;

        cin >> datos2;

        cout << endl;

        switch (datos2)
        {

        case 1:   // Modificar nombre (string)
        {

            cout << "Modificar nombre: " << endl;

            cin >> datos;

            this->setNombre(datos);

            if (archivo.modificar(*this) == true)
            {

                cout << "Nombre modificado correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar el nombre correctamente. " << endl;
            }

            system ("pause");

            break;
        }

        case 2:   // Modificar apellido (string)
        {

            cout << "Modificar apellido: " << endl;

            cin >> datos;

            this->setApellido(datos);

            if (archivo.modificar(*this) == true)
            {

                cout << "Apellido modificado correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar el apellido correctamente. " << endl;

            }

            system ("pause");

            break;
        }

        case 3:  // Modificar telefono (string)
        {

            cout << "Modificar telefono: " << endl;

            cin >> datos;

            this->setTelefono(datos);

            if (archivo.modificar(*this) == true)
            {

                cout << "Telefono modificado correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar el telefono correctamente. " << endl;
            }

            system ("pause");

            break;
        }

        case 4:  // Modificar direccion (string)
        {

            cout << "Modificar direccion: " << endl;

            datos = cargarCadena ();

            this->setDireccion(datos);

            if (archivo.modificar(*this) == true)
            {

                cout << "Direccion modificada correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar la direccion correctamente. " << endl;
            }

            system ("pause");

            break;
        }

        case 5:  // Modificar CUIT (string)
        {

            cout << "Modificar CUIT: " << endl;

            cin >> datos;

            int const cantReg = archivo.getCantidadRegistros();

            for (int i = 0; i<cantReg; i++)
            {

                *this = archivo.leer (i);

                while (strcmp(datos.c_str(), this->getCuit().c_str()) == 0 && this->getEstado() == true)   // == 0 significa si son iguales los dos strings, no si son iguales a 0
                {

                    cout << "El CUIT ya corresponde a un empleado existente. Desea salir o introducir otro CUIT?: (1- Agregar otro CUIT, 2- Salir): ";

                    cin >> datos2;

                    switch (datos2)
                    {

                    case 1:
                    {

                        cout << "Ingrese el nuevo CUIT: " ;

                        cin >> datos;

                        break;
                    }

                    case 2:
                    {

                        cout << endl << "Saliendo..." << endl;

                        return;

                        break;
                    }

                    default:
                    {

                        cout << "La opcion que eligio es invalida. Intentelo de nuevo. " << endl ;

                        break ;
                    }
                    }
                }
            }

            *this = archivo.leer (pos);

            this->setCuit(datos);

            if (archivo.modificar(*this) == true)
            {

                cout << "El CUIT fue modificado correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar el CUIT correctamente. " << endl;
            }

            system ("pause");

            break;
        }

        case 6: // Modificar ID de puesto (int)
        {

            cout << "Modificar ID de puesto: " << endl;

            cin >> datos2;

            this->setID_Puesto (datos2);

            if (archivo.modificar(*this) == true)
            {

                cout << "ID de puesto modificado correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar el ID de puesto correctamente. " << endl;
            }

            system ("pause");

            break;
        }

        case 7: // Modificar horas trabajadas por semana
        {

            cout << "Modificar horas trabajadas por semana: " << endl;

            cin >> datos2;

            this->setHoras_Trabajo (datos2);

            if (archivo.modificar(*this) == true)
            {

                cout << "Horas trabajadas por semana modificadas correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar las horas trabajadas por semana correctamente. " << endl;
            }

            system ("pause");

            break;
        }

        case 8:  // Salir al menu anterior
        {

            cout << "Saliendo al menu anterior..." << endl;

            system ("pause");

            system ("cls");

            return;

            break;
        }

        default:
        {

            cout << "La opcion que ingreso es incorrecta. Intentelo de nuevo. " << endl;

            system ("pause");

            break;
        }
        }
    }
    while (datos2 != 8);
}
