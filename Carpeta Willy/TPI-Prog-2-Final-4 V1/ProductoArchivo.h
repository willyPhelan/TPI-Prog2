#pragma once
#include "Producto.h"
#include <cstdio>

class ProductoArchivo
{

public:


    bool guardar(const Producto &reg) ;

    Producto leer(int pos) ;

    bool bajaLogica(int id_producto) ;

    bool altaLogica(int id_producto) ;

    bool modificar(const Producto &reg) ;

    int obtenerID() ;

    int getCantidadRegistros() ;

    int buscarPosicion(int id_producto) ;

    float buscarPrecio(int idBuscado) ;

    bool validarDescripcion(const std::string &descripcion_a_validar) ;

    void modificarCampos();

    bool MarcaPorID(int idBuscado, char* marcaDestino, int tam);

    // Backups

    bool hacerBackup ();

    bool restaurarBackup ();


private:

    const char *archivo_Producto = "Productos.dat" ;

    const char *archivo_Producto_Backup = "Productos_Backup.bkp";

};
