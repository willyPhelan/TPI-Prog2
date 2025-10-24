#include <iostream>
#include "Producto.h"
#include "Ventas.h"

using namespace std;

int main()
{

    Producto producto;
    Ventas venta;

    //producto.cargar();

    //producto.Mostrar();

    venta.cargarVenta();

    venta.mostrarVenta();


    system("pause");

    return 0;
}
