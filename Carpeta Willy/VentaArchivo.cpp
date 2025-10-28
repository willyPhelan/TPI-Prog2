#include "VentaArchivo.h"
#include <iostream>
#include <cstdio>

using namespace std ;


bool VentaArchivo::guardar(const Venta &reg){

    FILE* pventa;

    pventa = fopen(archivo_Venta,"ab") ;

    if(pventa == nullptr){

        cout << "NO SE PUDO CREAR EL ARCHIVO" ;

        return false ;
    }

    int escrito = fwrite(&reg, sizeof(Venta), 1, pventa) ;

    fclose(pventa) ;

    return escrito ;

}

Venta VentaArchivo::leer(int pos){

    Venta reg ;

    FILE* pventa ;

    pventa = fopen(archivo_Venta, "rb") ;

    if(pventa == nullptr){

        cout << "NO SE PUDO CREAR EL ARCHIVO" ;

        return reg ;
    }

    fseek(pventa, pos * sizeof(Venta), SEEK_SET) ;

    fread(&reg, sizeof(Venta), 1, pventa) ;

    fclose(pventa) ;

    return reg ;

}

bool VentaArchivo::bajaLogica(int id_venta){

    int pos = buscarPosicion(id_venta) ;

    if(pos == -1){

        return false ;
    }

    Venta reg = leer(pos) ;

    reg.setEstado(false) ;

    FILE* pventa ;

    pventa = fopen(archivo_Venta, "rb+") ;

    if (pventa == nullptr){ return false ; }

    fseek(pventa,pos*sizeof(Venta),SEEK_SET) ;

    int escrito = fwrite(&reg, sizeof(Venta), 1, pventa) ;

    fclose(pventa) ;

    return escrito ;
}


bool VentaArchivo::modificar(const Venta &reg){

    int pos ;

    pos = buscarPosicion(reg.getID_Venta()) ;

    if(pos == -1){

        return false ;
    }

    FILE* pventa ;

    pventa = fopen(archivo_Venta, "rb+") ;

    if(pventa == nullptr){ return false ; }

    fseek(pventa, pos * sizeof(Venta), SEEK_SET) ;

    int escrito = fwrite(&reg, sizeof(Venta), 1, pventa) ;

    fclose(pventa) ;

    return escrito ;

}

int VentaArchivo::obtenerID(){

    int bytes ;

    int numRegistros ;

    FILE* pventa ;

    pventa = fopen(archivo_Venta, "rb") ;

    if(pventa == nullptr){ return 1 ; }

    fseek(pventa, 0, SEEK_END) ;

    bytes = ftell(pventa) ;

    fclose(pventa) ;

    if(bytes == 0){ return 1 ; }

    numRegistros = bytes / sizeof(Venta) ;

    return numRegistros + 1 ;
}
int VentaArchivo::getCantidadRegistros(){

    FILE* pventa ;

    pventa = fopen(archivo_Venta, "rb") ;

    if(pventa == nullptr){

        cout << "NO SE PUDO CREAR EL ARCHIVO" ;

        return false ;
    }

    fseek(pventa, 0, SEEK_END) ;

    int tamanoBytes = ftell(pventa) ;

    fclose(pventa) ;

    return tamanoBytes / sizeof(Venta) ;

}

int VentaArchivo::buscarPosicion(int id_venta){

    Venta reg;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad ; i++){

        reg = leer(i) ;

        if(reg.getID_Venta() == id_venta){

            return i ;
        }
    }

    return -1 ;
}
