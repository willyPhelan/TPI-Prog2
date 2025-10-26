#include <iostream>
#include <cstring>
#include "Persona.h"
#include "Fecha.h"
#include "Ventas.h"

using namespace std;

Venta::Venta()
: ID_Venta(0),ID_persona(),FechaVenta(0),MedioDePago(0),TipoEnvio(0),SubTotal(0),MontoTotal(0),TipoFactura(0),Estado(true)
{}

Venta::Venta(int id_venta,const Persona& id_persona,const Fecha& fechaventa,int mediopago,int tipoenvio,float subtotal,float montototal,int tipofactura,bool estado)
:ID_Venta(id_venta),ID_persona(id_persona),FechaVenta(fechaventa),MedioDePago(mediopago),TipoEnvio(tipoenvio),SubTotal(subtotal),MontoTotal(montototal),TipoFactura(tipofactura),Estado(estado)
{}

int Venta::getID_Venta(){
    return ID_Venta;
}

const Persona& Venta::getID_Persona(){
    return ID_persona;
}

const Fecha& Venta::getFechaVenta(){
    return FechaVenta;
}

int Venta::getMedioPago(){
    return MedioDePago;
}

int Venta::getTipoEnvio(){
    return TipoEnvio;
}

float Venta::getSubTotal(){
    return SubTotal;
}

float Venta::getMontoTotal(){
    return MontoTotal;
}

int Venta::getTipoFactura(){
    return TipoFactura;
}

bool Venta::getEstado(){
    return Estado;
}

void Venta::setID_Venta(int _IDventa){
    ID_Venta = _IDventa;
}
void Venta::setID_Persona(const Persona& _IDPersona){
    ID_persona = _IDPersona;
}
void Venta::setFechaVenta(const Fecha& _fechaVenta){
    FechaVenta = _fechaVenta;
}
void Venta::setMedioDePago(int _medioPago){
    MedioDePago = _medioPago;
}
void Venta::setTipoEnvio(int _tipoEnvio){
    TipoEnvio = _tipoEnvio;
}
void Venta::setSubTotal(float _subTotal){
    SubTotal = _subTotal;
}
void Venta::setMontoTotal(float _montoTotal){
    MontoTotal = _montoTotal;
}
void Venta::setTipoFactura(int _tipoFactura){
    TipoFactura = _tipoFactura;
}
void Venta::setEstado(bool _estado){
    Estado = _estado;
}

void Venta::cargarVenta(){
    int num;
    cout<<"ID_Venta: ";
    cin>>num;
    setID_Venta(num);
    cout<<"Medio de Pago: ";
    cin>>num;
    setMedioDePago(num);
    cout<<"Tipo Envio(1/Domicilio o 0/Retiro en Local): ";
    cin>>num;
    setTipoEnvio(num);
    cout<<"SubTotal: ";
    cin>>num;
    setSubTotal(num);
    cout<<"Monto Total: ";
    cin>>num;
    setMontoTotal(num);
    cout<<"TipoFactura: ";
    cin>>num;
    setTipoFactura(num);

}

void Venta::mostrarVenta(){
    cout<<"ID_Venta: "<<getID_Venta()<<endl;
    cout<<"Medio de Pago: "<<getMedioPago()<<endl;
    cout<<"Tipo Envio: "<<getTipoEnvio()<<endl;
    cout<<"Sub Total: "<<getSubTotal()<<endl;
    cout<<"Monto Total: "<<getMontoTotal()<<endl;
    cout<<"Tipo de Factura: "<<getTipoFactura()<<endl;
}
