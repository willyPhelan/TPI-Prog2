#include "Proveedor.h"
#include "ProveedorArchivo.h"
#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std ;

// Constructor


Proveedor::Proveedor() : tipo_proveedor(0)
{
}

Proveedor::Proveedor(int tipo_proveedor)
{

    setTipo_proveedor(tipo_proveedor) ;
}

// Getters

int Proveedor::getTipo_proveedor()
{

    return tipo_proveedor ;
}


string Proveedor::getMail() const
{

    return mail ;
}

// Setters

void Proveedor::setTipo_proveedor(int tipo_proveedor)
{

    this->tipo_proveedor = tipo_proveedor ;
}

void Proveedor::setMail(std::string mail)
{

    // strncpy para copiar la cadena al array char[30] de forma segura

    strncpy(this->mail, mail.c_str(), 29) ;

    this->mail[29] = '\0' ;
}

// Metodos

void Proveedor::cargar()
{

    string datos ;

    int datos2 ;

    Proveedor proveedor1 ;

    ProveedorArchivo archivo;

    int tipo_proveedor ;

    int const cantReg = archivo.getCantidadRegistros() ;

    cout << "Ingrese el CUIT del proveedor: "  ;

    cin >> datos ;

    for (int i = 0; i <cantReg ; i++)
    {

        proveedor1 = archivo.leer(i) ;

        while (strcmp(datos.c_str(), proveedor1.getCuit().c_str()) == 0 && proveedor1.getEstado() == true)
        {

            cout << "El CUIT ya corresponde a un proveedor existente. Desea salir o introducir otro CUIT? (1- Agregar otro CUIT, 2- Salir):" ;

            cin >> datos2 ;

            switch (datos2)
            {

            case 1:

                cout << "Ingrese el nuevo CUIT: "  ;

                cin >> datos ;

                break ;

            case 2:

                cout << endl << "Saliendo..." << endl ;

                return ;

                break ;

            default:

                cout << "La opcion que eligio es invalida. Intentelo de nuevo. " << endl ;

                break ;
            }

        }
    }

    Proveedor::setCuit(datos) ;

    cout << "Ingrese el tipo de proveedor (1-Empresa, 2-Particular, 3-Servicios):  " ;

    cin >> tipo_proveedor ;

    Proveedor::setTipo_proveedor(tipo_proveedor) ;

    cout << "Ingrese el nombre del proveedor: " ;

    datos = cargarCadena() ;

    Proveedor::setNombre(datos) ;

    cout << "Ingrese el numero de telefono del proveedor: " ;

    cin >> datos ;

    Proveedor::setTelefono(datos) ;

    cout << "Ingrese la direccion del proveedor: "  ;

    datos = cargarCadena() ;

    Proveedor::setDireccion(datos) ;

    cout << "Ingrese el mail del proveedor: "  ;

    datos = cargarCadena() ;

    Proveedor::setMail(datos) ;

    Proveedor::setEstado(true) ;

    cout << endl << "El proveedor fue agregado con exito. " << endl ;

}

void Proveedor::mostrar()
{

    cout << "Informacion del proveedor: " << endl ;

    cout << endl ;

    cout << "ID del proveedor: " << Proveedor::getID() << endl ;

    cout << "CUIT del proveedor: " << Proveedor::getCuit() << endl ;

    cout << "Tipo de proveedor: " << Proveedor::getTipo_proveedor() << endl ;

    cout << "Nombre del proveedor: " << Proveedor::getNombre() << endl ;

    cout << "Telefono del proveedor: " << Proveedor::getTelefono() << endl ;

    cout << "Direccion del proveedor: " << Proveedor::getDireccion() << endl ;

    cout << "Mail del proveedor: " << Proveedor::getMail() << endl ;

    if(Proveedor::getEstado())
    {

        cout << "Estado del proveedor: Activo " << endl ;
    }
    else
    {
        cout << "Estado del proveedor: Inactivo " << endl ;
    }

    cout << endl;
}


void Proveedor::modificarCampo ()
{
    ProveedorArchivo archivo;

    string datos;

    int datos2;

    cout << "Modificar un campo especifico de un proveedor " << endl;

    cout << "-------------------------------------------" << endl;

    cout << "Ingrese el ID del proveedor a modificar: ";

    cin >> datos2;

    int pos = archivo.buscarPosicion (datos2);

    if (pos == -1)
    {

        cout << "ERROR: ID de proveedor no encontrado. " << endl;

        system ("pause");

        return;
    }

    *this = archivo.leer (pos);

    do
    {

        system ("cls");

        cout << "Proveedor a modificar (ID: " << this->getID() << ")" << endl;

        cout << "-----------------------------" << endl ;

        this->mostrar();

        cout << "Seleccione una opcion o el campo a modificar: " << endl;

        cout << "1. Nombre" << endl;

        cout << "2. Telefono" << endl;

        cout << "3. Direccion" << endl;

        cout << "4. CUIT" << endl;

        cout << "5. Mail" << endl;

        cout << "6. Tipo de proveedor" << endl;

        cout << "7. Finalizar modificaciones y volver al menu anterior" << endl;

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

        case 2:   // Modificar telefono (string)
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

        case 3:  // Modificar direccion (string)
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

        case 4:  // Modificar CUIT (string)
        {

            cout << "Modificar CUIT: " << endl;

            cin >> datos;

            int const cantReg = archivo.getCantidadRegistros();

            for (int i = 0; i<cantReg; i++)
            {

                *this = archivo.leer (i);

                while (strcmp(datos.c_str(), this->getCuit().c_str()) == 0 && this->getEstado() == true)   // == 0 significa si son iguales los dos strings, no si son iguales a 0
                {

                    cout << "El CUIT ya corresponde a un proveedor existente. Desea salir o introducir otro CUIT?: (1- Agregar otro CUIT, 2- Salir): ";

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

        case 5:  // Modificar mail (string)
        {

            cout << "Modificar mail: " << endl;

            cin >> datos;

            this->setMail (datos);

            if (archivo.modificar(*this) == true)
            {

                cout << "Mail modificado correctamente. " << endl;
            }
            else
            {

                cout << "ERROR: No se pudo modificar el mail correctamente. " << endl;
            }

            system ("pause");

            break;
        }

        case 6: // Modificar tipo de proveedor (int)
        {

            cout << "Modificar tipo de proveedor: " << endl;

            cin >> datos2;

            this->setTipo_proveedor (datos2);

            if (archivo.modificar(*this) == true)
            {

                cout << "Tipo de proveedor modificado correctamente. " << endl;

            }
            else
            {

                cout << "ERROR: No se pudo modificar el tipo de proveedor correctamente. " << endl;
            }

            system ("pause");

            break;
        }

        case 7: // Salir al menu anterior
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
    while (datos2 != 7);

}
