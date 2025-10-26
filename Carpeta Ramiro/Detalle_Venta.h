#pragma once
#include "Producto.h"
#include "Ventas.h"

class Detalle_Venta {

public:

// Constructores

Detalle_Venta() ;

// Constructor con parámetros

Detalle_Venta(int idDetalle,const Producto& idProducto,const Venta& idVenta, int cantidad, float precio, bool activo = true) ;

//GETTERS

    int getID_Detalle() const ;

    Producto getID_Producto() const ;

    Venta getID_Venta() const ;

    int getCantidad() const ;

    float getPrecio_Unitario() const ;

    bool getEstado() const ;

// SETTERS

    void setID_Detalle(int idDetalle) ;

    void setID_Producto(const Producto& idProducto) ;

    void setID_Venta(const Venta& idVenta) ;

    void setCantidad(int cantidad) ;

    void setPrecio_Unitario(float precio) ;

    void setEstado(bool activo) ;

// MÉTODOS

    void cargar() ;

    void mostrar() const ;


private:

    int ID_Detalle ;
    Producto ID_Producto ;
    Venta ID_Venta ;
    int cantidad ;
    float precio_Unitario ;
    bool estado ;




};
