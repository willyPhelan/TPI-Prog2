#pragma once
#include "Persona.h"
#include "Producto.h"
#include "Venta.h"
#include "ProductoArchivo.h"
#include "VentaArchivo.h"
#include "EnvioArchivo.h"
#include "ClienteArchivo.h"
#include "Envio.h"

class Menu
{

public:

    void mostrar() ; // muestro opciones

private:

    void subMenuPersonas() ;   // Gestiono el submenu de Personas.

    void subMenuABML() ;

    void subMenuABML_Clientes() ;

    void subMenuABML_Empleados() ;

    void subMenuABML_Proveedores() ;

    void subMenuABML_Productos() ;

    void subMenuABML_Ventas() ;

    void subMenuABML_Envios() ;

    void subMenuABML_Listados() ;

    void subMenuABML_Listados_Activos() ;

    void subMenuReportes() ;

    void menuConfiguraciones();

} ;
