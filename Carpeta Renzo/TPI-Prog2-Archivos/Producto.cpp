#include "Utils.h"
#include "Producto.h"
#include <cstring>
#include <iostream>


using namespace std ;

// constructores

Producto::Producto() // por defecto con lista de inicializacion

: ID_Producto(0), ID_Proveedor(), descripcion{}, marca{}, tipoProducto(0), precioActual(0.0), garantia(0), cantidadStock(0), estado(true)
{} // inicializo los arrays marca y descripcion vacios

// consturctor con parametros

Producto::Producto(int _id_Producto, int _id_Proveedor, const string &descripcion, const string &marca ,int _tipoProducto, float _precioActual, int _garantia, int _cantStock, bool _estado)

// Aca ID_Proveedor() llama al constructor por defecto de Proveedor

: ID_Producto(_id_Producto), ID_Proveedor(), tipoProducto(_tipoProducto), precioActual(_precioActual), garantia(_garantia), cantidadStock(_cantStock), estado(_estado)
{
 // setters para asignar cadenas de texto

    setDescripcion(descripcion) ;

    setMarca(marca) ;

}

// getters

int Producto::getID_Producto() const {

    return ID_Producto ;
}

Proveedor Producto::getID_Proveedor() const { // la funcion devuelve un proveedor (composicion)

    return ID_Proveedor ;

}

const char* Producto::getDescripcion() const {

    return descripcion ;
}

const char* Producto::getMarca() const {

    return marca ;
}

int Producto::getTipoProducto() const {

    return tipoProducto ;
}

float Producto::getPrecioActual() const {

    return precioActual ;
}

int Producto::getGarantia() const {

    return garantia ;
}

int Producto::getCantStock() const {

    return cantidadStock ;
}

bool Producto::getEstado() const {

    return estado ;
}

// setters

void Producto::setID_Producto(int _idProducto){

    ID_Producto = _idProducto ;
}

void Producto::setID_Proveedor(Proveedor ID_Proveedor){

    ID_Proveedor = ID_Proveedor ;
}

void Producto::setDescripcion(const std::string &_descripcion){

    strncpy(this->descripcion, _descripcion.c_str(), 19) ;
 }

  void Producto::setMarca(const std::string &_marca){

    strncpy(this->marca, _marca.c_str(), 19) ;
 }

 void Producto::setTipoProducto(int _tipoProducto){

    tipoProducto = _tipoProducto ;
 }

 void Producto::setPrecioActual(float _precioActual){

    precioActual = _precioActual;
 }

 void Producto::setGarantia(int _garantia){
    garantia = _garantia;
 }

 void Producto::setCantidadStock(int _cantStock){

    cantidadStock = _cantStock ;
 }

 void Producto::setEstado(bool _estado){

    this-> estado = _estado ;
 }

void Producto::cargar(){

    string str ;

  //  cout << endl << "Ingrese un ID al Producto: AUTO INCREMENTAL DESDE PRODUCTO ARCHIVO" << endl ;

    cout << "Ingrese la Marca del Producto: " ;

    str = cargarCadena() ;

    setMarca(str) ;

    cout << "Ingrese una Descripcion: " ;

    str = cargarCadena() ;

    setDescripcion(str) ;

    cout << "Ingrese Tipo de Producto (1-PCS, 2-Accesorios, 3-Otros): " ;

    cin >> tipoProducto ;

    setTipoProducto(tipoProducto) ;

    cout << "Ingrese el precio (en pesos) del producto: $"  ;

    cin >> precioActual ;

    setPrecioActual(precioActual) ;

    cout << "Ingrese la garantia (en meses) que tiene el producto: " ;

    cin >> garantia ;

    setGarantia(garantia) ;

    cout << "Ingrese la cantidad que hay del producto: " ;

    cin >> cantidadStock ;

    setCantidadStock(cantidadStock) ;

   /* cout << "Estado(1- Activo, 0- Inactivo): " ;

    cin >> estado ;

    setEstado(estado) ; */



}

void Producto::mostrar(){

    cout << "ID de producto: " << getID_Producto() << endl ;

    cout << "ID de proveedor: " << 200 << endl ;

    cout << "Descripcon: " << getDescripcion() << endl ;

    cout << "Marca: " << getMarca() << endl ;

    cout << "Tipo de producto: " << getTipoProducto() << endl ;

    cout << "Precio actual: $" << getPrecioActual() << endl ;

    cout << "Garantia del producto: " << getGarantia() << " Mes/es" << endl ;

    cout << "Cantidad del producto en stock: " << getCantStock() << endl ;

    cout << "Estado: " << (getEstado() ? "Activo" : "Inactivo") << endl << endl ;

}

