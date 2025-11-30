#include "Detalle_Venta.h"
#include <iostream>
#include "Utils.h"

using namespace std;


Detalle_Venta::Detalle_Venta()

: ID_Detalle(0), ID_Producto(0), ID_Venta(0), cantidad(0), precio_Unitario(0.0), estado(true){}


Detalle_Venta::Detalle_Venta(int idDetalle, int idProducto, int idVenta, int cantidad, float precio, bool activo)

: ID_Detalle(idDetalle), ID_Producto(idProducto), ID_Venta(idVenta), cantidad(cantidad), precio_Unitario(precio), estado(activo){}


int Detalle_Venta::getID_Detalle() const {

    return ID_Detalle ;
}

int Detalle_Venta::getID_Producto() const{

    return ID_Producto ;
}

int Detalle_Venta::getID_Venta() const{

    return ID_Venta ;
}

int Detalle_Venta::getCantidad() const{

    return cantidad ;
}

float Detalle_Venta::getPrecio_Unitario() const{

    return precio_Unitario ;
}

bool Detalle_Venta::getEstado() const{

    return estado ;
}

void Detalle_Venta::setID_Detalle(int idDetalle){
    ID_Detalle = idDetalle ;
}

void Detalle_Venta::setID_Producto(int idProducto){

    ID_Producto = idProducto ;
}

void Detalle_Venta::setID_Venta(int idVenta){

    ID_Venta = idVenta ;
}

void Detalle_Venta::setCantidad(int cantidad){

    this->cantidad = cantidad ;
}

void Detalle_Venta::setPrecio_Unitario(float precio){

    precio_Unitario = precio ;
}

void Detalle_Venta::setEstado(bool activo){

    estado = activo ;
}


void Detalle_Venta::cargar(){


    ProductoArchivo archivoP ;

    Producto regP ;

    int id, pos, cantidad_a_vender ;

    bool stock_ok = false ;

    cout << endl << "ID Producto: " ;

    cin >> id ;

    pos = archivoP.buscarPosicion(id) ;

    if (pos == -1){

        cout << "ERROR: El ID de Producto no existe." << endl ;

        return ;
    }

    regP = archivoP.leer(pos) ;

    if (regP.getEstado () == false){

        cout << "ERROR: El producto con el id " << id << " se encuentra dado de baja y no se puede agregar. Desea darlo de alta? 1-Si 2-No: " << endl;

        int opc ;

        cin >> opc ;

        if (opc == 1){

                regP.setEstado(true) ;

                archivoP.modificar(regP) ;

                cout << "Producto dado de alta" << endl ;
        }


        system ("pause") ;

        return ;
    }

    setID_Producto(id) ;

    while (!stock_ok){

        cout << "Cantidad: " ;

        cin >> cantidad_a_vender ;

        if(cantidad_a_vender > 0){

            if (cantidad_a_vender > regP.getCantStock()){

                int opc ;

                cout << "ERROR: Stock insuficiente. Solo hay " << regP.getCantStock() << " unidades disponibles." << endl ;

                cout << "Desea omitir esta carga? (1- Si, 2- No)" << endl ;

                cin >> opc ;

                while (opc != 1 && opc != 2){

                    cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl ;

                    cout << "Desea omitir esta carga? (1- Si, 2- No)" << endl ;

                    cin >> opc ; }

                if (opc == 1){ return ; }


            } else{ stock_ok = true ; }

        }
        else
        {
            cout << "Ingrese una cantidad valida:" << endl ;



        }
    }

    setCantidad(cantidad_a_vender) ;

    float unitario = archivoP.buscarPrecio(id) ;

    setPrecio_Unitario(unitario) ;
}

void Detalle_Venta::mostrar() const
{

    cout << "  - ID Detalle: " << getID_Detalle() << endl ;

    cout << "  - ID Producto: " << getID_Producto() << endl ;

    cout << "  - ID Venta Asociada: " << getID_Venta() << endl ;

    cout << "  - Cantidad: " << getCantidad() << endl ;

    cout << "  - Precio Unitario: $" << getPrecio_Unitario() << endl ;

    cout << "  - Subtotal: $" << getCantidad() * getPrecio_Unitario() << endl ;

    cout << "  - Registro Activo: " << (getEstado() ? "Si" : "No") << endl ;
}
