#pragma once
#include <cstring>
#include "Persona.h"
#include "Fecha.h"
#include "Ventas.h"

class Venta{
    private:
        int ID_Venta;
        Persona ID_persona;
        Fecha FechaVenta;
        int MedioDePago;
        int TipoEnvio;
        float SubTotal;
        float MontoTotal;
        int TipoFactura;
        bool Estado;


    public:

        Venta();
        Venta(int id_venta,const Persona& id_persona,const Fecha& fechaventa,int mediopago,int tipoenvio,float subtotal,float montototal,int tipofactura,bool estado);

        int getID_Venta()const;
        Persona getID_Persona()const;
        Fecha getFechaVenta()const;
        int getMedioPago()const;
        int getTipoEnvio()const;
        float getSubTotal()const;
        float getMontoTotal()const;
        int getTipoFactura()const;
        bool getEstado()const;

        void setID_Venta(int _IDventa);
        void setID_Persona(const Persona& _IDPersona);
        void setFechaVenta(const Fecha& _fechaVenta);
        void setMedioDePago(int _medioPago);
        void setTipoEnvio(int _tipoEnvio);
        void setSubTotal(float _subTotal);
        void setMontoTotal(float _montoTotal);
        void setTipoFactura(int _tipoFactura);
        void setEstado(bool _estado);

        void cargarVenta();
        void mostrarVenta();

};

