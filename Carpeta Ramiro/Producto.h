#pragma once
#include <cstring>

class Producto
{
    private:
        int ID_Producto;
        Proveedor ID_Proveedor;
        char Descripcion[200];
        char Marca[20];
        int TipoProducto;
        float PrecioActual;
        int Garantia;
        int CantidadStock;
        bool Estado;
    public:

        Producto();
        Producto(int id_Producto,int id_Proveedor,const std::string &descripcion,const std::string &marca,int tipoProducto,float precioActual,int garantia,int cantStock,bool estado);
        int getID_Producto();
        Proveedor getID_Proveedor();
        char* getDescripcion();
        char* getMarca();
        int getTipoProducto();
        float getPrecioActual();
        int getGarantia();
        int getCantStock();
        bool getEstado();

        void setID_Producto(int _idProducto);
        void setID_Proveedor(Proveedor ID_Proveedor);
        void setDescripcion(const std::string &_descripcion);
        void setMarca(const std::string &_marca);
        void setTipoProducto(int _tipoProducto);
        void setPrecioActual(float _precioActual);
        void setGarantia(int _garantia);
        void setCantidadStock(int _cantStock);
        void setEstado(bool _estado);

        void cargar();
        void Mostrar();

};


