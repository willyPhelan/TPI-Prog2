#include "ProductoArchivo.h"
#include <iostream>
#include <cstdio>
#include "Utils.h"

using namespace std ;

int ProductoArchivo::getCantidadRegistros(){

    FILE* p ;

    p = fopen(archivo_Producto, "rb") ;

    if (p == nullptr){ return 0 ; }

    fseek(p, 0, SEEK_END) ;

    int tamanioEnBytes = ftell(p) ;

    fclose(p) ;

    return tamanioEnBytes / sizeof(Producto) ;
}

int ProductoArchivo::buscarPosicion(int id_producto){

    Producto reg ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++){

        reg = leer(i) ;

        if (reg.getID_Producto() == id_producto) {

            return i ;
        }
    }

    return -1 ;
}

bool ProductoArchivo::guardar(const Producto &reg){

    FILE* p ;

    p = fopen(archivo_Producto, "ab") ;

    if (p == nullptr){

        cout << "NO SE PUDO CREAR EL ARCHIVO" ;

        return false ;
    }

    int escrito = fwrite(&reg, sizeof(Producto), 1, p) ;

    fclose(p) ;

    return escrito ;
}

Producto ProductoArchivo::leer(int pos){

    Producto reg ;

    FILE* p ;

    p = fopen(archivo_Producto, "rb") ;

    if (p == nullptr) { return reg ; }

    fseek(p, pos * sizeof(Producto), SEEK_SET) ;

    fread(&reg, sizeof(Producto), 1, p) ;

    fclose(p) ;

    return reg ;
}


bool ProductoArchivo::modificar(const Producto &reg){

    int pos = buscarPosicion(reg.getID_Producto()) ;

    if (pos == -1){ return false ; }

    FILE* p ;

    p = fopen(archivo_Producto, "rb+") ;

    if (p == nullptr) { return false ; }

    fseek(p, pos * sizeof(Producto), SEEK_SET) ;

    int escrito = fwrite(&reg, sizeof(Producto), 1, p) ;

    fclose(p) ;

    return escrito ;
}


bool ProductoArchivo::bajaLogica(int id_producto) {

    int pos = buscarPosicion(id_producto) ;

    if (pos == -1) { return false ; }

    Producto reg = leer(pos) ;

    if (reg.getEstado () == false) { return false ; }

    reg.setEstado(false);

    FILE* p ;

    p = fopen(archivo_Producto, "rb+") ;

    if (p == nullptr){ return false ; }

    fseek(p, pos * sizeof(Producto), SEEK_SET) ;

    int escrito = fwrite(&reg, sizeof(Producto), 1, p) ;

    fclose(p) ;

    return escrito ;
}


bool ProductoArchivo::altaLogica(int id_producto) {

    int pos = buscarPosicion(id_producto) ;

    if (pos == -1){ return false ; }

    Producto reg = leer(pos) ;

    if (reg.getEstado () == true){ return false ; }

    reg.setEstado(true) ;

    FILE* p ;

    p = fopen(archivo_Producto, "rb+") ;

    if (p == nullptr) { return false ; }

    fseek(p, pos * sizeof(Producto), SEEK_SET) ;

    int escrito = fwrite(&reg, sizeof(Producto), 1, p) ;

    fclose(p) ;

    return escrito ;
}

int ProductoArchivo::obtenerID(){

    FILE* p = fopen(archivo_Producto, "rb") ;

    if (p == nullptr){ return 1 ; }

    fseek(p, 0, SEEK_END) ;

    int bytes = ftell(p) ;

    fclose(p) ;

    if (bytes == 0){ return 1 ; }

    int numRegistros = bytes / sizeof(Producto) ;

    return numRegistros + 1 ;
}

float ProductoArchivo::buscarPrecio(int idBuscado){

    FILE* archivoP ;

    Producto reg ;

    archivoP = fopen(archivo_Producto,"rb") ;

    if(archivoP == nullptr){ return 0 ; } ;

    while(fread(&reg, sizeof(Producto), 1, archivoP)) {

        if(reg.getID_Producto() == idBuscado) {

            fclose(archivoP) ;

            return reg.getPrecioActual() ;
        }
    }

    fclose(archivoP) ;

    return 0 ;
}


bool ProductoArchivo::validarDescripcion(const std::string &descripcion_a_validar){

    Producto reg ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++){

        reg = leer(i) ;

        if(reg.getEstado() == false) {

                cout << "El producto esta dado de baja, desea reactivarlo? 1-Si, 2-No:" << endl ;

                int opc ;

                cin >> opc ;

                if(opc == 1) {

                    reg.setEstado(true) ;

                    modificar(reg) ;

                    cout << "Producto dado de alta" << endl ;

                    return false ;

                } else { return false ; }

        }

        if (strcmp(reg.getDescripcion(), descripcion_a_validar.c_str()) == 0){

            cout << "ERROR: Ya existe un producto con esta descripcion: " << reg.getDescripcion() << endl ;

            return false ;
        }
 }

    return true ;
}


bool ProductoArchivo::validarMarca(const std::string &marca_a_validar){

    Producto reg ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++){

        reg = leer(i) ;

        if (strcmp(reg.getMarca(), marca_a_validar.c_str()) == 0){

            cout << "ERROR: Ya existe un producto con esta marca: " << reg.getMarca() << endl ;

            return false ;
        }
 }

    return true ;
}


void ProductoArchivo::modificarCampos(){

    int id_a_buscar ;

    int opcion ;

    string nuevo_dato_str ;

    cout << "Modificar un campo especifico del producto" << endl ;

    cout << "-------------------------------------------" << endl ;

    cout << "Ingrese el ID del producto a modificar: " ;

    cin >> id_a_buscar ;

    int pos = buscarPosicion(id_a_buscar) ;

    if (pos == -1) {

        cout << "ERROR: ID de producto no encontrado." << endl ;

        system("pause") ;

        return ; }

    Producto producto_modificado = leer(pos) ;

    do {

        system("cls") ;

        cout << "Producto a Modificar (ID: " << producto_modificado.getID_Producto() << "):" << endl ;

        cout << "-----------------------------" << endl ;

        producto_modificado.mostrar() ;

        cout << "Seleccione el campo a modificar:" << endl ;

        cout << "1. Descripcion" << endl ;

        cout << "2. Marca" << endl ;

        cout << "3. ID Proveedor" << endl ;

        cout << "4. Precio" << endl ;

        cout << "5. Tipo de producto" << endl ;

        cout << "6. Garantia" << endl ;

        cout << "7. Cantidad" << endl ;

        cout << "0. Finalizar y volver al menu anterior " << endl ;

        cout << endl << "Opcion: " ;

        cin >> opcion ;

        cout << endl ;

        switch (opcion) {

        case 1: {

            string nueva_desc ;

            cout << "Nueva descripcion: " ;

            nueva_desc = cargarCadena() ;

            string aux = producto_modificado.getDescripcion();

            producto_modificado.setDescripcion(nueva_desc) ;

            if (producto_modificado.getDescripcion() != aux) {

                cout << endl << "Descripcion modificada y guardada con exito en el archivo." << endl ;

                modificar(producto_modificado) ; }

            else {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 2: {

            cout << "Modificar marca: " ;

            nuevo_dato_str = cargarCadena() ;

            string aux = producto_modificado.getMarca() ;

            producto_modificado.setMarca(nuevo_dato_str) ;

            if (producto_modificado.getMarca() != aux) {

                cout << endl << "Marca modificada y guardada con exito en el archivo." << endl ;

                modificar(producto_modificado) ; }

            else {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 3: {

            int nuevo_id_proveedor ;

            int pos ;

            do{

            cout << "Nuevo ID del proveedor: " ;

            cin >> nuevo_id_proveedor ;

            ProveedorArchivo nuevo ;

            pos = nuevo.buscarPosicion(nuevo_id_proveedor) ;

            if(pos == -1){ cout << "Error, ID del proveedro no encontrado" << endl ; }

            } while (pos == -1) ;

            int aux = producto_modificado.getID_Proveedor() ;

            producto_modificado.setID_Proveedor(nuevo_id_proveedor) ;

            if (producto_modificado.getID_Proveedor() != aux) {

                cout << endl << "ID de proveedor modificado y guardado con exito en el archivo." << endl ;

                modificar(producto_modificado) ;

            } else {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ;
        }


        case 4: {

            float nuevo_precio ;

            cout << "Nuevo precio: $" ;

            cin >> nuevo_precio ;

            float aux = producto_modificado.getPrecioActual() ;

            producto_modificado.setPrecioActual(nuevo_precio) ;

            if (producto_modificado.getPrecioActual() != aux) {

                cout << endl << "Precio modificado y guardado con exito en el archivo." << endl ;

                modificar(producto_modificado) ; }

            else {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 5: {

            int nuevo_tipo ;

            cout << "Nuevo tipo de producto (1-Pcs 2-Accessorios 3-Otros): " ;

            cin >> nuevo_tipo ;

            int aux = producto_modificado.getTipoProducto() ;

            producto_modificado.setTipoProducto(nuevo_tipo) ;

            if (producto_modificado.getTipoProducto() !=  aux) {

                cout << endl << "Tipo de producto modificado y guardado con exito en el archivo." << endl ;

                modificar(producto_modificado) ;

            } else {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 6: {

            int nueva_garantia ;

            cout << "Nueva garantia: " ;

            cin >> nueva_garantia ;

            int aux = producto_modificado.getGarantia() ;

            producto_modificado.setGarantia(nueva_garantia) ;

            if (producto_modificado.getGarantia() != aux) {

                cout << endl << "Garantia modificada y guardada con exito en el archivo." << endl ;

                modificar(producto_modificado) ;

            } else {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 7: {

            int nueva_cantidad ;

            cout << "Nueva cantidad: " ;

            cin >> nueva_cantidad ;

            int aux = producto_modificado.getCantStock() ;

            producto_modificado.setCantidadStock(nueva_cantidad) ;

            if (producto_modificado.getCantStock() !=  aux) {

                cout << endl << "Cantidad modificada y guardada con exito en el archivo." << endl ;

                modificar(producto_modificado) ;

            } else {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 0:

            cout << "Volviendo al menu anterior" << endl ;

            return ;

        default:

            cout << "Opcion invalida." << endl ;

            system("pause") ;
        }

    }
    while (opcion != 0) ;


}

bool ProductoArchivo::MarcaPorID(int idBuscado, char* marcaDestino, int tam){

    FILE* p = fopen(archivo_Producto, "rb") ;

    if (p == nullptr) {

        strncpy(marcaDestino, "ERROR_FILE", tam - 1) ;

        marcaDestino[tam - 1] = '\0' ;

        return false ;
    }

    Producto reg ;

    while(fread(&reg, sizeof(Producto), 1, p) == 1){

        if (reg.getID_Producto() == idBuscado){

            strncpy(marcaDestino, reg.getMarca(), tam - 1) ;

            marcaDestino[tam - 1] = '\0' ;

            fclose(p) ;

            return true ;
        }
    }

    fclose(p) ;

    strncpy(marcaDestino, "DESCONOCIDA", tam - 1) ;

    marcaDestino[tam - 1] = '\0' ;

    return false ;
}


bool ProductoArchivo::hacerBackup(){

    FILE* pArchivoOriginal = fopen(archivo_Producto,"rb") ;

    if(pArchivoOriginal == nullptr){

        return false ;
    }

    FILE* pBackup = fopen(archivo_Producto_Backup,"wb") ;

    if(pBackup == nullptr){

        fclose(pArchivoOriginal) ;

        return false ;
    }


    char temporal[1024] ;

    int bytesLeidos ;


    while((bytesLeidos = fread(temporal, 1, 1024, pArchivoOriginal)) > 0) {

        fwrite(temporal, 1, bytesLeidos, pBackup) ;
    }


    fclose(pArchivoOriginal) ;

    fclose(pBackup) ;

    return true ;

}

bool ProductoArchivo::restaurarBackup (){

    FILE* pArchivoBkp = fopen(archivo_Producto_Backup, "rb") ;

    if (pArchivoBkp == nullptr){

        return false ;
    }

    FILE* pArchivoOriginal = fopen(archivo_Producto, "wb") ;

    if (pArchivoOriginal == nullptr){

        fclose(pArchivoBkp) ;

        return false ;
    }

    char temporal[1024] ;

    int bytesLeidos ;

    while((bytesLeidos = fread(temporal, 1, 1024, pArchivoBkp)) > 0){

        fwrite(temporal, 1, bytesLeidos, pArchivoOriginal) ;
    }

    fclose(pArchivoBkp) ;

    fclose(pArchivoOriginal) ;

    return true ;

}
