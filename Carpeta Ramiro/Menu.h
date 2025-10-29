#pragma once
#include "Persona.h"
#include "Producto.h"
#include "Venta.h"
#include "Detalle_Venta.h"
#include "ProductoArchivo.h"
#include "VentaArchivo.h"
#include "EnvioArchivo.h"
#include "EmpleadoArchivo.h"
#include "ProveedorArchivo.h"
#include "ClienteArchivo.h"
#include "DetalleVentaArchivo.h"


class Menu {

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

    void subMenuABML_Detalle_Ventas() ;

    void subMenuABML_Envios() ;

    void subMenuABML_Listados() ;

} ;
