#pragma once
#include "Producto.h"
#include <cstdio> // Para el manejo de archivos FILE*

class ProductoArchivo {

public:

    // ALTA (Guarda un nuevo registro al final del archivo)

    bool guardar(const Producto &reg) ;

    // LECTURA/LISTADO (Lee un registro por su posici�n/�ndice)

    // Devuelve el objeto Producto en esa posici�n.

    Producto leer(int pos) ;

    // BAJA (Realiza una Baja L�gica, modificando el estado a 'false')
    // Devuelve true si la operaci�n fue exitosa.

    bool bajaLogica(int id_producto) ;

    // MODIFICACI�N (Sobreescribe el registro con el mismo ID)
    // Recibe el registro modificado y lo guarda en su posici�n original.

    bool modificar(const Producto &reg) ;

    int obtenerID() ; // cuenta los registos y suma 1 para el nuevo ID

    //fns Auxiliares

    int getCantidadRegistros() ;

    int buscarPosicion(int id_producto) ; // Devuelve la posici�n (�ndice) del registro o -1 si no lo encuentra

private:

    const char *archivo_Producto = "Productos.dat" ;

};
