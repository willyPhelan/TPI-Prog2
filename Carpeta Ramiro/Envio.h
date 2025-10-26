#pragma once
#include "Fecha.h"
#include "Ventas.h"

class Envio {


public:

    Envio() ; // constructor

    Envio(const Venta& idVenta,const Fecha& fecha, int estado, float valor, bool activo) ;

    // getters

    Venta getID_Venta() const ;

    Fecha getFecha_Entrega() const ;

    int getEstado_Entrega() const ;

    float getValor_Envio() const ;

    bool getEstado() const ;

    // setters

    void setID_Venta(const Venta& idVenta) ;

    void setFecha_Entrega(const Fecha& fecha) ;

    void setEstado_Entrega(int estado) ;

    void setValor_Envio(float valor) ;

    void setEstado(bool activo) ;

    // metodos

    void cargar() ;

    void mostrar() const ;

private:

    Venta ID_Venta;

    Fecha fecha_Entrega; // composicion Fecha

    int estado_Entrega ;

    float valor_Envio ;

    bool estado ;






};
