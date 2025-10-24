#include "Ventas.h"
#include <iostream>
#include <cstring>

using namespace std;

int Ventas::getID_Venta(){
    return ID_Venta;
}

int Ventas::getID_Persona(){
    return ID_persona
}

int Ventas::getFechaVenta(){
    return FechaVenta;
}

int Ventas::getMedioPago(){
    return MedioDePago;
}

int Ventas::getTipoEnvio(){
    return TipoEnvio;
}

float Ventas::getSubTotal(){
    return SubTotal;
}

float Ventas::getMontoTotal(){
    return MontoTotal;
}

int Ventas::getTipoFactura(){
    return TipoFactura;
}

bool Ventas::getEstado(){
    return Estado;
}

void Ventas::setID_Venta(int _IDventa){
    ID_Venta = _IDventa;
}
void Ventas::setID_Persona(Persona _IDPersona){
    ID_persona = _IDPersona;
}
void Ventas::setFechaVenta(Fecha _fechaVenta){
    FechaVenta = _fechaVenta;
}
void Ventas::setMedioDePago(int _medioPago){
    MedioDePago = _medioPago;
}
void Ventas::setTipoEnvio(int _tipoEnvio){
    TipoEnvio = _tipoEnvio;
}
void Ventas::setSubTotal(float _subTotal){
    SubTotal = _subTotal;
}
void Ventas::setMontoTotal(float _montoTotal){
    MontoTotal = _montoTotal;
}
void Ventas::setTipoFactura(int _tipoFactura){
    TipoFactura = _tipoFactura;
}
void Ventas::setEstado(bool _estado){
    Estado = _estado;
}

void Ventas::cargarVenta(){
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

void Ventas::mostrarVenta(){
    cout<<"ID_Venta: "<<getID_Venta()<<endl;
    cout<<"Medio de Pago: "<<getMedioPago()<<endl;
    cout<<"Tipo Envio: "<<getTipoEnvio()<<endl;
    cout<<"Sub Total: "<<getSubTotal()<<endl;
    cout<<"Monto Total: "<<getMontoTotal()<<endl;
    cout<<"Tipo de Factura: "<<getTipoFactura()<<endl;
}
