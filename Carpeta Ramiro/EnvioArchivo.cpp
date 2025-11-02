#include "EnvioArchivo.h"
#include <iostream>

using namespace std ;

// FUNCIONES

// Obtengo la cantidad total de registros

int EnvioArchivo::getCantidadRegistros() {

    FILE* p = fopen(archivo_Envio, "rb") ;

    if (p == nullptr) {

        return 0 ;
    }

    fseek(p, 0, SEEK_END) ;

    long bytes = ftell(p) ;

    fclose(p) ;

    if (bytes == 0) { return 0 ; }

    return bytes / sizeof(Envio);
}

// Genero el ID para el próximo registro
// ID_Envio autoincremental, independiente de Venta.

int EnvioArchivo::obtenerID() {

    return getCantidadRegistros() + 1 ;
}

// 3. Buscar la posición (índice) de un registro por ID_Envio

int EnvioArchivo::buscarPosicion(int id_envio) {

    Envio reg ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++) {

        reg = leer(i) ;

        // busco por ID_Envio, la clave principal del archivo

        if (reg.getID_Envio() == id_envio) {

            return i ; // Retorna la posicion
        }
    }

    return -1 ; // No encontrado
}

// Busco la posición de un registro por ID_Venta

int EnvioArchivo::buscarPosicionPorID_Venta(int id_venta) {

    Envio reg ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++) {

        reg = leer(i) ;

        // para encontrar el envío asociado a una venta.

        if (reg.getID_Venta() == id_venta) {

            return i ;
        }
    }

    return -1 ;
}


// FUNCIONES ABML

// ALTA

bool EnvioArchivo::guardar(const Envio &reg) {

    FILE* p = fopen(archivo_Envio, "ab") ;

    if (p == nullptr) { return false ; }

    int escrito = fwrite(&reg, sizeof(Envio), 1, p) ;

    fclose(p) ;

    return escrito  ;
}

// LECTURA

Envio EnvioArchivo::leer(int pos) {

    Envio reg ;

    FILE* p = fopen(archivo_Envio, "rb") ;

    if (p == nullptr || pos < 0) { return reg ; }

    fseek(p, pos * sizeof(Envio), SEEK_SET) ;

    fread(&reg, sizeof(Envio), 1, p) ;

    fclose(p) ;

    return reg ;
}

// MODIFICACIÓN
// Usa el ID_Envio de la venta pasada como parámetro para buscar la posición.

bool EnvioArchivo::modificar(const Envio &reg) {

    // 1. Buscar la posición del registro usando ID_Envio

    int pos = buscarPosicion(reg.getID_Envio()) ;

    if (pos == -1) { return false ; }

    FILE* p = fopen(archivo_Envio, "rb+") ;

    if (p == nullptr) { return false ; }

    // 2. Mover el puntero y sobrescribir

    fseek(p, pos * sizeof(Envio), SEEK_SET) ;

    int escrito = fwrite(&reg, sizeof(Envio), 1, p) ;

    fclose(p) ;

    return escrito  ;
}

// BAJA LÓGICA
// Recibe el ID_Envio para realizar la baja.

bool EnvioArchivo::bajaLogica(int id_envio) {

    // 1. Busco la posicion por ID_Envio

    int pos = buscarPosicion(id_envio) ;

    if (pos == -1) { return false ; }

    // Leer y modificar estado

    Envio reg = leer(pos) ;

    if (!reg.getEstado()) { return false ; } // Ya estaba inactivo

    reg.setEstado(false) ; // Cambio a inactivo

    // 3. Sobreescribo el registro modificado usa ID_Envio para buscar

    return modificar(reg) ;
}

bool EnvioArchivo::altaLogica(int id_envio) {

    // 1. Busco la posicion por ID_Envio

    int pos = buscarPosicion(id_envio) ;

    if (pos == -1) { return false ; }

    // Leer y modificar estado

    Envio reg = leer(pos) ;

    if (reg.getEstado()) { return true ; } // Ya estaba aactivo

    reg.setEstado(true) ; // Cambio a activo

    // 3. Sobreescribo el registro modificado usa ID_Envio para buscar

    return modificar(reg) ;
}


