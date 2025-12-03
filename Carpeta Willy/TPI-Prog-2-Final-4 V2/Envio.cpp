#include "Envio.h"
#include "Fecha.h"
#include "Utils.h"
#include <iostream>
#include "EnvioArchivo.h"
#include "VentaArchivo.h"


using namespace std ;


Envio::Envio()

: ID_Envio(0), estado_Entrega(0), valor_Envio(0.0f), estado(true){}


Envio::Envio(int idEnvio, Fecha fecha, int estado, float valor, bool activo)

: ID_Envio(idEnvio), fecha_Entrega(fecha), estado_Entrega(estado), valor_Envio(valor), estado(activo){}



int Envio::getID_Envio() const {

    return ID_Envio ;
}

int Envio::getID_Venta() const {

    return ID_Venta ;
}

Fecha Envio::getFecha_Entrega() const {

    return fecha_Entrega ;
}

int Envio::getEstado_Entrega() const {

    return estado_Entrega ;
}

float Envio::getValor_Envio() const {

    return valor_Envio ;
}

bool Envio::getEstado() const {

    return estado ;
}

void Envio::setID_Envio(int idEnvio){

    ID_Envio = idEnvio ;
}

void Envio::setID_Venta(int id_venta){

    ID_Venta = id_venta ;
}

void Envio::setFecha_Entrega(const Fecha& fecha){

    fecha_Entrega = fecha ;
}

void Envio::setEstado_Entrega(int estado){

    estado_Entrega = estado ;
}

void Envio::setValor_Envio(float valor){

    valor_Envio = valor ;
}

void Envio::setEstado(bool activo){

    estado = activo ;
}


void Envio::cargar(){

    VentaArchivo archivoVenta ;

    Venta ventaAsociada ;

    int posVenta = archivoVenta.buscarPosicion(getID_Venta()) ;

    if (posVenta == -1){

        cout << "ERROR: Venta asociada (ID " << getID_Venta() << ") no encontrada. No se puede validar la fecha." << endl ; }

    else {

        ventaAsociada = archivoVenta.leer(posVenta) ; }

        Fecha fechaVenta = ventaAsociada.getFechaVenta() ;

    int estadoEntrega ;

    float valorEnvio ;

    bool fechaValida = false ;

    do {

        Fecha fecha ;

        int dia, mes, anio ;

        cout << endl << "-----------------------------------" << endl ;

        cout << "Dia de entrega: " ;

        cin >> dia ;

        while (dia < 1 || dia > 31){

            cout << "El dia que ingreso es invalido. Intentelo de nuevo." << endl ;

            cout << "Dia: " ;

            cin >> dia ; }

        cout << "Mes de entrega: " ;

        cin >> mes ;

        while (mes < 1 || mes > 12){

            cout << "El mes que ingreso es invalido. Intentelo de nuevo." << endl;

            cout << "Mes: " ;

            cin >> mes ; }

        cout << "Anio de entrega: " ;

        cin >> anio ;

        while (anio < 2000 || anio > 2025){

            cout << "El anio que ingreso es invalido. Intentelo de nuevo." << endl ;

            cout << "Anio: " ;

            cin >> anio ; }

        fecha.setDia(dia) ;

        fecha.setMes(mes) ;

        fecha.setAnio(anio) ;

        if (fecha.esMayorOIgualA(fechaVenta)){

            setFecha_Entrega(fecha) ;

            fechaValida = true ; }

            else {

            cout << endl << "ERROR: La fecha de entrega (" ;

            fecha.mostrar() ;

            cout << ") debe ser IGUAL O POSTERIOR a la fecha de la venta (" ;

            fechaVenta.mostrar() ;

            cout << "). Intente de nuevo." << endl << endl ;
        }

    }

    while (!fechaValida) ;

    cout << "Estado de Entrega (1- Pendiente, 2- En curso, 3- Entregado): " ;

    cin >> estadoEntrega ;

    setEstado_Entrega(estadoEntrega) ;

    cout << "Valor (en pesos) del Envio: $" ;

    cin >> valorEnvio ;

    setValor_Envio(valorEnvio) ;

    cout << endl ;
}

void Envio::mostrar() const{

    cout << endl << "DATOS DEL ENVIO:" << endl ;

    cout << "ID Envio: " << getID_Envio() << endl ;

    cout << "ID Venta Asociada: " << getID_Venta() << endl ;

    cout << "Fecha de Entrega: " ;

    getFecha_Entrega().mostrar() ;

    cout << endl << "Valor del Envio: $" << getValor_Envio() << endl ;

    cout << "Estado de Entrega: " ;

    switch (getEstado_Entrega()){

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
