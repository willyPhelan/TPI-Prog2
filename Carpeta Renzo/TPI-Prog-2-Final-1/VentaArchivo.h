#pragma once
#include "Venta.h"
#include "EnvioArchivo.h"
#include <cstdio>


class VentaArchivo
{

private:

    const char *archivo_Venta = "Ventas.dat" ;

    const char *archivo_Venta_Backup = "Ventas_Backup.bkp";

public:

    bool guardar(const Venta &reg) ;

    Venta leer(int pos) ;

    bool bajaLogica(int id_venta) ;

    bool altaLogica(int id_venta) ;

    bool modificar(const Venta &reg) ;

    int obtenerID() ;

    int getCantidadRegistros() ;

    int buscarPosicion(int id_venta) ;

    void modificarCampos() ;

    void actualizarEnvioCondicional(Venta& venta_modificar, int nuevo_tipo_envio) ;

    void calcularRecaudacionPorCliente () ;

    void reporteCantidadPorMedioPago();

    float calcularRecaudacion (int anio);

    bool hacerBackup ();

    bool restaurarBackup ();

};
