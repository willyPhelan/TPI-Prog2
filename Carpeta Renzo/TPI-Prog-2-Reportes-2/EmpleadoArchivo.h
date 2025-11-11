#pragma once
#include "Empleado.h"
#include <cstdio>

class EmpleadoArchivo
{

private: /// Atributos

    const char *archivo_Empleado = "Empleados.dat" ;

public: /// Metodos

/// FUNCIONES ABML

    bool guardar (const Empleado &reg) ; // <-- Metodo para guardar un nuevo registro

    bool bajaLogica (int id_persona) ; // <-- Metodo para hacer la baja logica

    bool altaLogica(int id_persona) ;

    Empleado leer (int pos) ; // <-- Metodo para leer (listado)

    bool modificar (const Empleado &reg) ;

/// FUNCIONES AUXILIARES

    int getCantidadRegistros () ;

    int buscarPosicion (int id_persona) ;

    bool validarCUIT (std::string cuit);

    void modificarCampo ();

/// REPORTES

    void calcularEmpleadosConMasHoras ();

} ;


