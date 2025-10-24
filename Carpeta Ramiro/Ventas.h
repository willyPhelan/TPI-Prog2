#pragma once
#include <cstring>

class Ventas
{
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

        int getID_Venta();
        Persona getID_Persona();
        Fecha getFechaVenta();
        int getMedioPago();
        int getTipoEnvio();
        float getSubTotal();
        float getMontoTotal();
        int getTipoFactura();
        bool getEstado();

        void setID_Venta(int _IDventa);
        void setID_Persona(Persona _IDPersona);
        void setFechaVenta(Fecha _fechaVenta);
        void setMedioDePago(int _medioPago);
        void setTipoEnvio(int _tipoEnvio);
        void setSubTotal(float _subTotal);
        void setMontoTotal(float _montoTotal);
        void setTipoFactura(int _tipoFactura);
        void setEstado(bool _estado);

        void cargarVenta();
        void mostrarVenta();

};

