#pragma once
#include "Empleado.h"
#include <cstdio>

class EmpleadoArchivo
{

private:

    const char *archivo_Empleado = "Empleados.dat" ;

    const char *archivo_Empleado_Backup = "Empleados_Backup.bkp";

public:



    bool guardar (const Empleado &reg) ;

    bool bajaLogica (int id_persona) ;

    bool altaLogica(int id_persona) ;

    Empleado leer (int pos) ;

    bool modificar (const Empleado &reg) ;

    void modificarCampo ();

    int getCantidadRegistros () ;

    int buscarPosicion (int id_persona) ;

    bool validarCUIT (std::string cuit);

    void calcularEmpleadosConMasHoras ();

    bool hacerBackup ();

    bool restaurarBackup ();

} ;


