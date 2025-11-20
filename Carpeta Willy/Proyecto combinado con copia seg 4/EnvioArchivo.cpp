#include "EnvioArchivo.h"
#include <iostream>

using namespace std ;

// FUNCIONES

// Obtengo la cantidad total de registros

int EnvioArchivo::getCantidadRegistros()
{

    FILE* p = fopen(archivo_Envio, "rb") ;

    if (p == nullptr)
    {

        return 0 ;
    }

    fseek(p, 0, SEEK_END) ;

    long bytes = ftell(p) ;

    fclose(p) ;

    if (bytes == 0)
    {
        return 0 ;
    }

    return bytes / sizeof(Envio);
}

// Genero el ID para el próximo registro
// ID_Envio autoincremental, independiente de Venta.

int EnvioArchivo::obtenerID()
{

    return getCantidadRegistros() + 1 ;
}

// 3. Buscar la posición (índice) de un registro por ID_Envio

int EnvioArchivo::buscarPosicion(int id_envio)
{

    Envio reg ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++)
    {

        reg = leer(i) ;

        // busco por ID_Envio, la clave principal del archivo

        if (reg.getID_Envio() == id_envio)
        {

            return i ; // Retorna la posicion
        }
    }

    return -1 ; // No encontrado
}

// Busco la posición de un registro por ID_Venta

int EnvioArchivo::buscarPosicionPorID_Venta(int id_venta)
{

    Envio reg ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++)
    {

        reg = leer(i) ;

        // para encontrar el envío asociado a una venta.

        if (reg.getID_Venta() == id_venta)
        {

            return i ;
        }
    }

    return -1 ;
}


// FUNCIONES ABML

// ALTA

bool EnvioArchivo::guardar(const Envio &reg)
{

    FILE* p = fopen(archivo_Envio, "ab") ;

    if (p == nullptr)
    {
        return false ;
    }

    int escrito = fwrite(&reg, sizeof(Envio), 1, p) ;

    fclose(p) ;

    return escrito  ;
}

// LECTURA

Envio EnvioArchivo::leer(int pos)
{

    Envio reg ;

    FILE* p = fopen(archivo_Envio, "rb") ;

    if (p == nullptr || pos < 0)
    {
        return reg ;
    }

    fseek(p, pos * sizeof(Envio), SEEK_SET) ;

    fread(&reg, sizeof(Envio), 1, p) ;

    fclose(p) ;

    return reg ;
}

// MODIFICACIÓN
// Usa el ID_Envio de la venta pasada como parámetro para buscar la posición.

bool EnvioArchivo::modificar(const Envio &reg)
{

    // 1. Buscar la posición del registro usando ID_Envio

    int pos = buscarPosicion(reg.getID_Envio()) ;

    if (pos == -1)
    {
        return false ;
    }

    FILE* p = fopen(archivo_Envio, "rb+") ;

    if (p == nullptr)
    {
        return false ;
    }

    // 2. Mover el puntero y sobrescribir

    fseek(p, pos * sizeof(Envio), SEEK_SET) ;

    int escrito = fwrite(&reg, sizeof(Envio), 1, p) ;

    fclose(p) ;

    return escrito  ;
}

// BAJA LÓGICA
// Recibe el ID_Envio para realizar la baja.

bool EnvioArchivo::bajaLogica(int id_envio)
{

    // 1. Busco la posicion por ID_Envio

    int pos = buscarPosicion(id_envio) ;

    if (pos == -1)
    {
        return false ;
    }

    // Leer y modificar estado

    Envio reg = leer(pos) ;

    if (reg.getEstado () == false)
    {

        return false;

    }

    if (!reg.getEstado())
    {
        return false ;    // Ya estaba inactivo
    }

    reg.setEstado(false) ; // Cambio a inactivo

    // 3. Sobreescribo el registro modificado usa ID_Envio para buscar

    return modificar(reg) ;
}

bool EnvioArchivo::altaLogica(int id_envio)
{

    // 1. Busco la posicion por ID_Envio

    int pos = buscarPosicion(id_envio) ;

    if (pos == -1)
    {
        return false ;
    }

    // Leer y modificar estado

    Envio reg = leer(pos) ;

    if (reg.getEstado () == true)
    {

        return false;

    }

    if (reg.getEstado())
    {
        return true ;    // Ya estaba aactivo
    }

    reg.setEstado(true) ; // Cambio a activo

    // 3. Sobreescribo el registro modificado usa ID_Envio para buscar

    return modificar(reg) ;
}

//  funciones de EnvioArchivo

void EnvioArchivo::modificarCampos()
{

    int id_a_buscar ;

    int opcion ;

    int nuevo_dato_int ;

    cout << "Modificar un campo especifico de un envio" << endl ;

    cout << "-------------------------------------------" << endl ;

    cout << "Ingrese el ID del envio a modificar: " ;

    cin >> id_a_buscar ;

    int pos = buscarPosicion(id_a_buscar) ; // Uso el método de la clase EnvioArchivo

    if (pos == -1)
    {

        cout << "ERROR: ID de envio no encontrado." << endl ;

        system("pause") ;

        return ;
    }

    // Cargar el objeto Envio actual
    // La modificacion se hace sobre este objeto, y luego se guarda en el archivo

    Envio envio_modificar = leer(pos) ; // Uso el método de la clase EnvioArchivo

    do
    {

        system("cls") ;

        cout << "Envio a modificar (ID: " << envio_modificar.getID_Envio() << "):" << endl ;

        cout << "-----------------------------" << endl ;

        envio_modificar.mostrar() ; // Llama al método de la instancia de Envio

        cout << endl << "Seleccione el campo a modificar:" << endl ;

        cout << "1. Fecha de entrega" << endl ;

        cout << "2. Valor del envio" << endl ;

        cout << "3. Estado del envio" << endl ;

        cout << "0. Volver al menu anterior " << endl ;

        cout << endl << "Opcion: " ;

        cin >> opcion ;

        cout << endl ;

        switch (opcion)
        {

        case 1:   // Modificar Fecha de Entrega
        {

            int dia, mes, anio ;

            Fecha nueva_fecha ; // Asumo que existe la clase Fecha

            cout << "Ingrese una nueva fecha de entrega" << endl ;

            cout << "Dia: " ;

            cin >> dia ;

            cout << "Mes: " ;

            cin >> mes ;

            cout << "Año: " ;

            cin >> anio ;

            nueva_fecha.setDia(dia) ;

            nueva_fecha.setMes(mes) ;

            nueva_fecha.setAnio(anio) ;

            envio_modificar.setFecha_Entrega(nueva_fecha) ;

            if (modificar(envio_modificar))   // Uso el método modificar de EnvioArchivo
            {

                cout << endl << "Fecha de entrega modificada y guardada con exito." << endl ;

            }
            else
            {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;

            }

            system("pause") ;

            break ;
        }

        case 2:   // Modifico valor del envio
        {

            float nuevo_valor ;

            cout << "Nuevo valor del envio: $" ;

            cin >> nuevo_valor ;

            envio_modificar.setValor_Envio(nuevo_valor) ;

            if (modificar(envio_modificar))   // Uso el método modificar de EnvioArchivo
            {

                cout << endl << "Valor del envio modificado y guardado con exito." << endl ;

            }
            else
            {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 3:   // Modificar Estado del Envío
        {

            cout << "Nuevo Estado (1-Pendiente, 2-En curso, 3-Entregado): " ;

            cin >> nuevo_dato_int ;

            envio_modificar.setEstado_Entrega(nuevo_dato_int) ;

            if (modificar(envio_modificar))   // Uso el método modificar de EnvioArchivo
            {

                cout << endl << "Estado del envio modificado y guardado con exito." << endl ;

            }
            else
            {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;

            }

            system("pause") ;

            break ;
        }



        case 0: // Volver

            cout << "Volviendo al menu anterior." << endl ;

            return ; // Salir de la función

        default:

            cout << "Opcion invalida. Intente de nuevo." << endl ;

            system("pause") ;
        }

    }
    while (opcion != 0) ;   // El bucle termina si opcion es 0
}


bool EnvioArchivo::hacerBackup ()
{

    // Abro el archivo original ("Envios.dat")

    FILE* pArchivoOriginal = fopen(archivo_Envio,"rb") ;

    if(pArchivoOriginal == nullptr)
    {

        // Si no existe el archivo original, devuelve error.

        return false ;
    }

    // 2. Abro o creo el archivo de backup

    FILE* pBackup = fopen(archivo_Envio_Backup,"wb") ;

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

bool EnvioArchivo::restaurarBackup ()
{

    FILE* pArchivoBkp = fopen(archivo_Envio_Backup, "rb") ;

    if (pArchivoBkp == NULL)
    {

        return false ;
    }

    FILE* pArchivoOriginal = fopen(archivo_Envio, "wb") ;

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
