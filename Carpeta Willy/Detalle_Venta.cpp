#include "Detalle_Venta.h"
#include <iostream>
#include "Utils.h"

using namespace std;

// 1. CONSTRUCTORES

// Constructor por defecto

Detalle_Venta::Detalle_Venta()
 : ID_Detalle(0), ID_Producto(0), ID_Venta(0), cantidad(0), precio_Unitario(0.0f), estado(true) // Estado Activo por defecto
{}

// Constructor con par�metros

Detalle_Venta::Detalle_Venta(int idDetalle, int idProducto, int idVenta, int cantidad, float precio, bool activo)
 : ID_Detalle(idDetalle), ID_Producto(idProducto), ID_Venta(idVenta), cantidad(cantidad), precio_Unitario(precio), estado(activo)
{}


//GETTERS

int Detalle_Venta::getID_Detalle() const {

    return ID_Detalle ;
}

int Detalle_Venta::getID_Producto() const {

    return ID_Producto ;
}

int Detalle_Venta::getID_Venta() const {

    return ID_Venta ;
}

int Detalle_Venta::getCantidad() const {

    return cantidad ;
}

float Detalle_Venta::getPrecio_Unitario() const {

    return precio_Unitario ;
}

bool Detalle_Venta::getEstado() const {

    return estado ;
}

// SETTERS


void Detalle_Venta::setID_Detalle(int idDetalle) {

    ID_Detalle = idDetalle ;
}

void Detalle_Venta::setID_Producto(int idProducto) {

    ID_Producto = idProducto ;
}

void Detalle_Venta::setID_Venta(int idVenta) {

    ID_Venta = idVenta ;
}

void Detalle_Venta::setCantidad(int cantidad) {

    this->cantidad = cantidad ;
}

void Detalle_Venta::setPrecio_Unitario(float precio) {

    precio_Unitario = precio ;
}

void Detalle_Venta::setEstado(bool activo) {

    estado = activo ;
}


// M�TODOS


void Detalle_Venta::cargar() {

    // El ID_Producto y el ID_Venta Tiene que ir por composicion de las respectivas clases y ID_detalle de esta clase (lo genera el archivo)???
    // Solo pedimos los datos necesarios al usuario.

    ProductoArchivo archivoP;

    int num ;

    int id ;

    float precio ;

    // ID Detalle

    cout << endl << "ID Producto: " ;

    cin >> id;

    setID_Producto(id);

    // Cantidad

    cout << "Cantidad: ";

    cin >> num ;

    setCantidad(num);

    float unitario = archivoP.buscarPrecio(id) ;

    setPrecio_Unitario(unitario) ;
}

void Detalle_Venta::mostrar() const {

    cout << "  - ID Detalle: " << getID_Detalle() << endl ;

    cout << "  - ID Producto: " << getID_Producto() << endl ;

    cout << "  - ID Venta Asociada: " << getID_Venta() << endl ;

    cout << "  - Cantidad: " << getCantidad() << endl ;

    cout << "  - Precio Unitario: $" << getPrecio_Unitario() << endl ;

    cout << "  - Subtotal: $" << getCantidad() * getPrecio_Unitario() << endl ;

    cout << "  - Registro Activo: " << (getEstado() ? "Si" : "No") << endl ;
}
