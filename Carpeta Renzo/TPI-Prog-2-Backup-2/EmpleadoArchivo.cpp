#include "EmpleadoArchivo.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include "Utils.h"

using namespace std ;

/// FUNCIONES ABML

bool EmpleadoArchivo::guardar(const Empleado &reg)
{

    FILE *archivo ;  // Se crea el puntero para utilizar el archivo

    archivo = fopen(archivo_Empleado, "ab") ; // Se abre el archivo en modo append binary

    if (archivo == nullptr)  // Se verifica si se abrio correctamente el archivo
    {

        cout << "NO SE PUDO CREAR EL ARCHIVO. " << endl ;

        return false ;
    }

    int escribio = fwrite(&reg, sizeof (Empleado), 1, archivo) ; // Se escribe la informacion en el archivo

    fclose(archivo) ; // Se cierra el archivo

    return escribio ; // Devuelvo la variable escribio

}

bool EmpleadoArchivo::bajaLogica(int id_persona)
{

    int pos = buscarPosicion(id_persona) ;

    if (pos == -1)
    {

        cout << "El ID que ingreso es incorrecto. " << endl ;

        system ("pause") ;

        return false ;
    }

    Empleado reg = leer (pos) ;

    if (reg.getEstado () == false)
    {

        return false;

    }

    reg.setEstado(false) ;

    FILE *archivo ;

    archivo = fopen (archivo_Empleado, "rb+") ;

    if (archivo == nullptr)
    {

        return false ;
    }

    fseek (archivo, pos * sizeof (Empleado), SEEK_SET) ;

    int escrito = fwrite (&reg, sizeof (Empleado), 1, archivo) ;

    fclose (archivo) ;

    return escrito ;

}


bool EmpleadoArchivo::altaLogica (int id_persona)
{

    int pos = buscarPosicion(id_persona) ;

    if (pos == -1)
    {

        cout << "El ID que ingreso es incorrecto. " << endl ;

        system ("pause") ;

        return false ;
    }

    Empleado reg = leer (pos);

    if (reg.getEstado () == true)
    {

        return false;

    }

    reg.setEstado(true);

    FILE *archivo;

    archivo = fopen (archivo_Empleado, "rb+") ;

    if (archivo == nullptr)
    {

        return false ;
    }

    fseek (archivo, pos * sizeof (Empleado), SEEK_SET);

    int escrito = fwrite (&reg, sizeof (Empleado), 1, archivo);

    fclose (archivo);

    return escrito;

}


Empleado EmpleadoArchivo::leer (int pos)
{

    Empleado reg ;

    FILE *archivo ;

    archivo = fopen(archivo_Empleado, "rb") ;

    if (archivo == nullptr)
    {
        return reg ;
    }

    fseek (archivo, pos * sizeof (Empleado), SEEK_SET) ;

    fread (&reg, sizeof (Empleado), 1, archivo) ;

    fclose (archivo) ;

    return reg ;
}

bool EmpleadoArchivo::modificar (const Empleado &reg)
{

    int pos = buscarPosicion (reg.getID()) ;

    if (pos == -1)
    {

        cout << "El ID ingresado es incorrecto. " << endl ;

        return false ;
    }

    FILE *archivo;

    archivo = fopen (archivo_Empleado, "rb+");

    if (archivo == nullptr)
    {
        return false ;
    }

    fseek (archivo, pos * sizeof (Empleado), SEEK_SET) ;

    int escribio = fwrite (&reg, sizeof (Empleado), 1, archivo) ;

    fclose (archivo) ;

    return escribio ;
}

/// FUNCIONES AUXILIARES

int EmpleadoArchivo::buscarPosicion (int id_persona)
{

    Empleado reg;

    int cantReg = getCantidadRegistros() ;

    for (int i = 0; i<cantReg; i++)
    {

        reg = leer (i) ;

        if (reg.getID() == id_persona)
        {

            return i ;
        }
    }

    return -1 ;
}

int EmpleadoArchivo::getCantidadRegistros ()
{

    FILE *archivo ;

    archivo = fopen(archivo_Empleado, "rb") ;

    if (archivo == nullptr)
    {
        return 0 ;
    }

    fseek(archivo, 0, SEEK_END) ;

    int tamanio = ftell(archivo) ;

    fclose(archivo) ;

    return tamanio / sizeof (Empleado) ;
}


bool EmpleadoArchivo::validarCUIT (string cuit)
{

    Empleado empleado1;

    int const cantReg = getCantidadRegistros ();

    int opcion;

    for (int i = 0; i<cantReg; i++)
    {

        empleado1 = leer(i) ;

        while (strcmp(cuit.c_str(), empleado1.getCuit().c_str()) == 0 && empleado1.getEstado() == true)
        {

            cout << "El CUIT ya corresponde a un empleado existente. Desea salir o introducir otro CUIT?: (1- Agregar otro CUIT, 2- Salir)" ;

            cin >> opcion ;

            switch (opcion)
            {

            case 1:

                cout << "Ingrese el nuevo CUIT: " ;

                cin >> cuit ;

                break ;

            case 2:

                cout << "Saliendo..." << endl ;

                return false;

                break ;

            default:

                cout << "La opcion que eligio es invalida. Intentelo de nuevo. " << endl ;

                break;
            }

        }
    }

    return true;
}


void EmpleadoArchivo::modificarCampo ()
{

    Empleado empleado;

    string datos;

    int datos2;

    cout << "Modificar un campo especifico de un empleado " << endl;

    cout << "-------------------------------------------" << endl;

    cout << "Ingrese el ID del empleado a modificar: ";

    cin >> datos2;

    int pos = buscarPosicion (datos2);

    if (pos == -1)
    {

        cout << "ERROR: ID de empleado no encontrado. " << endl;

        system ("pause");

        return;
    }

    empleado = leer (pos);

    do
    {

        system ("cls");

        cout << "Empleado a modificar (ID: " << empleado.getID() << ")" << endl;

        cout << "-----------------------------" << endl ;

        empleado.mostrar();

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

            empleado.setNombre(datos);

            if (modificar(empleado) == true)
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

            empleado.setApellido(datos);

            if (modificar(empleado) == true)
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

            empleado.setTelefono(datos);

            if (modificar(empleado) == true)
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

            empleado.setDireccion(datos);

            if (modificar(empleado) == true)
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

            bool const validado = validarCUIT (datos);

            if (validado == false)
            {

                return;
            }

            empleado = leer (pos);

            empleado.setCuit(datos);

            if (modificar(empleado) == true)
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

            empleado.setID_Puesto (datos2);

            if (modificar(empleado) == true)
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

            empleado.setHoras_Trabajo (datos2);

            if (modificar(empleado) == true)
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


/// REPORTES


void EmpleadoArchivo::calcularEmpleadosConMasHoras ()
{

    Empleado empleadoObjeto;

    int const cantReg = getCantidadRegistros ();

    if (cantReg == 0)
    {

        cout << "No hay empleados cargados. " << endl;

        return;
    }

    int *horas = new int [cantReg] ();

    int *id_empleado = new int [cantReg] ();

    int acum_activos = 0;

    for (int i=0; i<cantReg; i++)
    {

        empleadoObjeto = leer (i);

        if (empleadoObjeto.getEstado () == true)
        {

            horas [acum_activos] = empleadoObjeto.getHoras_Trabajo ();

            id_empleado [acum_activos] = empleadoObjeto.getID ();

            acum_activos ++;

        }

    }

    if (acum_activos == 0)
    {

        cout << "No hay empleados activos. " << endl;

        delete[] id_empleado;

        delete[] horas;

        return;
    }

    int aux_horas=0;

    int aux_id=0;

    for (int i=0; i<acum_activos-1; i++)
    {

        for (int j=0; j<acum_activos-i-1; j++)
        {

            if (horas [j] < horas [j+1])
            {

                aux_horas = horas [j];

                horas [j] = horas [j+1];

                horas [j+1] = aux_horas;

//-----------------------------------------------------

                aux_id = id_empleado [j];

                id_empleado [j] = id_empleado [j+1];

                id_empleado [j+1] = aux_id;
            }
        }
    }

    cout << "-------------------------------------------------------------------------------------------------" << endl;

    cout << "EMPLEADOS ORDENADOS POR HORAS SEMANALES" << endl;

    cout << "-------------------------------------------------------------------------------------------------" << endl;

    for (int i=0; i<acum_activos; i++)
    {

        empleadoObjeto = leer (buscarPosicion(id_empleado[i]));

        //    if (empleadoObjeto.getEstado() == true){

        cout << "-------------------------------------------------------------------------------------------------" << endl;

        cout << "ID de Empleado: " << id_empleado [i] << " | " << "Nombre y apellido: " << empleadoObjeto.getNombre () << " " << empleadoObjeto.getApellido () << " | " << "Horas trabajadas a la semana: " << horas [i] << endl;

        cout << "-------------------------------------------------------------------------------------------------" << endl;

        //    }
    }

    delete[] id_empleado;

    delete[] horas;

    return;
}


bool EmpleadoArchivo::hacerBackup ()
{

    // Abro el archivo original ("Empleados.dat")

    FILE* pArchivoOriginal = fopen(archivo_Empleado,"rb") ;

    if(pArchivoOriginal == nullptr)
    {

        // Si no existe el archivo original, devuelve error.

        return false ;
    }

    // 2. Abro o creo el archivo de backup

    FILE* pBackup = fopen(archivo_Empleado_Backup,"wb") ;

    if(pBackup == nullptr)
    {

        // Si no se puede crear el backup, cerrar el original y devolver error.

        fclose(pArchivoOriginal) ;

        return false ;
    }

    // Búfer temporal para copiar datos

    char temporal[1024] ;

    int bytesLeidos ;

    // Copio el contenido: leer un bloque y escribirlo hasta el final del archivo

    while((bytesLeidos = fread(temporal, 1, 1024, pArchivoOriginal)) > 0)
    {

        // Escribir solo los bytes que se leyeron (pueden ser menos de 1024 en la última lectura)

        fwrite(temporal, 1, bytesLeidos, pBackup) ;
    }

    // Cerrar ambos archivos

    fclose(pArchivoOriginal) ;

    fclose(pBackup) ;


    return true ;

}

bool EmpleadoArchivo::restaurarBackup ()
{

    FILE* pArchivoBkp = fopen(archivo_Empleado_Backup, "rb") ;

    if (pArchivoBkp == NULL)
    {

        return false ;
    }

    FILE* pArchivoOriginal = fopen(archivo_Empleado, "wb") ;

    if (pArchivoOriginal == NULL)
    {

        fclose(pArchivoBkp) ;

        return false ;
    }

    char temporal[1024] ;

    int bytesLeidos ;

    while ((bytesLeidos = fread(temporal, 1, 1024, pArchivoBkp)) > 0)
    {

        fwrite(temporal, 1, bytesLeidos, pArchivoOriginal) ;
    }

    fclose(pArchivoBkp) ;

    fclose(pArchivoOriginal) ;

    return true ;

}
