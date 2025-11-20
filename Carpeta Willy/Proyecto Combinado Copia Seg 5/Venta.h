#pragma once
#include <cstring>
#include "Persona.h"
#include "Fecha.h"
#include "Envio.h"
#include "Cliente.h"
#include "Detalle_Venta.h"
#include "DetalleVentaArchivo.h"


class Venta
{

private:

    int ID_Cliente ;

    int ID_Venta ;

    Persona ID_persona ;

    Fecha fechaVenta ;

    int medioDePago ;

    int tipoEnvio ;

    float subTotal ;

    float montoTotal ;

//    int tipoFactura ;

    bool estado ;


public:

    // constructores

    Venta() ;

    Venta(int id_cliente, int id_venta, int id_persona, const Fecha &fechaventa, int mediopago, int tipoenvio, float subtotal, float montototal, bool estado) ;

    // getters

    int getID_Venta() const ;

    int getID_Cliente() ;

    Persona getID_Persona() ;

    int getID_Cliente() const ;

    Fecha getFechaVenta() ;

    int getMedioPago() ;

    int getTipoEnvio() ;

    float getSubTotal() ;

    float getMontoTotal() ;

//    int getTipoFactura() ;

    bool getEstado() ;

    // setters

    void setID_Venta(int _IDventa) ;

    void setID_Cliente(int _IDCliente);

    void setID_Persona(Persona _IDPersona) ;

    void setFechaVenta(Fecha _fechaVenta) ;

    void setMedioDePago(int _medioPago) ;

    void setTipoEnvio(int _tipoEnvio) ;

    void setSubTotal(float _subTotal) ;

    void setMontoTotal(float _montoTotal) ;

 //   void setTipoFactura(int _tipoFactura) ;

    void setEstado(bool _estado) ;

    // metodos

    void cargarVenta() ;

    void mostrarVenta() ;



};

