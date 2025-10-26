#include "Venta.h"
#include <iostream>
#include <cstring>

using namespace std ;

// consturcotres

// constructor por defecto

Venta::Venta()

: ID_Venta(0), ID_persona(), fechaVenta(), medioDePago(0), tipoEnvio(0), subTotal(0.0), montoTotal(0.0), tipoFactura(0), estado(true)

{}

// constructor con parametros

Venta::Venta(int id_venta, int id_persona, const Fecha &_fechaVenta, int _mediopago, int _tipoEnvio, float _subtotal, float _montoTotal, int _tipoFactura, bool _estado)

// Inicializa miembros de objeto con sus constructores por defecto.

:ID_Venta(id_venta), ID_persona(), fechaVenta(_fechaVenta), medioDePago(_mediopago), tipoEnvio(_tipoEnvio), subTotal(_subtotal), montoTotal(_montoTotal), tipoFactura(_tipoFactura), estado(_estado)
{
    // Lógica para asignar el ID a la Persona (ya que el miembro es un objeto)

    ID_persona.setID(id_persona) ; }



// getters

int Venta::getID_Venta(){

    return ID_Venta ;
}

Persona Venta::getID_Persona(){ // composicion Persona

    return ID_persona ;
}

Fecha Venta::getFechaVenta(){

    return fechaVenta ;
}

int Venta::getMedioPago(){

    return medioDePago ;
}

int Venta::getTipoEnvio(){

    return tipoEnvio ;
}

float Venta::getSubTotal(){

    return subTotal ;
}

float Venta::getMontoTotal(){

    return montoTotal ;
}

int Venta::getTipoFactura(){

    return tipoFactura ;
}

bool Venta::getEstado(){

    return estado ;
}

// setters

void Venta::setID_Venta(int _IDventa){

    ID_Venta = _IDventa ;
}

void Venta::setID_Persona(Persona _IDPersona){

    ID_persona = _IDPersona ;
}

void Venta::setFechaVenta(Fecha _fechaVenta){

    fechaVenta = _fechaVenta ;
}

void Venta::setMedioDePago(int _medioPago){

    medioDePago = _medioPago ;
}

void Venta::setTipoEnvio(int _tipoEnvio){

    tipoEnvio = _tipoEnvio ;
}

void Venta::setSubTotal(float _subTotal){

    subTotal = _subTotal ;

}

void Venta::setMontoTotal(float _montoTotal){

    montoTotal = _montoTotal ;

}

void Venta::setTipoFactura(int _tipoFactura){

    tipoFactura = _tipoFactura ;

}

void Venta::setEstado(bool _estado){

    estado = _estado ;
}

void Venta::cargarVenta(){

    int num ;

    cout << "Carga de una venta" << endl ;

    cout << "-------------------------------" << endl ;

    cout << "ID VENTA TIENE QUE SER AUTOINCRMENTAL DESDE ARCHIVO VENTA" << endl ;

    cout << "Medio de pago: " ;

    cin >> num ;

    setMedioDePago(num) ;

    cout << "Tipo de envio: (1- Domicilio, 0- Retiro en Local): " ;

    cin >> num ;

    setTipoEnvio(num) ;

    cout << "Subtotal: " ;

    cin >> num ;

    setSubTotal(num) ;

    cout << "Monto total: " ;

    cin >> num ;

    setMontoTotal(num) ;

    cout << "Tipo de factura (1- Factura A, 2- Factura B, 3- Factura C): " ;

    cin >> num ;

    setTipoFactura(num) ;

}

void Venta::mostrarVenta(){

    cout << "ID_Venta: " <<getID_Venta() << endl ;

    cout << "Medio de pago: " <<getMedioPago() << endl ;

    cout << "Tipo de envio: " << getTipoEnvio() << endl ;

    cout << "Subtotal: " << getSubTotal() << endl ;

    cout << "Monto total: " << getMontoTotal() << endl ;

    cout << "Tipo de factura: " << getTipoFactura() << endl ;
}
