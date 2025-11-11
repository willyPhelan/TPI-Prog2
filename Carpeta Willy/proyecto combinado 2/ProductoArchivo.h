#pragma once
#include "Producto.h"
#include <cstdio> // Para el manejo de archivos FILE*

class ProductoArchivo
{

public:

    // ALTA (Guarda un nuevo registro al final del archivo)

    bool guardar(const Producto &reg) ;

    // LECTURA/LISTADO (Lee un registro por su posición/índice)

    // Devuelve el objeto Producto en esa posición.

    Producto leer(int pos) ;

    // BAJA (Realiza una Baja Lógica, modificando el estado a 'false')
    // Devuelve true si la operación fue exitosa.

    bool bajaLogica(int id_producto) ;

    bool altaLogica(int id_producto) ;

    // MODIFICACIÓN (Sobreescribe el registro con el mismo ID)
    // Recibe el registro modificado y lo guarda en su posición original.

    bool modificar(const Producto &reg) ;

    int obtenerID() ; // cuenta los registos y suma 1 para el nuevo ID

    //fns Auxiliares

    int getCantidadRegistros() ;

    int buscarPosicion(int id_producto) ; // Devuelve la posición (índice) del registro o -1 si no lo encuentra

    float buscarPrecio(int idBuscado) ;

    bool validarDescripcion(const std::string &descripcion_a_validar) ;

    void modificarCampos() ;


private:

    const char *archivo_Producto = "Productos.dat" ;

};
