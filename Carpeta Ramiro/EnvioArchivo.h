#pragma once
#include "Envio.h"
#include <cstdio> // Para el manejo de archivos FILE*

class EnvioArchivo {

public:

    // ALTA

    bool guardar(const Envio &reg) ;

    // LECTURA

    Envio leer(int pos) ;

    // BAJA

    bool bajaLogica(int id_venta) ; // Uso ID_Venta para dar de baja el env�o asociado

    // MODIFICACI�N

    bool modificar(const Envio &reg) ;

    // GENERACI�N DE ID (ID de Venta autoincremental, ya que el Env�o depende de la Venta)

    int obtenerID() ;

    // Fns Auxiliares

    int getCantidadRegistros() ;

    int buscarPosicion(int id_envio) ; // Busca la posici�n del Env�o por ID_Venta

    int buscarPosicionPorID_Venta(int id_venta);

private:

    const char* archivo_Envio = "Envios.dat" ;
};
