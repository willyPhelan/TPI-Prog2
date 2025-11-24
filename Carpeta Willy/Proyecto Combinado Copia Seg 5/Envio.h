#pragma once
#include "Fecha.h"


class Envio
{


public:

    Envio() ;

    Envio(int idVenta, Fecha fecha, int estado, float valor, bool activo) ;

    int getID_Envio() const ;

    int getID_Venta() const ;

    Fecha getFecha_Entrega() const ;

    int getEstado_Entrega() const ;

    float getValor_Envio() const ;

    bool getEstado() const ;

    void setID_Envio(int idEnvio) ;

    void setID_Venta(int id_venta);

    void setFecha_Entrega(const Fecha& fecha) ;

    void setEstado_Entrega(int estado) ;

    void setValor_Envio(float valor) ;

    void setEstado(bool activo) ;

    void cargar() ;

    void mostrar() const ;


private:

    int ID_Envio ;

    int ID_Venta ;

    Fecha fecha_Entrega ;

    int estado_Entrega ;

    float valor_Envio ;

    bool estado ;





};
