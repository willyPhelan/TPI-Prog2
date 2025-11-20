#pragma once
#include "Venta.h"
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

    // METODOS

    void modificarCampos() ;


    // REPORTES

//    float calcularRecaudacionAnual(int anio) ;

//    float calcularRecaudacionMensual(int mes, int anio) ;

    void calcularRecaudacionPorCliente () ;

    void reporteCantidadPorMedioPago();

    float calcularRecaudacion (int anio);

    // BACKUPS

    bool hacerBackup ();

    bool restaurarBackup ();

};
