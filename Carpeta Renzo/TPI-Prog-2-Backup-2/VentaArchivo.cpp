#include "Venta.h"
#include "VentaArchivo.h"
#include "ClienteArchivo.h"
#include <iostream>
#include <cstdio>

using namespace std ;


bool VentaArchivo::guardar(const Venta &reg)
{

    FILE* pventa;

    pventa = fopen(archivo_Venta,"ab") ;

    if(pventa == nullptr)
    {

        cout << "NO SE PUDO CREAR EL ARCHIVO" ;

        return false ;
    }

    int escrito = fwrite(&reg, sizeof(Venta), 1, pventa) ;

    fclose(pventa) ;

    return escrito ;

}

Venta VentaArchivo::leer(int pos)
{

    Venta reg ;

    FILE* pventa ;

    pventa = fopen(archivo_Venta, "rb") ;

    if(pventa == nullptr)
    {

        cout << "NO SE PUDO CREAR EL ARCHIVO" ;

        return reg ;
    }

    fseek(pventa, pos * sizeof(Venta), SEEK_SET) ;

    fread(&reg, sizeof(Venta), 1, pventa) ;

    fclose(pventa) ;

    return reg ;

}

bool VentaArchivo::bajaLogica(int id_venta)
{

    int pos = buscarPosicion(id_venta) ;

    if(pos == -1)
    {

        return false ;
    }

    Venta reg = leer(pos) ;

    if (reg.getEstado () == false)
    {

        return false;

    }

    reg.setEstado(false) ;

    FILE* pventa ;

    pventa = fopen(archivo_Venta, "rb+") ;

    if (pventa == nullptr)
    {
        return false ;
    }

    fseek(pventa,pos*sizeof(Venta),SEEK_SET) ;

    int escrito = fwrite(&reg, sizeof(Venta), 1, pventa) ;

    fclose(pventa) ;

    return escrito ;
}

bool VentaArchivo::altaLogica(int id_venta)
{

    int pos = buscarPosicion(id_venta) ;

    if(pos == -1)
    {

        return false ;
    }

    Venta reg = leer(pos) ;

    if (reg.getEstado () == true)
    {

        return false;

    }

    reg.setEstado(true) ;

    FILE* pventa ;

    pventa = fopen(archivo_Venta, "rb+") ;

    if (pventa == nullptr)
    {
        return false ;
    }

    fseek(pventa,pos*sizeof(Venta),SEEK_SET) ;

    int escrito = fwrite(&reg, sizeof(Venta), 1, pventa) ;

    fclose(pventa) ;

    return escrito ;
}

bool VentaArchivo::modificar(const Venta &reg)
{

    int pos ;

    pos = buscarPosicion(reg.getID_Venta()) ;

    if(pos == -1)
    {

        return false ;
    }

    FILE* pventa ;

    pventa = fopen(archivo_Venta, "rb+") ;

    if(pventa == nullptr)
    {
        return false ;
    }

    fseek(pventa, pos * sizeof(Venta), SEEK_SET) ;

    int escrito = fwrite(&reg, sizeof(Venta), 1, pventa) ;

    fclose(pventa) ;

    return escrito ;

}

int VentaArchivo::obtenerID()
{

    int bytes ;

    int numRegistros ;

    FILE* pventa ;

    pventa = fopen(archivo_Venta, "rb") ;

    if(pventa == nullptr)
    {
        return 1 ;
    }

    fseek(pventa, 0, SEEK_END) ;

    bytes = ftell(pventa) ;

    fclose(pventa) ;

    if(bytes == 0)
    {
        return 1 ;
    }

    numRegistros = bytes / sizeof(Venta) ;

    return numRegistros + 1 ;
}
int VentaArchivo::getCantidadRegistros()
{

    FILE* pventa ;

    pventa = fopen(archivo_Venta, "rb") ;

    if(pventa == nullptr)
    {

        cout << "NO SE PUDO CREAR EL ARCHIVO" ;

        return false ;
    }

    fseek(pventa, 0, SEEK_END) ;

    int tamanoBytes = ftell(pventa) ;

    fclose(pventa) ;

    return tamanoBytes / sizeof(Venta) ;

}

int VentaArchivo::buscarPosicion(int id_venta)
{

    Venta reg;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad ; i++)
    {

        reg = leer(i) ;

        if(reg.getID_Venta() == id_venta)
        {

            return i ;
        }
    }

    return -1 ;
}

// FUNCIONES PARA REPORTES

/*float VentaArchivo::calcularRecaudacionAnual(int anio)
{

    Venta reg ;

    float recaudacion = 0.0 ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++)
    {

        reg = leer(i) ;

        // Filtra por estado (solo ventas activas)

        // Filtra por año

        if (reg.getEstado() && reg.getFechaVenta().getAnio() == anio)
        {

            recaudacion += reg.getMontoTotal() ;
        }
    }

    return recaudacion ;
}

float VentaArchivo::calcularRecaudacionMensual(int mes, int anio)
{

    Venta reg ;

    float recaudacion = 0.0 ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++)
    {

        reg = leer(i) ;

        // Filtra por estado activo

        // Filtra por año

        // Filtra por mes

        if (reg.getEstado() && reg.getFechaVenta().getAnio() == anio && reg.getFechaVenta().getMes() == mes)
        {

            recaudacion += reg.getMontoTotal() ;
        }
    }
    return recaudacion ;
}
*/
// funciones de VentaArchivo

void VentaArchivo::modificarCampos()
{

    int id_a_buscar ;

    int opcion ;

    int nuevo_dato_int ;

    cout << "Modificar un campo especifico de una venta" << endl ;

    cout << "-------------------------------------------" << endl ;

    cout << "Ingrese el ID de la venta a modificar: " ;

    cin >> id_a_buscar ;

    int pos = buscarPosicion(id_a_buscar) ; // Usa el metodo de la clase VentaArchivo

    if (pos == -1)
    {

        cout << "ERROR: ID de venta no encontrado." << endl ;

        system("pause") ;

        return ;
    }

    // Cargar el objeto Venta actual desde el archivo

    Venta venta_modificar = leer(pos) ; // Usa el método de la clase VentaArchivo

    do
    {

        system("cls") ;

        cout << "Venta a Modificar (ID: " << venta_modificar.getID_Venta() << "):" << endl ;

        cout << "-----------------------------" << endl ;

        venta_modificar.mostrarVenta() ; // Llama al método de la instancia de Venta

        cout << endl << "Seleccione el campo a modificar:" << endl ;

        cout << "1. Fecha de venta" << endl ;

        cout << "2. Medio de pago" << endl ;

        cout << "3. Tipo de envio" << endl ;

//        cout << "4. Tipo de factura" << endl ;

        cout << "0. Volver al menu anterior" << endl ;

        cout << endl << "Opcion: " ;

        cin >> opcion ;

        cout << endl ;

        switch (opcion)
        {

        case 1:
        {

            int dia, mes, anio ;

            Fecha nueva_fecha ;

            cout << "Ingrese nueva fecha de venta" << endl ;

            cout << "Dia: " ;

            cin >> dia ;

            cout << "Mes: " ;

            cin >> mes ;

            cout << "Anio: " ;

            cin >> anio ;

            nueva_fecha.setDia(dia) ;

            nueva_fecha.setMes(mes) ;

            nueva_fecha.setAnio(anio) ;

            venta_modificar.setFechaVenta(nueva_fecha) ;

            // Guardo el cambio

            if (modificar(venta_modificar))   // Usa el método modificar de VentaArchivo
            {

                cout << endl << "Fecha de venta modificada y guardada con exito." << endl ;

            }
            else
            {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;

            }

            system("pause") ;

            break ;
        }

        case 2:   // Modificar Medio de Pago (int)
        {

            cout << "Nuevo medio de pago (1-Efectivo, 2-Tarjeta, 3-Transferencia): " ;

            cin >> nuevo_dato_int ;

            venta_modificar.setMedioDePago(nuevo_dato_int) ;

            if (modificar(venta_modificar))
            {

                cout << endl << "Medio de pago modificado y guardado con exito." << endl ;

            }
            else
            {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;

            }

            system("pause") ;

            break ;
        }

        case 3:   // Modificar Tipo de Envío
        {

            cout << "Nuevo tipo de envio (1-A domicilio, 2-Retiro en sucursal): " ;

            cin >> nuevo_dato_int ;

            venta_modificar.setTipoEnvio(nuevo_dato_int) ;

            if (modificar(venta_modificar))
            {

                cout << endl << "Tipo de envio modificado y guardado con exito." << endl ;

            }
            else
            {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;

            }
            system("pause") ;

            break ;
        }
/*
        case 4:   // Modificar Tipo de Factura
        {

            cout << "Nuevo Tipo de Factura (1-A, 2-B, 3-C): " ;

            cin >> nuevo_dato_int ;

            venta_modificar.setTipoFactura(nuevo_dato_int) ;

            if (modificar(venta_modificar))
            {

                cout << endl << "Tipo de factura modificado y guardado con exito." << endl ;

            }
            else
            {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;

            }

            system("pause") ;

            break ;
        }
*/
        // Los campos subTotal y montoTotal NO se modifican directamente por el usuario
        // ya que se calculan en base al Detalle_Venta.

        case 0: // Volver

            cout << "Volviendo al menu anterior." << endl ;

            break ;

        default:

            cout << "Opcion invalida. Intente de nuevo." << endl ;

            system("pause") ;
        }

    }
    while (opcion != 0) ;

    cout << "Todos los cambios han sido aplicados y guardados en el archivo de Ventas." << endl ;

    system("pause") ;
}

void VentaArchivo::calcularRecaudacionPorCliente ()
{

    Venta venta;

    ClienteArchivo registroCliente;

    Cliente cliente;

    int const cantCliente = registroCliente.getCantidadRegistros ();

    int const cantVenta = getCantidadRegistros ();

    if (cantCliente == 0 || cantVenta == 0)
    {

        cout << "No hay registros de clientes o ventas. " << endl;

        return;
    }

    float *acumulador = new float [cantCliente] (); // Acumulador por ID de cliente -1

    for (int i=0; i<cantVenta; i++)
    {

        venta = leer (i);

        if (venta.getEstado() == false) continue;

        for (int j=0; j<cantCliente; j++)
        {

            cliente = registroCliente.leer (j);

            if (cliente.getEstado () == true && cliente.getID() == venta.getID_Cliente())
            {

                acumulador [j] += venta.getMontoTotal ();

                break;
            }


        }


    }

    cout << "-------------------------------------------------------------------------------" << endl;

    cout << "RECAUDACION POR CLIENTE" << endl;

    cout << "-------------------------------------------------------------------------------" << endl;

    for (int i=0; i<cantCliente; i++)
    {

        cliente = registroCliente.leer (i);

        if (cliente.getEstado () == true)
        {

            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "ID del cliente: " << cliente.getID() << " | " << "Nombre y apellido: " << cliente.getNombre() << " " << cliente.getApellido () << " | " << "Recaudacion total: $" << acumulador [i] << endl;

            cout << "-------------------------------------------------------------------------------" << endl;
        }
    }

    delete[] acumulador;

}


void VentaArchivo::reporteCantidadPorMedioPago ()
{

    const int MAX_METODOS_PAGO = 4;

    const char *nombresMetodos[MAX_METODOS_PAGO] =
    {
        "1. Efectivo",
        "2. Transferencia",
        "3. Debito",
        "4. Credito",
    };

    int contadores[MAX_METODOS_PAGO] = {0};

    float montosAcumulados[MAX_METODOS_PAGO] = {0.0};

    int cantVentas = getCantidadRegistros();

    if (cantVentas == 0)
    {

        cout << "No hay ventas cargadas para reportar." << endl;

        return;

    }

    Venta reg;

    int totalGeneralVentas = 0;

    float totalGeneralMonto = 0.0;

    for (int i = 0; i < cantVentas; i++)
    {

        reg = leer(i);


        if (reg.getEstado())
        {
            int metodo = reg.getMedioPago();


            if (metodo >= 1 && metodo <= MAX_METODOS_PAGO)
            {

                int indiceArray = metodo - 1;


                contadores[indiceArray]++;

                totalGeneralVentas++;


                montosAcumulados[indiceArray] += reg.getMontoTotal();

                totalGeneralMonto += reg.getMontoTotal();

            }
        }
    }

    system("cls");

    cout << "--- REPORTE DE VENTAS POR MEDIO DE PAGO ---" << endl;

    cout << "-------------------------------------------" << endl;

    for (int i = 0; i < MAX_METODOS_PAGO; i++)
    {

        cout << nombresMetodos[i] << ":" << endl;

        cout << "   - Cantidad: " << contadores[i] << " ventas" << endl;

        cout << "   - Monto Total: $" << montosAcumulados[i] << endl;

    }

    cout << "-------------------------------------------" << endl;

    cout << "TOTAL VENTAS (ACTIVAS): " << totalGeneralVentas << " ventas" << endl;

    cout << "MONTO TOTAL (ACTIVOS): $" << totalGeneralMonto << endl;

    cout << "-------------------------------------------" << endl;

}


float VentaArchivo::calcularRecaudacion(int anio)
{

    Venta reg ;

    const int MESES_DEL_ANIO = 12;

    // Array para acumular la recaudación de cada mes (índices 0 a 11 para meses 1 a 12)

    float recaudacionMensual[MESES_DEL_ANIO] = {0.0} ;

    float recaudacionTotalAnual = 0.0 ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++)
    {

        reg = leer(i) ;

        // Filtra por estado (solo ventas activas)
        // Filtra por el año solicitado

        if (reg.getEstado() && reg.getFechaVenta().getAnio() == anio)
        {

            int mes = reg.getFechaVenta().getMes();

            // Verificación de mes válido (1 a 12)

            if (mes >= 1 && mes <= 12)
            {

                // Acumula en la posición correcta (mes - 1)

                recaudacionMensual[mes - 1] += reg.getMontoTotal() ;
            }
        }
    }

    // A. IMPRIMIR LA RECAUDACIÓN DE CADA MES Y SUMAR EL TOTAL

    cout << "RECAUDACION DEL ANIO: " << anio << " " << endl ;

    cout << "--------------------------------------------" << endl << endl ;

    for (int mes = 0; mes < 12; ++mes)
    {

        // Sumar al total

        recaudacionTotalAnual += recaudacionMensual[mes] ;

        // Imprimir el detalle mensual


        cout << "Mes " << mes + 1 << ": $ " << recaudacionMensual[mes] << endl ;
    }

    // B. IMPRIMIR LA RECAUDACIÓN TOTAL ANUAL (El total de la suma de los meses)

    cout << endl << "--------------------------------------------" << endl ;

    cout << "TOTAL RECAUDADO EN " << anio << ": $" << recaudacionTotalAnual << endl ;

    cout << "--------------------------------------------" << endl ;

    // Retorna la recaudación total, aunque ya la imprimimos.

    return recaudacionTotalAnual ;
}


bool VentaArchivo::hacerBackup ()
{


    FILE *pArchivoOriginal = fopen(archivo_Venta,"rb");

    if(pArchivoOriginal == nullptr)
    {

        return false;

    }

    FILE *pBakup = fopen (archivo_Venta_Backup,"wb");

    if(pBakup == nullptr)
    {

        pclose(pArchivoOriginal);

        return false;
    }

    char temporal[1024];

    int bytesLeidos;

    while((bytesLeidos = fread(temporal,1,1024,pArchivoOriginal))>0)
    {

        fwrite(temporal,1,bytesLeidos,pBakup);
    }

    fclose(pArchivoOriginal);

    fclose(pBakup);

    return true;

}

bool VentaArchivo::restaurarBackup ()
{

    FILE *pArchivoBkp = fopen(archivo_Venta_Backup, "rb");

    if (pArchivoBkp == NULL)
    {

        return false;

    }

    FILE *pArchivoOriginal = fopen(archivo_Venta, "wb");

    if (pArchivoOriginal == NULL)
    {

        fclose(pArchivoBkp);

        return false;

    }

    char temporal[1024];

    int bytesLeidos;

    while ((bytesLeidos = fread(temporal, 1, 1024, pArchivoBkp)) > 0)
    {

        fwrite(temporal, 1, bytesLeidos, pArchivoOriginal);

    }

    fclose(pArchivoBkp);

    fclose(pArchivoOriginal);

    return true;

}
