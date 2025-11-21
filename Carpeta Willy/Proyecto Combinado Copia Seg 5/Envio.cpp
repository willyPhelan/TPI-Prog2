#include "Envio.h"
#include "Fecha.h"  // Necesario para el atributo Fecha_Entrega
#include "Utils.h" // funciones aux
#include <iostream>
#include "EnvioArchivo.h"
#include "VentaArchivo.h"


using namespace std ;


// CONSTRUCTORES //

// Constructor por defecto

Envio::Envio()
    : ID_Envio(0), estado_Entrega(0), valor_Envio(0.0f), estado(true) // Estado por defecto: Activo
{}

// Constructor con parámetros

Envio::Envio(int idEnvio, Fecha fecha, int estado, float valor, bool activo)
    : ID_Envio(idEnvio), fecha_Entrega(fecha), estado_Entrega(estado), valor_Envio(valor), estado(activo)
{}



// GETTERS

int Envio::getID_Envio() const
{

    return ID_Envio ;
}

int Envio::getID_Venta() const
{

    return ID_Venta ;
}

Fecha Envio::getFecha_Entrega() const
{

    return fecha_Entrega ;
}

int Envio::getEstado_Entrega() const
{

    return estado_Entrega ;
}

float Envio::getValor_Envio() const
{

    return valor_Envio ;
}

bool Envio::getEstado() const
{

    return estado ;
}


// SETTERS

void Envio::setID_Envio(int idEnvio)
{

    ID_Envio = idEnvio ;
}

void Envio::setID_Venta(int id_venta)
{

    ID_Venta = id_venta ;
}

void Envio::setFecha_Entrega(const Fecha& fecha)
{

    fecha_Entrega = fecha ;
}

void Envio::setEstado_Entrega(int estado)
{

    estado_Entrega = estado ;
}

void Envio::setValor_Envio(float valor)
{

    valor_Envio = valor ;
}

void Envio::setEstado(bool activo){

    estado = activo ;
}


void Envio::cargar() {


    VentaArchivo archivoVenta ;

    Venta ventaAsociada ;

    // 1. Buscar la Venta asociada a este Envio.

    int posVenta = archivoVenta.buscarPosicion(getID_Venta()) ;

    if (posVenta == -1) {

        cout << "ERROR: Venta asociada (ID " << getID_Venta() << ") no encontrada. No se puede validar la fecha." << endl ;

    } else { ventaAsociada = archivoVenta.leer(posVenta) ; }

    Fecha fechaVenta = ventaAsociada.getFechaVenta() ;

    int estadoEntrega ;

    float valorEnvio ;

    bool fechaValida = false ;

    // Bucle para el ingreso de una fecha valida

    do {

        // Fecha de Entrega

        Fecha fecha ; // objeto temporal para la carga

        int dia, mes, anio ;

        cout << "La fecha de venta fue: " ;

        fechaVenta.mostrar() ; // Muestra la fecha de la venta para referencia.

        cout << endl << "-----------------------------------" << endl ;

        cout << "Dia de entrega: " ;

        cin >> dia ;

        while (dia < 1 || dia > 31){

        cout << "El dia que ingreso es invalido. Intentelo de nuevo." << endl;

        cout << "Dia: " ;

        cin >> dia ; }

        cout << "Mes de entrega: " ;

        cin >> mes ;

        while (mes < 1 || mes > 12){

                cout << "El mes que ingreso es invalido. Intentelo de nuevo." << endl;

                cout << "Mes: " ;

                cin >> mes ;

            }

        cout << "Anio de entrega: " ;

        cin >> anio ;

    while (anio < 2000 || anio > 2025){

        cout << "El anio que ingreso es invalido. Intentelo de nuevo." << endl ;

        cout << "Anio: " ;

        cin >> anio ;

    }

        // Asigno lo que se ingreso en el cin al obj Fecha

        fecha.setDia(dia) ;
        fecha.setMes(mes) ;
        fecha.setAnio(anio) ;

        //VERIFICACION CLAVE

        if (fecha.esMayorOIgualA(fechaVenta)) {

            setFecha_Entrega(fecha) ;

            fechaValida = true ;

        } else {

            cout << endl << "ERROR: La fecha de entrega (" ;

            fecha.mostrar() ;

            cout << ") debe ser IGUAL O POSTERIOR a la fecha de la venta (" ;

            fechaVenta.mostrar() ;

            cout << "). Intente de nuevo." << endl << endl ;
        }

    } while (!fechaValida) ;

    // resto de logica de cargar()

    cout << "Estado de Entrega (1- Pendiente, 2- En curso, 3- Entregado): " ;

    cin >> estadoEntrega ;

    setEstado_Entrega(estadoEntrega) ;

    cout << "Valor (en pesos) del Envio: $" ;

    cin >> valorEnvio ;

    setValor_Envio(valorEnvio) ;

    cout << endl ;

    // Estado se mantiene en TRUE (Activo) por defecto
}

void Envio::mostrar() const
{

    cout << endl << "DATOS DEL ENVIO:" << endl ;

    cout << "ID Envio: " << getID_Envio() << endl ;

    cout << "ID Venta Asociada: " << getID_Venta() << endl ;

    cout << "Fecha de Entrega: " ;

    getFecha_Entrega().mostrar() ;

    cout << endl << "Valor del Envio: $" << getValor_Envio() << endl ;

    // Traducción del estado numérico a texto legible

    cout << "Estado de Entrega: " ;

    switch (getEstado_Entrega())
    {

    case 1:
        cout << "Pendiente" << endl ;
        break ;

    case 2:
        cout << "En curso" << endl ;
        break ;

    case 3:
        cout << "Entregado" << endl ;
        break ;

    default:
        cout << "Desconocido" << endl ;
        break ;

    }

    cout << "Estado del envio: " << (getEstado() ? "Activo" : "Dado de baja") << endl ;

    cout << "-------------------------------" << endl ;



}


/* void Envio::modificarCampos() {

    EnvioArchivo archivo ;

    int id_a_buscar ;

    int opcion ;

    string nuevo_dato_str ;

    float nuevo_dato_float ;

    int nuevo_dato_int ;

    cout << "-------------------------------------------" << endl ;

    cout << "Ingrese el ID del envio a modificar: " ;

    cin >> id_a_buscar ;

    cin.ignore() ;

    int pos = archivo.buscarPosicion(id_a_buscar) ;

    if (pos == -1) {

        cout << "ERROR: ID de envío no encontrado." << endl ;

        system("pause") ;

        return ; }

    *this = archivo.leer(pos) ;


    do {

        system("cls") ;

        cout << "ENVIO a Modificar (ID: " << this->getID_Envio() << "):" << endl ;

        cout << "-----------------------------" << endl ;

        this->mostrar() ;

        cout << endl << "Seleccione el campo a modificar:" << endl ;

        cout << "1. Fecha de entrega" << endl ;

        cout << "2. Valor del envio" << endl ;

        cout << "3. Estado del envio" << endl ;

        cout << "0. Volver al menu anterior " << endl ;

        cout << endl << "Opcion: " ;

        cin >> opcion ;

        cout << endl ;

        switch (opcion) {


            case 1: { // Modificar Fecha de Entrega (Corrección del tipo de dato)

                int dia, mes, anio ;

                Fecha nueva_fecha ; // 1. Creamos un objeto Fecha

                cout << "Ingrese nueva Fecha de Entrega" << endl ;

                cout << "Dia: " ;

                cin >> dia ;

                cout << "Mes: " ;

                cin >> mes ;

                cout << "Año: " ;

                cin >> anio ;

                nueva_fecha.setDia(dia) ;

                nueva_fecha.setMes(mes) ;

                nueva_fecha.setAnio(anio) ;

                this->setFecha_Entrega(nueva_fecha) ;

                if (archivo.modificar(*this)) {

                    cout << endl << "Fecha de entrega modificada y guardada con exito." << endl ;

                } else {

                    cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;

                }
                system("pause") ;

                break ;
            }

            case 2: { // Modifico valor del envio

                float nuevo_valor ;

                cout << "Nuevo Valor del envio: $" ;

                cin >> nuevo_valor ;

                this->setValor_Envio(nuevo_valor) ;

                if (archivo.modificar(*this)) {

                    cout << endl << "Valor del envio modificado y guardado con exito." << endl ;

                } else {

                    cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
                }

                system("pause") ;

                break ;
            }

            case 3: { // Modificar Estado del Envío

                cout << "Nuevo Estado (1-Pendiente, 2-En curso, 3-Entregado): " ;

                cin >> nuevo_dato_int ;


                this->setEstado_Entrega(nuevo_dato_int) ; // Asumo que tienes setEstado_Entrega

                if (archivo.modificar(*this)) {

                    cout << endl << "Estado del envio modificado y guardado con exito." << endl ;

                } else {

                    cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;

                }

                system("pause") ;

                break ;
            }



            case 0: // Volver

                cout << "Volviendo al menu anterior." << endl ;

                return ;

                break ;

            default:

                cout << "Opcion invalida. Intente de nuevo." << endl ;

                system("pause") ;
        }

    } while (opcion != 5) ;

    cout << "Todos los cambios han sido aplicados y guardados en el archivo." << endl ;

    system("pause") ;
}
*/
