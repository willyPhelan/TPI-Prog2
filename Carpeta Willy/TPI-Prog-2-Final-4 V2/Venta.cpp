#include "Venta.h"
#include "VentaArchivo.h"
#include "ClienteArchivo.h"
#include <iostream>
#include <cstring>

using namespace std ;


Venta::Venta()

    :ID_Cliente(), ID_Venta(0), ID_persona(), fechaVenta(), medioDePago(0), tipoEnvio(0), subTotal(0.0), montoTotal(0.0), estado(true)

{}


Venta::Venta(int id_cliente, int id_venta, int id_persona, const Fecha &_fechaVenta, int _mediopago, int _tipoEnvio, float _subtotal, float _montoTotal, bool _estado)



    :ID_Venta(id_venta), ID_persona(), fechaVenta(_fechaVenta), medioDePago(_mediopago), tipoEnvio(_tipoEnvio), subTotal(_subtotal), montoTotal(_montoTotal), estado(_estado)
{


    ID_persona.setID(id_persona) ;
}





int Venta::getID_Venta() const
{

    return ID_Venta ;
}

int Venta::getID_Cliente()
{

    return ID_Cliente ;
}

Persona Venta::getID_Persona()
{

    return ID_persona ;
}

Fecha Venta::getFechaVenta()
{

    return fechaVenta ;
}


int Venta::getMedioPago()
{

    return medioDePago ;
}

int Venta::getTipoEnvio()
{

    return tipoEnvio ;
}

float Venta::getSubTotal()
{

    return subTotal ;
}

float Venta::getMontoTotal()
{

    return montoTotal ;
}

bool Venta::getEstado()
{

    return estado ;
}



void Venta::setID_Venta(int _IDventa)
{

    ID_Venta = _IDventa ;
}

void Venta::setID_Cliente(int _IDCliente)
{

    ID_Cliente = _IDCliente ;
}

void Venta::setID_Persona(Persona _IDPersona)
{

    ID_persona = _IDPersona ;
}

void Venta::setFechaVenta(Fecha _fechaVenta)
{

    fechaVenta = _fechaVenta ;
}



void Venta::setMedioDePago(int _medioPago)
{

    medioDePago = _medioPago ;
}

void Venta::setTipoEnvio(int _tipoEnvio)
{

    tipoEnvio = _tipoEnvio ;
}

void Venta::setSubTotal(float _subTotal)
{

    subTotal = _subTotal ;

}

void Venta::setMontoTotal(float _montoTotal)
{

    montoTotal = _montoTotal ;

}



void Venta::setEstado(bool _estado)
{

    estado = _estado ;
}




bool Venta::cargarVenta()
{

    int num ;

    int continuarDetalle = 1;

    float montoFinal = 0;

    float subtotalAcumulado = 0.0 ;
    int contadorProductos = 1 ;

    int idcliente;

    ClienteArchivo archivoCliente ;

    bool clienteEncontrado = false ;

    Fecha fechaActual ;

    ProductoArchivo archivoP ;

    cout << endl << "Carga de Fecha de Venta: " << endl ;

    cout << "--------------------------------------------------------------" << endl ;

    fechaActual.cargar() ;

    setFechaVenta(fechaActual) ;

    cout << "--------------------------------------------------------------" << endl ;

    do{

        cout << "Ingrese ID del Cliente: " ;

        cin >> idcliente ;

        int pos = archivoCliente.buscarPosicion(idcliente) ; // busco la posicion de un registro en el archivo

        Cliente reg = archivoCliente.leer(pos) ;

        if(reg.getEstado() == false) {

            cout << "Cliente dado de baja. Intente con otro" << endl ;

            return false ;
        }



        if (archivoCliente.buscarPosicion(idcliente) != -1)
        {

            setID_Cliente(idcliente) ;

            clienteEncontrado = true ;

        }
        else
        {

            cout << "ERROR: El ID de Cliente (" << idcliente << ") no existe." << endl ;

            cout << "Por favor, ingrese un ID de Cliente valido." << endl ;
        }

    }
    while (!clienteEncontrado) ;


    cout << endl << "Medio de pago (1- Efectivo, 2- Transferencia, 3- Debito, 4- Credito): " ;

    cin >> num ;

    while (num < 1 || num > 4)
    {

        cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

        cout << endl << "Medio de pago (1- Efectivo, 2- Transferencia, 3- Debito, 4- Credito): " ;

        cin >> num ;

    }

    setMedioDePago(num) ;

    cout << endl << "Tipo de envio: (1- Domicilio, 2- Retiro en Local): " ;

    cin >> num ;

    while (num != 1 && num != 2)
    {

        cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

        cout << "Tipo de envio: (1- Domicilio, 2- Retiro en Local): " ;

        cin >> num ;

    }

    setTipoEnvio(num) ;

    cout << endl << "Carga de productos de (DETALLE DE VENTA)" << endl ;

    cout << "--------------------------------------------------------------" << endl ;

    do
    {

        Detalle_Venta detalle ;

        DetalleVentaArchivo archivoDetalleVenta ;

        int idDetalle = archivoDetalleVenta.obtenerID();

        detalle.setID_Detalle(idDetalle);

        detalle.setID_Venta(getID_Venta());


        cout << "Producto #" << contadorProductos << " " ;

        detalle.cargar() ;

        if (detalle.getID_Producto() > 0 && detalle.getCantidad() > 0)
        {

            int id_prod = detalle.getID_Producto() ;

            int cantidad_vendida = detalle.getCantidad() ;

            int pos = archivoP.buscarPosicion(id_prod) ;

            if (pos != -1)
            {

                Producto regP = archivoP.leer(pos) ;


                int nuevo_stock = regP.getCantStock() - cantidad_vendida ;

                regP.setCantidadStock(nuevo_stock) ;


                if (archivoP.modificar(regP))
                {

                    cout << "Stock de Producto (ID " << id_prod << ") actualizado a " << regP.getCantStock() << " unidades." << endl ;

                }
                else
                {

                    cout << "ERROR: No se pudo guardar la modificacion del stock." << endl ;
                }

            }
            else
            {

                cout << " Advertencia: Producto no encontrado en archivo, stock no modificado." << endl ;
            }
        }

        cout << "Precio del Producto: $" << detalle.getPrecio_Unitario() << endl ;

        subtotalAcumulado += (detalle.getCantidad() * detalle.getPrecio_Unitario()) ;

        contadorProductos++ ;

        //      cout << endl << "Detalle de venta cargado. " << endl ;

        cout << "Desea agregar otro producto a la venta? (1- Si, 2- No): "  ;

        cin >> continuarDetalle ;

        while (continuarDetalle != 1 && continuarDetalle !=2)
        {

            cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

            cout << "Desea agregar otro producto a la venta? (1- Si, 2- No): "  ;

            cin >> continuarDetalle ;

        }

        cout << endl ;

        if (detalle.getCantidad () != 0)
        {

            archivoDetalleVenta.guardar(detalle);

            cout << endl << "Detalle de venta cargado. " << endl ;

        }

    }
    while (continuarDetalle == 1) ;

    montoFinal += subtotalAcumulado ;

    setSubTotal(subtotalAcumulado) ;

    setMontoTotal(montoFinal) ;

    cout << "--------------------------------------------------------------" << endl << endl ;

    cout << "Total: $" << getMontoTotal() << endl ;

    setEstado(true);

    return true ;

}


void Venta::mostrarVenta()
{

    cout << "ID_Venta: " << getID_Venta() << endl ;

    cout << "ID_Cliente: " << getID_Cliente() << endl ;

    cout << "Medio de pago: ";

    switch(getMedioPago())
    {
    case 1:

        cout<<"Efectivo"<< endl;

        break;

    case 2:

        cout<<"Transferencia"<< endl;

        break;

    case 3:

        cout<<"Debito"<< endl;

        break;

    case 4:

        cout<<"Credito"<< endl;

        break;

    }

    if(getTipoEnvio() == 1)
    {

        cout << "Forma de entrega: Envio a domicilio"  << endl ;

        cout << "Para ver mas informacion sobre el envio, busque el ID de esta venta en el listado de envios." << endl ;

    }
    else
    {

        cout <<  "Forma de entrega: Retiro en el local"  << endl ;

    }

    cout << "Fecha de la venta (dia/mes/anio): " << fechaVenta.getDia () << "/" << fechaVenta.getMes () << "/" << fechaVenta.getAnio() << endl;

    cout << "Subtotal (sin envio incluido): $" << getSubTotal() << endl ;

    cout << "Monto total (con envio incluido, si es aplicable): $" << getMontoTotal() << endl ;

    if(getEstado())
    {

        cout << "Estado: Activo" << endl ;
    }
    else
    {
        cout << "Estado: Dado de baja" << endl ;
    }
}

