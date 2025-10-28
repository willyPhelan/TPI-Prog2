#include "Envio.h"
#include "Fecha.h"  // Necesario para el atributo Fecha_Entrega
#include "Utils.h" // funciones aux
#include <iostream>


using namespace std ;


// CONSTRUCTORES //

// Constructor por defecto

Envio::Envio()
: ID_Envio(0), estado_Entrega(0), valor_Envio(0.0f), estado(true) // Estado por defecto: Activo
{}

// Constructor con parámetros

Envio::Envio(int idEnvio, Fecha fecha, int estado, float valor, bool activo)
 : ID_Envio(idEnvio), fecha_Entrega(fecha), estado_Entrega(estado), valor_Envio(valor), estado(activo)
{}



// GETTERS

int Envio::getID_Envio() const {

    return ID_Envio ;
}

int Envio::getID_Venta() const {

    return ID_Venta ;
}

Fecha Envio::getFecha_Entrega() const {

    return fecha_Entrega ;
}

int Envio::getEstado_Entrega() const {

    return estado_Entrega ;
}

float Envio::getValor_Envio() const {

    return valor_Envio ;
}

bool Envio::getEstado() const {

    return estado ;
}


// SETTERS

void Envio::setID_Envio(int idEnvio) {

    ID_Envio = idEnvio ;
}

void Envio::setID_Venta(int id_venta) {

    ID_Venta = id_venta ;
}

void Envio::setFecha_Entrega(const Fecha& fecha) {

    fecha_Entrega = fecha ;
}

void Envio::setEstado_Entrega(int estado) {

    estado_Entrega = estado ;
}

void Envio::setValor_Envio(float valor) {

    valor_Envio = valor ;
}

void Envio::setEstado(bool activo) {

    estado = activo ;
}


// MÉTODOS


void Envio::cargar() {

    int estadoEntrega ;

    float valorEnvio ;

    // El ID_Venta NO se pide al usuario (asumimos que lo asigna el Archivo)

    // Fecha de Entrega

    Fecha fecha ; // Creamos un objeto temporal para la carga

    // Asumimos que la clase Fecha tiene un método para cargarse o set/get básicos.
    // Aquí implementamos la carga manual de la Fecha:

    int dia, mes, anio ;

    cout << "Dia de entrega: " ;

    cin >> dia ;

    cout << "Mes de entrega: " ;

    cin >> mes ;

    cout << "Anio de entrega: " ;

    cin >> anio ;

    // Asigno lo que se ingreso en el cin al obj Fecha

    fecha.setDia(dia) ;
    fecha.setMes(mes) ;
    fecha.setAnio(anio) ;
    setFecha_Entrega(fecha) ;

    // Estado de Entrega (1: Pendiente, 2: En curso, 3: Entregado)

    cout << "Estado de Entrega (1- Pendiente, 2- En curso, 3- Entregado): " ;

    cin >> estadoEntrega ;

    setEstado_Entrega(estadoEntrega) ;

    // Valor del Envío

    cout << "Valor (en pesos) del Envio: $" ;

    cin >> valorEnvio ;

    setValor_Envio(valorEnvio) ;

    cout << endl ;

    // Estado se mantiene en TRUE (Activo) por defecto
}

void Envio::mostrar() const {

    cout << endl << "DATOS DEL ENVIO" << endl ;

    cout << "ID Envio: " << getID_Envio() << endl ;

    cout << "Fecha de Entrega: " ;

    getFecha_Entrega().mostrar() ; // Asume que la clase Fecha tiene un metodo mostrar()

    cout << endl ;

    cout << "Valor del Envio: $" << getValor_Envio() << endl ;

    // Traducción del estado numérico a texto legible

    cout << "Estado de Entrega: " ;

    switch (getEstado_Entrega()) {

        case 1: cout << "Pendiente" << endl ; break ;

        case 2: cout << "En curso" << endl ; break ;

        case 3: cout << "Entregado" << endl ; break ;

        default: cout << "Desconocido" << endl ; break ;

     }

    cout << "Registro Activo: " << (getEstado() ? "Si" : "No") << endl ;

    cout << "-------------------------------" << endl ;

    cout << "Envio cargado exitosamente" << endl ;
}
