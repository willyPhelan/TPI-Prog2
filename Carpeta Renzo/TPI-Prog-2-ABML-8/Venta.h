#pragma once
#include <cstring>
#include "Persona.h"
#include "Fecha.h"
#include "Envio.h"
#include "Detalle_Venta.h"
#include "DetalleVentaArchivo.h"


class Venta
{

private:

    int ID_Venta ;

    int ID_Cliente ;

    Persona ID_persona ;

    Fecha fechaVenta ;

    int medioDePago ;

    int tipoEnvio ;

    float subTotal ;

    float montoTotal ;

    int tipoFactura ;

    bool estado ;


public:

    // constructores

    Venta() ;

    Venta(int id_venta, int id_persona, const Fecha &fechaventa, int mediopago, int tipoenvio, float subtotal, float montototal, int tipofactura, bool estado) ;

    // getters

    int getID_Venta() const ;

    Persona getID_Persona() ;

    int getID_Cliente() const ;

    Fecha getFechaVenta() ;

    int getMedioPago() ;

    int getTipoEnvio() ;

    float getSubTotal() ;

    float getMontoTotal() ;

    int getTipoFactura() ;

    bool getEstado() ;

    // setters

    void setID_Venta(int _IDventa) ;

    void setID_Persona(Persona _IDPersona) ;

    void setID_Cliente(int _IDcliente) ;

    void setFechaVenta(Fecha _fechaVenta) ;

    void setMedioDePago(int _medioPago) ;

    void setTipoEnvio(int _tipoEnvio) ;

    void setSubTotal(float _subTotal) ;

    void setMontoTotal(float _montoTotal) ;

    void setTipoFactura(int _tipoFactura) ;

    void setEstado(bool _estado) ;

    // metodos

    void cargarVenta() ;

    void mostrarVenta() ;



};

