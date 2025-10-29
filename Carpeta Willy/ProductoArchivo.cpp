#include "ProductoArchivo.h"
#include <iostream>
#include <cstdio>

using namespace std ;

// 1. Obtener la cantidad total de registros

int ProductoArchivo::getCantidadRegistros() {

    FILE* p ;

    // Abrir en modo binario de lectura ("rb")

    p = fopen(archivo_Producto, "rb") ;

    if (p == nullptr) {

        return 0 ; // Si no existe o no se puede abrir
    }

    // Mover el puntero al final del archivo

    fseek(p, 0, SEEK_END) ;

    // Obtener la posici�n actual (tama�o total en bytes)

    int tamanioEnBytes = ftell(p) ;

    fclose(p) ;

    // La cantidad es el tama�o total dividido por el tama�o de un registro

    return tamanioEnBytes / sizeof(Producto) ;
}

// 2. Buscar la posici�n (�ndice) de un registro por ID

int ProductoArchivo::buscarPosicion(int id_producto) {

    Producto reg ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++) {

        reg = leer(i) ; // Uso el m�todo leer por posici�n

        // Comparo el ID

        if (reg.getID_Producto() == id_producto) {

            return i ; // Retorna la posici�n (�ndice)
        }
    }

    return -1 ; // No encontrado
}

// ====================================================================
// FUNCIONES ABML
// ====================================================================

// ALTA (Guardar)

bool ProductoArchivo::guardar(const Producto &reg) {

    FILE* p ;

    // Abrir en modo binario de adici�n ("ab")

    p = fopen(archivo_Producto, "ab") ;

    if (p == nullptr) {

            cout << "NO SE PUDO CREAR EL ARCHIVO" ;

            return false ; }

    // Escribir el registro al final del archivo
    // fwrite(&variable, tama�o_del_registro, cantidad_de_registros, puntero_archivo)

    int escrito = fwrite(&reg, sizeof(Producto), 1, p) ;

    fclose(p) ;

    // Devuelve true si se escribi� 1 registro.

    return escrito ;
}

// LECTURA

Producto ProductoArchivo::leer(int pos) {

    Producto reg ; // Se inicializa con el constructor por defecto

    FILE* p ;

    // Abrir en modo binario de lectura ("rb")

    p = fopen(archivo_Producto, "rb") ;

    if (p == nullptr) {

        return reg ; // Retorna un objeto vac�o
    }

    // Mover el puntero a la posici�n deseada
    // fseek(puntero_archivo, desplazamiento, origen)

    fseek(p, pos * sizeof(Producto), SEEK_SET) ; // SEEK_SET = desde el inicio

    // Leer el registro en la variable 'reg'
    // fread(&variable, tama�o_del_registro, cantidad_de_registros, puntero_archivo)

    fread(&reg, sizeof(Producto), 1, p) ;

    fclose(p) ;

    return reg ;
}

// MODIFICACI�N (Sobreescribir con datos nuevos)

bool ProductoArchivo::modificar(const Producto &reg) {

    // 1. Buscar la posici�n del registro

    int pos = buscarPosicion(reg.getID_Producto()) ;

    if (pos == -1) {

        return false ; // El registro a modificar no existe
    }

    FILE* p ;

    // Abrir en modo binario de lectura y escritura ("rb+")

    p = fopen(archivo_Producto, "rb+") ;

    if (p == nullptr) { return false ; }

    // 2. Muevo el puntero a la posici�n del registro a modificar

    fseek(p, pos * sizeof(Producto), SEEK_SET) ;

    // Sobreescribo el registro con el objeto 'reg' (que ya trae los datos modificados)

    int escrito = fwrite(&reg, sizeof(Producto), 1, p) ;

    fclose(p) ;

    return escrito ;
}

// BAJA L�GICA

bool ProductoArchivo::bajaLogica(int id_producto) {

    // 1. Busco la posici�n del registro

    int pos = buscarPosicion(id_producto) ;

    if (pos == -1) {

        return false ; // Producto no encontrado
    }

    // Leo el registro en la posici�n encontrada

    Producto reg = leer(pos) ;

    // Modifico el estado a falso (baja l�gica)

    reg.setEstado(false);

    // 4. Sobreescribo el registro modificado en la misma posici�n (reutilizando la l�gica de Modificar)
    // "rb+" para reescribir

    FILE* p ;

    p = fopen(archivo_Producto, "rb+") ;

    if (p == nullptr) { return false ; }

    // Mover el puntero a la posici�n

    fseek(p, pos * sizeof(Producto), SEEK_SET) ;

    // Sobreescribir (write) el registro modificado

    int escrito = fwrite(&reg, sizeof(Producto), 1, p) ;

    fclose(p) ;

    return escrito ;
}

// ALTA

bool ProductoArchivo::altaLogica(int id_producto) {

    // 1. Busco la posici�n del registro

    int pos = buscarPosicion(id_producto) ;

    if (pos == -1) {

        return false ; // Producto no encontrado
    }

    // Leo el registro en la posici�n encontrada

    Producto reg = leer(pos) ;

    // Modifico el estado a falso (baja l�gica)

    reg.setEstado(true) ;

    // 4. Sobreescribo el registro modificado en la misma posici�n (reutilizando la l�gica de Modificar)
    // "rb+" para reescribir

    FILE* p ;

    p = fopen(archivo_Producto, "rb+") ;

    if (p == nullptr) { return false ; }

    // Mover el puntero a la posici�n

    fseek(p, pos * sizeof(Producto), SEEK_SET) ;

    // Sobreescribir (write) el registro modificado

    int escrito = fwrite(&reg, sizeof(Producto), 1, p) ;

    fclose(p) ;

    return escrito ;
}

int ProductoArchivo::obtenerID() {

    FILE* p = fopen(archivo_Producto, "rb") ;

    // Si el archivo no existe o no se puede abrir, es el primer registro.

    if (p == nullptr) {

        return 1 ;
    }

    // 1. Muevo el puntero al final del archivo

    fseek(p, 0, SEEK_END) ;

    // 2. obtengo la posici�n (cantidad de bytes)

    int bytes = ftell(p) ;

    // 3. Cierro el archivo inmediatamente

    fclose(p) ;

    // Si el archivo est� vac�o (0 bytes), el primer ID es 1.

    if (bytes == 0) {

        return 1 ;
    }

    // 4. Calculo el n�mero de registros: (Total de bytes / Tama�o de un registro)

    // El ID del �ltimo registro es igual al n�mero total de registros (asumiendo que empiezan en 1).

    int numRegistros = bytes / sizeof(Producto) ;

    // 5. El nuevo ID es el n�mero de registros existentes + 1.

    return numRegistros + 1 ;
}
