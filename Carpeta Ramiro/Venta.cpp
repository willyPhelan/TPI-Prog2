#include "Venta.h"
#include <iostream>
#include <cstring>

using namespace std ;

// consturcotres

// constructor por defecto

Venta::Venta()

: ID_Venta(0), ID_persona(), fechaVenta(), medioDePago(0), tipoEnvio(0), subTotal(0.0), montoTotal(0.0), tipoFactura(0), estado(true)

{}

// constructor con parametros

Venta::Venta(int id_venta, int id_persona, const Fecha &_fechaVenta, int _mediopago, int _tipoEnvio, float _subtotal, float _montoTotal, int _tipoFactura, bool _estado)

// Inicializa miembros de objeto con sus constructores por defecto.

:ID_Venta(id_venta), ID_persona(), fechaVenta(_fechaVenta), medioDePago(_mediopago), tipoEnvio(_tipoEnvio), subTotal(_subtotal), montoTotal(_montoTotal), tipoFactura(_tipoFactura), estado(_estado)
{
    // L�gica para asignar el ID a la Persona (ya que el miembro es un objeto)

    ID_persona.setID(id_persona) ; }



// getters

int Venta::getID_Venta() const {

    return ID_Venta ;
}

Persona Venta::getID_Persona(){ // composicion Persona

    return ID_persona ;
}

Fecha Venta::getFechaVenta(){

    return fechaVenta ;
}

/* Envio Venta::getEnvio() const {

    return envioAsociado ;
} */

int Venta::getMedioPago(){

    return medioDePago ;
}

int Venta::getTipoEnvio(){

    return tipoEnvio ;
}

float Venta::getSubTotal(){

    return subTotal ;
}

float Venta::getMontoTotal(){

    return montoTotal ;
}

int Venta::getTipoFactura(){

    return tipoFactura ;
}

bool Venta::getEstado(){

    return estado ;
}

// setters

void Venta::setID_Venta(int _IDventa){

    ID_Venta = _IDventa ;
}

void Venta::setID_Persona(Persona _IDPersona){

    ID_persona = _IDPersona ;
}

void Venta::setFechaVenta(Fecha _fechaVenta){

    fechaVenta = _fechaVenta ;
}

/*void Venta::setEnvio(const Envio &_envio) {

    envioAsociado = _envio ;
} */

void Venta::setMedioDePago(int _medioPago){

    medioDePago = _medioPago ;
}

void Venta::setTipoEnvio(int _tipoEnvio){

    tipoEnvio = _tipoEnvio ;
}

void Venta::setSubTotal(float _subTotal){

    subTotal = _subTotal ;

}

void Venta::setMontoTotal(float _montoTotal){

    montoTotal = _montoTotal ;

}

void Venta::setTipoFactura(int _tipoFactura){

    tipoFactura = _tipoFactura ;

}

void Venta::setEstado(bool _estado){

    estado = _estado ;
}

/* void Venta::cargarVenta(){

    int num ;

    cout << "Carga de una venta" << endl ;

    cout << "-------------------------------" << endl ;

    cout << "ID VENTA TIENE QUE SER AUTOINCRMENTAL DESDE ARCHIVO VENTA" << endl ;

    cout << "Medio de pago: " ;

    cin >> num ;

    setMedioDePago(num) ;

    cout << "Tipo de envio: (1- Domicilio, 0- Retiro en Local): " ;

    cin >> num ;

    setTipoEnvio(num) ;

    cout << "Subtotal: " ;

    cin >> num ;

    setSubTotal(num) ;

    cout << "Monto total: " ;

    cin >> num ;

    setMontoTotal(num) ;

    cout << "Tipo de factura (1- Factura A, 2- Factura B, 3- Factura C): " ;

    cin >> num ;

    setTipoFactura(num) ;

} */


void Venta::cargarVenta(){

    int num ;

    int continuarDetalle = 1 ;

    float MontoIVA = 1.21;

    float montoFinal;

    float subtotalAcumulado = 0.0 ; // Para calcular el subtotal

    int contadorProductos = 1 ;

    // Carga de ID_Persona y Fecha

    // L�gica de carga de ID_Persona aca
    // L�gica de carga de Fecha , usando Fecha::cargar()

    Fecha fechaActual ;

    cout << endl << "Carga de Fecha de Venta: " << endl ;

    cout << "--------------------------------------------------------------" << endl ;

    fechaActual.cargar() ;

    setFechaVenta(fechaActual) ;

    //2. Carga de la Cabecera de la Venta

    cout << "--------------------------------------------------------------" << endl ;

    cout << endl << "Medio de pago (1-Efectivo, 2-Tarjeta): " ;

    cin >> num ;

    setMedioDePago(num) ;

    cout << "Tipo de envio: (1- Domicilio, 0- Retiro en Local): " ;

    cin >> num ;

    setTipoEnvio(num) ;

    // 3. Carga Condicional del ENVIO




    // 4. Carga del DETALLE_VENTA (Bucle)

    cout << endl << "Carga de productos de (DETALLE DE VENTA)" << endl ;

    cout << "--------------------------------------------------------------" << endl ;

    do {

        Detalle_Venta detalle ;// Instancia de Detalle_Venta
        DetalleVentaArchivo archivoDetalleVenta;

        detalle.setID_Detalle(getID_Venta());
        detalle.setID_Venta(getID_Venta());


        cout << "Producto #" << contadorProductos << " " ;

        detalle.cargar() ;// Carga de ID_Producto, Cantidad, Precio_Unitario

        cout <<"Precio del Producto: "<<detalle.getPrecio_Unitario();

        // C�LCULO DE SUBTOTAL:

        subtotalAcumulado += (detalle.getCantidad() * detalle.getPrecio_Unitario()) ;

        montoFinal += subtotalAcumulado * MontoIVA;

        contadorProductos++ ;

        // *NOTA: Aqu� se deber�a guardar 'linea' en su archivo correspondiente (DetalleVentas.dat)*

        cout << endl << "Detalle de venta cargado. " << endl ;

        cout << "Desea agregar otro producto a la venta? (1 = Si, 0 = No): "  ;

        cin >> continuarDetalle ;

        cout << endl ;

        archivoDetalleVenta.guardar(detalle);

    } while (continuarDetalle == 1) ;


    // 5. Actualizaci�n de Totales y Factura

    setSubTotal(subtotalAcumulado) ;

    // El monto total debe incluir impuestos y costo de env�o (si aplica)

    setMontoTotal(montoFinal) ;

    cout << "Tipo de factura: (1- Factura A, 2- Factura B, 3- Factura C): " ;

    cin >> num ;

    cout << endl ;

    cout << "--------------------------------------------------------------" << endl << endl ;

    cout << "Subtotal: " << getSubTotal() << endl ;

    cout << "TOTAL: " << getMontoTotal() << endl ;

    setTipoFactura(num) ;

    // El estado de la Venta es activo por defecto al cargar

    setEstado(true);

}


void Venta::mostrarVenta(){

    cout << "ID_Venta: " <<getID_Venta() << endl ;

    cout << "Medio de pago: " <<getMedioPago() << endl ;

    if(getTipoEnvio() == 1) {

         cout << "Forma de entrega: Envio a domicilio"  << endl ;

    } else {

        cout <<  "Forma de entrega: Envio a domicilio"  << endl ;

    }


    cout << "Subtotal: " << getSubTotal() << endl ;

    cout << "Monto total: " << getMontoTotal() << endl ;

    cout << "Tipo de factura: " << getTipoFactura() << endl ;

    if(getEstado()) {

    cout << "Estado: " << "Activa" << endl ; } else { cout << "Dada de baja" << endl ; }
}
