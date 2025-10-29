#pragma once
#include <cstring>
#include "Proveedor.h"

class Producto{

    private:

        int ID_Producto ;

        int ID_Proveedor ;

        char descripcion[200] ;

        char marca[20] ;

        int tipoProducto ;

        float precioActual ;

        int garantia ;

        int cantidadStock ;

        bool estado ;

    public:

        // constructores

        Producto() ;

        Producto(int id_Producto, int id_Proveedor, const std::string &descripcion, const std::string &marca ,int tipoProducto, float precioActual, int garantia, int cantStock, bool estado=true) ;

       // getters

        int getID_Producto() const ;

        int getID_Proveedor() const ;

        const char* getDescripcion() const ;

        const char* getMarca() const ;

        int getTipoProducto() const ;

        float getPrecioActual() const ;

        int getGarantia() const ;

        int getCantStock() const ;

        bool getEstado() const ;

        // setters

        void setID_Producto(int _idProducto) ;

        void setID_Proveedor(int _idProveedor) ;

        void setDescripcion(const std::string &_descripcion) ;

        void setMarca(const std::string &_marca) ;

        void setTipoProducto(int _tipoProducto) ;

        void setPrecioActual(float _precioActual) ;

        void setGarantia(int _garantia) ;

        void setCantidadStock(int _cantStock) ;

        void setEstado(bool _estado) ;

        void cargar() ;

        void mostrar() ;

};


