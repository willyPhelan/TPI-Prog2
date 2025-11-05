#pragma once
#include "Fecha.h"


class Envio {


public:

    Envio() ; // constructor

    Envio(int idVenta, Fecha fecha, int estado, float valor, bool activo) ;

    // getters

    int getID_Envio() const ;

    int getID_Venta() const ;

    Fecha getFecha_Entrega() const ;

    int getEstado_Entrega() const ;

    float getValor_Envio() const ;

    bool getEstado() const ;

    // setters

    void setID_Envio(int idEnvio) ;

    void setID_Venta(int id_venta);

    void setFecha_Entrega(const Fecha& fecha) ;

    void setEstado_Entrega(int estado) ;

    void setValor_Envio(float valor) ;

    void setEstado(bool activo) ;

    // metodos

    void cargar() ;

    void mostrar() const ;


private:

    int ID_Envio ; //PREGUNTAR PROFE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    int ID_Venta ;

    Fecha fecha_Entrega ;

    int estado_Entrega ;

    float valor_Envio ;

    bool estado ;





};
