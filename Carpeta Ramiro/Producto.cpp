#include <iostream>
#include "Producto.h"
#include <cstring>
#include "Utils.h"

using namespace std;


Producto::Producto(){
    ID_Producto(0),ID_Proveedor(0),TipoProducto(0),PrecioActual(0),Garantia(0),CantidadStock(0),Estado(true);
}
Producto::Producto(int id_Producto,int id_Proveedor,int tipoProducto,float precioActual,int garantia,int cantStock,bool estado)
:ID_Producto(id_Producto),ID_Proveedor(id_Proveedor),TipoProducto(tipoProducto),PrecioActual(precioActual),Garantia(garantia),CantidadStock(cantStock),Estado(estado)
{}

int Producto::getID_Producto(){
    return ID_Producto;
}

int Producto::getID_Proveedor(){
    return ID_Proveedor;
}
char* Producto::getDescripcion(){
    return Descripcion;
}

char* Producto::getMarca(){
    return Marca;
}
int Producto::getTipoProducto(){
    return TipoProducto;
}
float Producto::getPrecioActual(){
    return PrecioActual;
}
int Producto::getGarantia(){
    return Garantia;
}
int Producto::getCantStock(){
    return CantidadStock;
}
bool Producto::getEstado(){
    return Estado;
}

void Producto::setID_Producto(int _idProducto){
    ID_Producto = _idProducto;
}
void Producto::setID_Proveedor(Proveedor ID_Proveedor){
    ID_Proveedor = _idProveedor;
}
 void Producto::setDescripcion(const std::string &_descripcion){
    strncpy(this->Descripcion,_descripcion.c_str(),19);
 }
  void Producto::setMarca(const std::string &_marca){
    strncpy(this->Marca,_marca.c_str(),19);
 }

 void Producto::setTipoProducto(int _tipoProducto){
    TipoProducto = _tipoProducto;
 }

 void Producto::setPrecioActual(float _precioActual){
    PrecioActual = _precioActual;
 }
 void Producto::setGarantia(int _garantia){
    Garantia = _garantia;
 }
 void Producto::setCantidadStock(int _cantStock){
    CantidadStock = _cantStock;
 }
 void Producto::setEstado(bool _estado){
    this-> Estado = _estado;
 }

void Producto::cargar(){

    string str;
    cout<<"Ingrese una ID al Producto: ";
    cin>> ID_Producto; //aca igual no se debe pedir se debe generar, lo puse para verificar si esta todo bien
    setID_Producto(ID_Producto);
    cout<<"Ingrese una Descripcion: ";
    str = cargarCadena();
    setDescripcion(str);
    cout<<"Ingrese la Marca del Producto: ";
    str = cargarCadena();
    setMarca(str);
    cout<<"Ingrese Tipo de Producto: ";
    cin>> TipoProducto;
    setTipoProducto(TipoProducto);
    cout<<"Ingrese el Precio del Producto: ";
    cin>>PrecioActual;
    setPrecioActual(PrecioActual);
    cout<<"Ingrese la Garantia que tiene el Producto: ";
    cin>>Garantia;
    setGarantia(Garantia);
    cout<<"Ingrese la Cantidad que hay del Producto: ";
    cin>>CantidadStock;
    setCantidadStock(CantidadStock);
    cout << "Estado (1- Activo / 0- Inactivo): " ;
    cin >>Estado;
    setEstado(Estado);


    system("cls");

}

void Producto::Mostrar(){
    cout<<"ID de Producto: "<<getID_Producto()<< endl;
    cout<<"ID de Proveedor: "<<200<< endl;
    cout<<"Descripcon: "<<getDescripcion()<< endl;
    cout<<"Marca: "<<getMarca()<< endl;
    cout<<"Tipo de Producto: "<<getTipoProducto()<< endl;
    cout<<"Precio Actual: "<<getPrecioActual()<< endl;
    cout<<"Garantia del Producto: "<<getGarantia()<<" Meses"<< endl;
    cout<<"Cantidad del Producto en stock: "<<getCantStock()<< endl;
    cout<<"Estado: "<< (getEstado() ? "Si" : "No") << endl << endl ;

}

