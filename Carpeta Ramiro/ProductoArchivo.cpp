#include "ProductoArchivo.h"
#include <iostream>
#include <cstdio>
#include "Utils.h"

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

    // Obtener la posición actual (tamaño total en bytes)

    int tamanioEnBytes = ftell(p) ;

    fclose(p) ;

    // La cantidad es el tamaño total dividido por el tamaño de un registro

    return tamanioEnBytes / sizeof(Producto) ;
}

// 2. Buscar la posición (índice) de un registro por ID

int ProductoArchivo::buscarPosicion(int id_producto) {

    Producto reg ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++) {

        reg = leer(i) ; // Uso el método leer por posición

        // Comparo el ID

        if (reg.getID_Producto() == id_producto) {

            return i ; // Retorna la posición (índice)
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

    // Abrir en modo binario de adición ("ab")

    p = fopen(archivo_Producto, "ab") ;

    if (p == nullptr) {

            cout << "NO SE PUDO CREAR EL ARCHIVO" ;

            return false ; }

    // Escribir el registro al final del archivo
    // fwrite(&variable, tamaño_del_registro, cantidad_de_registros, puntero_archivo)

    int escrito = fwrite(&reg, sizeof(Producto), 1, p) ;

    fclose(p) ;

    // Devuelve true si se escribió 1 registro.

    return escrito ;
}

// LECTURA

Producto ProductoArchivo::leer(int pos) {

    Producto reg ; // Se inicializa con el constructor por defecto

    FILE* p ;

    // Abrir en modo binario de lectura ("rb")

    p = fopen(archivo_Producto, "rb") ;

    if (p == nullptr) {

        return reg ; // Retorna un objeto vacío
    }

    // Mover el puntero a la posición deseada
    // fseek(puntero_archivo, desplazamiento, origen)

    fseek(p, pos * sizeof(Producto), SEEK_SET) ; // SEEK_SET = desde el inicio

    // Leer el registro en la variable 'reg'
    // fread(&variable, tamaño_del_registro, cantidad_de_registros, puntero_archivo)

    fread(&reg, sizeof(Producto), 1, p) ;

    fclose(p) ;

    return reg ;
}

// MODIFICACIÓN (Sobreescribir con datos nuevos)

bool ProductoArchivo::modificar(const Producto &reg) {

    // 1. Buscar la posición del registro

    int pos = buscarPosicion(reg.getID_Producto()) ;

    if (pos == -1) {

        return false ; // El registro a modificar no existe
    }

    FILE* p ;

    // Abrir en modo binario de lectura y escritura ("rb+")

    p = fopen(archivo_Producto, "rb+") ;

    if (p == nullptr) { return false ; }

    // 2. Muevo el puntero a la posición del registro a modificar

    fseek(p, pos * sizeof(Producto), SEEK_SET) ;

    // Sobreescribo el registro con el objeto 'reg' (que ya trae los datos modificados)

    int escrito = fwrite(&reg, sizeof(Producto), 1, p) ;

    fclose(p) ;

    return escrito ;
}

// BAJA LÓGICA

bool ProductoArchivo::bajaLogica(int id_producto) {

    // 1. Busco la posición del registro

    int pos = buscarPosicion(id_producto) ;

    if (pos == -1) {

        return false ; // Producto no encontrado
    }

    // Leo el registro en la posición encontrada

    Producto reg = leer(pos) ;

    // Modifico el estado a falso (baja lógica)

    reg.setEstado(false);

    // 4. Sobreescribo el registro modificado en la misma posición (reutilizando la lógica de Modificar)
    // "rb+" para reescribir

    FILE* p ;

    p = fopen(archivo_Producto, "rb+") ;

    if (p == nullptr) { return false ; }

    // Mover el puntero a la posición

    fseek(p, pos * sizeof(Producto), SEEK_SET) ;

    // Sobreescribir (write) el registro modificado

    int escrito = fwrite(&reg, sizeof(Producto), 1, p) ;

    fclose(p) ;

    return escrito ;
}

// ALTA

bool ProductoArchivo::altaLogica(int id_producto) {

    // 1. Busco la posición del registro

    int pos = buscarPosicion(id_producto) ;

    if (pos == -1) {

        return false ; // Producto no encontrado
    }

    // Leo el registro en la posición encontrada

    Producto reg = leer(pos) ;

    // Modifico el estado a falso (baja lógica)

    reg.setEstado(true) ;

    // 4. Sobreescribo el registro modificado en la misma posición (reutilizando la lógica de Modificar)
    // "rb+" para reescribir

    FILE* p ;

    p = fopen(archivo_Producto, "rb+") ;

    if (p == nullptr) { return false ; }

    // Mover el puntero a la posición

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

    // 2. obtengo la posición (cantidad de bytes)

    int bytes = ftell(p) ;

    // 3. Cierro el archivo inmediatamente

    fclose(p) ;

    // Si el archivo está vacío (0 bytes), el primer ID es 1.

    if (bytes == 0) {

        return 1 ;
    }

    // 4. Calculo el número de registros: (Total de bytes / Tamaño de un registro)

    // El ID del último registro es igual al número total de registros (asumiendo que empiezan en 1).

    int numRegistros = bytes / sizeof(Producto) ;

    // 5. El nuevo ID es el número de registros existentes + 1.

    return numRegistros + 1 ;
}

float ProductoArchivo::buscarPrecio(int idBuscado){

    FILE* archivoP ;

    Producto reg ;

    archivoP = fopen(archivo_Producto,"rb") ;

    if(archivoP == nullptr){ return 0 ; } ;

    while(fread(&reg,sizeof(Producto),1,archivoP)){

        if(reg.getID_Producto() == idBuscado){

            fclose(archivoP) ;

            return reg.getPrecioActual() ;
        }
    }

    fclose(archivoP) ;

    return 0 ;
}


// Implementacion método de validacion

// Devuelve true si la descripcion es valida

bool ProductoArchivo::validarDescripcion(const std::string &descripcion_a_validar) {

    // Validar que no exista otro producto con la misma descripción
    // El tamaño máximo en Producto.h es 200 (char descripcion[200])

    Producto reg ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++) {

        reg = leer(i);

        // Usar strncmp para comparar con la longitud del miembro del objeto

        // Asumo que getDescripcion() devuelve un char*

        if (strcmp(reg.getDescripcion(), descripcion_a_validar.c_str()) == 0) {

            cout << "ERROR: Ya existe un producto con esta descripcion: " << reg.getDescripcion() << endl ;

            return false ;
        }
    }

    return true; // La descripción es válida
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

    if (pos == -1)
    {

        cout << "ERROR: ID de producto no encontrado." << endl ;

        system("pause") ;

        return ;
    }

    // Cargar el objeto producto actual desde el archivo

    Producto producto_modificado = leer(pos) ;



    do
    {

        system("cls") ;

        cout << "Producto a Modificar (ID: " <<producto_modificado.getID_Producto() << "):" << endl ;

        cout << "-----------------------------" << endl ;

        producto_modificado.mostrar() ; // Muestra el estado actual del producto

        cout << "Seleccione el campo a modificar:" << endl ;

        cout << "1. Marca" << endl ;

        cout << "2. Descripcion" << endl ;

        cout << "3. Precio" << endl ;

        cout << "4. Tipo de producto" << endl ;

        cout << "5. Garantia" << endl ;

        cout << "6. Cantidad" << endl ;

        cout << "7. Finalizar" << endl ;

        cout << "0. Volver al menu anterior " << endl ;

        cout << endl << "Opcion: " ;

        cin >> opcion ;

        cout << endl ;

        switch (opcion)
        {

        case 1:   // Modificar marca (string)
        {

            cout << "Modificar marca: " ;

            nuevo_dato_str = cargarCadena() ;

            string aux = producto_modificado.getMarca();

            producto_modificado.setMarca(nuevo_dato_str) ;

            if (producto_modificado.getMarca() != aux)
            {

                cout << endl << "Marca modificada y guardada con exito en el archivo." << endl ;
                modificar(producto_modificado);

            }
            else
            {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 2:   // Modificar Descripcion
        {

            string nueva_desc ;

            cout << "Nueva descripcion: " ;

            nueva_desc = cargarCadena() ;

            string aux = producto_modificado.getDescripcion();

            producto_modificado.setDescripcion(nueva_desc) ;

            if (producto_modificado.getDescripcion() != aux)
            {

                cout << endl << "Descripcion modificada y guardada con exito en el archivo." << endl ;
                  modificar(producto_modificado);

            }
            else
            {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 3:   // Modificar Precio
        {

            float nuevo_precio ;

            cout << "Nuevo precio: $" ;

            cin >> nuevo_precio ;

            float aux = producto_modificado.getPrecioActual();

            producto_modificado.setPrecioActual(nuevo_precio) ;

            if (producto_modificado.getPrecioActual() != aux)
            {

                cout << endl << "Precio modificado y guardado con exito en el archivo." << endl ;
                modificar(producto_modificado);

            }
            else
            {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 4:
        {

            int nuevo_tipo ;

            cout << "Nuevo tipo de producto" ;

            cin >> nuevo_tipo ;

            int aux = producto_modificado.getTipoProducto();

            producto_modificado.setTipoProducto(nuevo_tipo) ;

            if (producto_modificado.getTipoProducto() !=  aux)
            {

                cout << endl << "Tipo de producto modificado y guardado con exito en el archivo." << endl ;
                modificar(producto_modificado);

            }
            else
            {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 5:
        {

            int nueva_garantia ;

            cout << "Nueva garantia" ;

            cin >> nueva_garantia ;

            int aux = producto_modificado.getGarantia();

            producto_modificado.setGarantia(nueva_garantia) ;

            if (producto_modificado.getGarantia() != aux)
            {

                cout << endl << "Garantia modificada y guardada con exito en el archivo." << endl ;
                modificar(producto_modificado);

            }
            else
            {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 6:
        {

            int nueva_cantidad ;

            cout << "Nueva cantidad" ;

            cin >> nueva_cantidad ;

            int aux = producto_modificado.getCantStock();

            producto_modificado.setCantidadStock(nueva_cantidad) ;

            if (producto_modificado.getCantStock() !=  aux)
            {

                cout << endl << "Cantidad modificada y guardada con exito en el archivo." << endl ;
                modificar(producto_modificado);

            }
            else
            {

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
