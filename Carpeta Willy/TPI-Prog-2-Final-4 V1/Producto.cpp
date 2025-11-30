#include "Utils.h"
#include "Producto.h"
#include "ProductoArchivo.h"
#include "Utils.h"
#include <cstring>
#include <iostream>


using namespace std ;


Producto::Producto()

    : ID_Producto(0), ID_Proveedor(), descripcion{}, marca{}, tipoProducto(0), precioActual(0.0), garantia(0), cantidadStock(0), estado(true)
{}



Producto::Producto(int _id_Producto, int _id_Proveedor, const string &descripcion, const string &marca,int _tipoProducto, float _precioActual, int _garantia, int _cantStock, bool _estado)



    : ID_Producto(_id_Producto), ID_Proveedor(), tipoProducto(_tipoProducto), precioActual(_precioActual), garantia(_garantia), cantidadStock(_cantStock), estado(_estado)
{


    setDescripcion(descripcion) ;

    setMarca(marca) ;

}



int Producto::getID_Producto() const
{

    return ID_Producto ;
}

int Producto::getID_Proveedor() const
{

    return ID_Proveedor ;

}

const char* Producto::getDescripcion() const
{

    return descripcion ;
}

const char* Producto::getMarca() const
{

    return marca ;
}

int Producto::getTipoProducto() const
{

    return tipoProducto ;
}

float Producto::getPrecioActual() const
{

    return precioActual ;
}

int Producto::getGarantia() const
{

    return garantia ;
}

int Producto::getCantStock() const
{

    return cantidadStock ;
}

bool Producto::getEstado() const
{

    return estado ;
}


void Producto::setID_Producto(int _idProducto)
{

    ID_Producto = _idProducto ;
}

void Producto::setID_Proveedor(int id_Proveedor)
{

    this->ID_Proveedor = id_Proveedor ;
}

void Producto::setDescripcion(const std::string &_descripcion)
{
    const int MAX_LEN = sizeof(this->descripcion) - 1 ;

    strncpy(this->descripcion, _descripcion.c_str(), MAX_LEN) ;

    this->descripcion[MAX_LEN] = '\0' ;
}

void Producto::setMarca(const std::string &_marca)
{

    const int MAX_LEN = sizeof(this->marca) - 1 ;

    strncpy(this->marca, _marca.c_str(), MAX_LEN) ;

    this->marca[MAX_LEN] = '\0' ;
}

void Producto::setTipoProducto(int _tipoProducto)
{

    tipoProducto = _tipoProducto ;
}

void Producto::setPrecioActual(float _precioActual)
{

    precioActual = _precioActual;
}

void Producto::setGarantia(int _garantia)
{
    garantia = _garantia;
}

void Producto::setCantidadStock(int _cantStock)
{

    cantidadStock = _cantStock ;
}

void Producto::setEstado(bool _estado)
{

    this-> estado = _estado ;
}

void Producto::cargar()
{

    ProductoArchivo archivoProd ;

    Producto productoExistente ;

    ProveedorArchivo archivoProv ;

    string str ;

    string descripcionNueva ;

    int idProveedor ;

    bool descValida = false ;

    do{

        cout << "Ingrese la descripcion del producto: " ;

        descripcionNueva = cargarCadena()  ;

        descValida = archivoProd.validarDescripcion(descripcionNueva) ;

        if(descValida == false) {

            int opc ;

            cout << "Desea salir o continuar con otra descripcion? 1-Salir 2-Continuar: " << endl ;

            cin >> opc ;

            if(opc == 1) {

                return  ;
            }
        }

         }


    while (!archivoProd.validarDescripcion(descripcionNueva) ) ;


    this->setDescripcion(descripcionNueva) ;



    setID_Producto(archivoProd.obtenerID()) ;

    cout << "Ingrese la marca del producto: " ;

    str = cargarCadena() ;

    setMarca(str) ;



    int posProveedor = -1 ;

    cout << "Ingrese el ID del proveedor:"  ;

    while (posProveedor == -1)
    {

        cin >> idProveedor ;

        posProveedor = archivoProv.buscarPosicion(idProveedor) ;

        if (posProveedor == -1)
        {

            cout << "ERROR: El ID del proveedor no existe." << endl;

            cout << "Ingrese un ID del proveedor valido: ";
        }
    }


    this->setID_Proveedor(idProveedor);

    cout << "Ingrese Tipo de Producto (1-PCS, 2-Accesorios, 3-Otros): " ;

    cin >> tipoProducto ;

    while (tipoProducto < 1 || tipoProducto > 3)
    {

        cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

        cout << "Ingrese Tipo de Producto (1-PCS, 2-Accesorios, 3-Otros): " ;

        cin >> tipoProducto ;

    }

    setTipoProducto(tipoProducto) ;

    cout << "Ingrese el precio del producto: $" ;

    cin >> precioActual ;

    setPrecioActual(precioActual) ;

    cout << "Ingrese la garantia (en meses) que tiene el producto: " ;

    cin >> garantia ;

    setGarantia(garantia) ;

    cout << "Ingrese la cantidad que hay del producto: " ;

    cin >> cantidadStock ;

    while (cantidadStock <= 0)
    {

        cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

        cout << "Ingrese la cantidad que hay del producto: " ;

        cin >> cantidadStock ;

    }

    setCantidadStock(cantidadStock) ;

    if (archivoProd.guardar(*this))
    {

        cout << endl << "Producto cargado con exito." << endl ;
    }
    else
    {

        cout << "ERROR: No se pudo guardar el producto en el archivo." << endl ;
    }



}


void Producto::mostrar()
{

    cout << "ID de producto: " << getID_Producto() << endl ;

    cout << "ID de proveedor: " << getID_Proveedor() << endl ;

    cout << "Descripcon: " << getDescripcion() << endl ;

    cout << "Marca: " << getMarca() << endl ;

    switch (getTipoProducto())
    {

    case 1:
    {

        cout << "Tipo de producto: PCs (1)" << endl;

        break;

    }

    case 2:
    {

        cout << "Tipo de producto: Accesorio (2)" << endl;

        break;

    }
    case 3:
    {

        cout << "Tipo de producto: Otros (3)" << endl;

        break;

    }
    default:
    {

        cout << "Tipo de producto: Desconocido" << endl;

        break;

    }
    }

    cout << "Precio actual: $" << getPrecioActual() << endl ;

    cout << "Garantia del producto: " << getGarantia() << " Mes/es" << endl ;

    cout << "Cantidad del producto en stock: " << getCantStock() << endl ;

    cout << "Estado: " << (getEstado() ? "Activo" : "Inactivo") << endl ;

}


