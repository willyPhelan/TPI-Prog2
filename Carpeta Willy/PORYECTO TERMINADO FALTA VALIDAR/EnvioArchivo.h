#pragma once
#include "Envio.h"
#include <cstdio> // Para el manejo de archivos FILE*

class EnvioArchivo
{

public:

    // ALTA

    bool guardar(const Envio &reg) ;

    // LECTURA

    Envio leer(int pos) ;

    // BAJA

    bool bajaLogica(int id_envio) ; // Uso ID_Venta para dar de baja el envío asociado

    bool altaLogica(int id_envio) ;

    // MODIFICACIÓN

    bool modificar(const Envio &reg) ;

    // GENERACIÓN DE ID (ID de Venta autoincremental, ya que el Envío depende de la Venta)

    int obtenerID() ;

    // Fns Auxiliares

    int getCantidadRegistros() ;

    int buscarPosicion(int id_envio) ; // Busca la posición del Envío

    int buscarPosicionPorID_Venta(int id_venta) ;

    void modificarCampos() ;

    bool hacerBackup() ;

    bool restaurarBackup() ;

private:

    const char* archivo_Envio = "Envios.dat"  ;

    const char* archivo_Enviobkp = "Envios.bkp" ;
};
