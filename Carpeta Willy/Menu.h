#pragma once
#include "Persona.h"

//incluir Producto y Venta cuando existan
// #include "Producto.h"
// #include "Venta.h"

class Menu {

public:

    void mostrar() ; // muestro opciones

private:

    void subMenuPersonas() ;   // Gestiono el submenu de Personas.

    void subMenuABML() ;

    void subMenuABML_Clientes() ;

    void subMenuABML_Empleados() ;

    void subMenuABML_Proveedores() ;

    // Declaraciones de submenús futuros:

    // void subMenuProductos();
    // void subMenuVentas();
};
