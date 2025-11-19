#pragma once
#include "ProductoArchivo.h"

class Detalle_Venta
{

public:

// Constructores

    Detalle_Venta() ;

// Constructor con parámetros

    Detalle_Venta(int idDetalle, int idProducto, int idVenta, int cantidad, float precio, bool activo = true) ;

//GETTERS

    int getID_Detalle() const ;

    int getID_Producto() const ;

    int getID_Venta() const ;

    int getCantidad() const ;

    float getPrecio_Unitario() const ;

    bool getEstado() const ;

// SETTERS

    void setID_Detalle(int idDetalle) ;

    void setID_Producto(int idProducto) ;

    void setID_Venta(int idVenta) ;

    void setCantidad(int cantidad) ;

    void setPrecio_Unitario(float precio) ;

    void setEstado(bool activo) ;

// MÉTODOS

    void cargar() ;

    void mostrar() const ;


private:

    int ID_Detalle ;

    int ID_Producto ;

    int ID_Venta ;

    int cantidad ;

    float precio_Unitario ;

    bool estado ;




};
