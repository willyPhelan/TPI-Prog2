#pragma once
#include "Envio.h"
#include <cstdio>
#include "Venta.h"
#include "VentaArchivo.h"

class EnvioArchivo
{

public:

    bool guardar(const Envio &reg) ;

    Envio leer(int pos) ;

    bool bajaLogica(int id_envio) ;

    bool altaLogica(int id_envio) ;

    bool modificar(const Envio &reg) ;

    int obtenerID() ;

    int getCantidadRegistros() ;

    int buscarPosicion(int id_envio) ;

    int buscarPosicionPorID_Venta(int id_venta) ;

    void modificarCampos() ;

    bool hacerBackup ();

    bool restaurarBackup ();

private:

    const char* archivo_Envio = "Envios.dat" ;

    const char *archivo_Envio_Backup = "Envios_Backup.bkp";
};
