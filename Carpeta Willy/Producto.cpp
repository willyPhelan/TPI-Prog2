#include "Utils.h"
#include "Producto.h"
#include "ProductoArchivo.h"
#include "Utils.h"
#include <cstring>
#include <iostream>


using namespace std ;

// constructores

Producto::Producto() // por defecto con lista de inicializacion

: ID_Producto(0), ID_Proveedor(), descripcion{}, marca{}, tipoProducto(0), precioActual(0.0), garantia(0), cantidadStock(0), estado(true)
{} // inicializo los arrays marca y descripcion vacios

// consturctor con parametros

Producto::Producto(int _id_Producto, int _id_Proveedor, const string &descripcion, const string &marca ,int _tipoProducto, float _precioActual, int _garantia, int _cantStock, bool _estado)

// Aca ID_Proveedor() llama al constructor por defecto de Proveedor

: ID_Producto(_id_Producto), ID_Proveedor(), tipoProducto(_tipoProducto), precioActual(_precioActual), garantia(_garantia), cantidadStock(_cantStock), estado(_estado)
{
 // setters para asignar cadenas de texto

    setDescripcion(descripcion) ;

    setMarca(marca) ;

}

// getters

int Producto::getID_Producto() const {

    return ID_Producto ;
}

int Producto::getID_Proveedor() const { // la funcion devuelve un proveedor (composicion)

    return ID_Proveedor ;

}

const char* Producto::getDescripcion() const {

    return descripcion ;
}

const char* Producto::getMarca() const {

    return marca ;
}

int Producto::getTipoProducto() const {

    return tipoProducto ;
}

float Producto::getPrecioActual() const {

    return precioActual ;
}

int Producto::getGarantia() const {

    return garantia ;
}

int Producto::getCantStock() const {

    return cantidadStock ;
}

bool Producto::getEstado() const {

    return estado ;
}

// setters

void Producto::setID_Producto(int _idProducto){

    ID_Producto = _idProducto ;
}

void Producto::setID_Proveedor(int id_Proveedor){

    ID_Proveedor = ID_Proveedor ;
}

void Producto::setDescripcion(const std::string &_descripcion){

    strncpy(this->descripcion, _descripcion.c_str(), 19) ;
 }

  void Producto::setMarca(const std::string &_marca){

    strncpy(this->marca, _marca.c_str(), 19) ;
 }

 void Producto::setTipoProducto(int _tipoProducto){

    tipoProducto = _tipoProducto ;
 }

 void Producto::setPrecioActual(float _precioActual){

    precioActual = _precioActual;
 }

 void Producto::setGarantia(int _garantia){
    garantia = _garantia;
 }

 void Producto::setCantidadStock(int _cantStock){

    cantidadStock = _cantStock ;
 }

 void Producto::setEstado(bool _estado){

    this-> estado = _estado ;
 }

void Producto::cargar(){

    ProductoArchivo archivoProd ;

    Producto productoExistente ;

    int cantReg = archivoProd.getCantidadRegistros() ;

    string str ; // Para cargar Marca

    string descripcionNueva ;

    bool descripcionValida = false ;

    int opcion ;

    do {

        cout << "Ingrese la descripcion del producto: " ;


        cin >> descripcionNueva ;


    } while (!archivoProd.validarDescripcion(descripcionNueva)) ;

    this->setDescripcion(descripcionNueva);



    // Asignación de ID Autoincremental

    setID_Producto(archivoProd.obtenerID()) ;

    // Marca
    // CORRECCIÓN 2: Línea reescrita para eliminar el carácter invisible.

    cout << "Ingrese la Marca del Producto: " ;

    str = cargarCadena() ;

    setMarca(str) ;

    // Tipo de Producto

    cout << "Ingrese Tipo de Producto (1-PCS, 2-Accesorios, 3-Otros): " ;

    cin >> tipoProducto ;

    setTipoProducto(tipoProducto) ;

    // Precio Actual

    cout << "Ingrese el precio (en pesos) del producto: $" ;

    cin >> precioActual ;

    setPrecioActual(precioActual) ;

    // Garantía

    cout << "Ingrese la garantia (en meses) que tiene el producto: " ;

    cin >> garantia ;

    setGarantia(garantia) ;

    // Cantidad en Stock

    cout << "Ingrese la cantidad que hay del producto: " ;

    cin >> cantidadStock ;

    setCantidadStock(cantidadStock) ;

    // El estado es true por defecto.

      if (archivoProd.guardar(*this)) {

                        cout << endl << "Producto cargado con exito." << endl ; } else {

                        cout << "ERROR: No se pudo guardar el producto en el archivo." << endl ; }

            }


void Producto::mostrar(){

    cout << "ID de producto: " << getID_Producto() << endl ;

    cout << "ID de proveedor: " << 200 << endl ;

    cout << "Descripcon: " << getDescripcion() << endl ;

    cout << "Marca: " << getMarca() << endl ;

    cout << "Tipo de producto: " << getTipoProducto() << endl ;

    cout << "Precio actual: $" << getPrecioActual() << endl ;

    cout << "Garantia del producto: " << getGarantia() << " Mes/es" << endl ;

    cout << "Cantidad del producto en stock: " << getCantStock() << endl ;

    cout << "Estado: " << (getEstado() ? "Activo" : "Inactivo") << endl << endl ;

}


void Producto::modificarCampos() {



    ProductoArchivo archivo ;



    int id_a_buscar ;



    int opcion ;



    string nuevo_dato_str ;



    cout << "Modificar un campo especifico del producto" << endl ;



    cout << "-------------------------------------------" << endl ;



    cout << "Ingrese el ID del producto a modificar: " ;



    cin >> id_a_buscar ;



    int pos = archivo.buscarPosicion(id_a_buscar) ;



    if (pos == -1) {



        cout << "ERROR: ID de producto no encontrado." << endl ;



        system("pause") ;



        return ;

    }



    // Cargar el objeto producto actual desde el archivo



    *this = archivo.leer(pos) ;





    do {



        system("cls") ;



        cout << "Producto a Modificar (ID: " << this->getID_Producto() << "):" << endl ;



        cout << "-----------------------------" << endl ;



        this->mostrar() ; // Muestra el estado actual del producto



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



        switch (opcion) {



            case 1: { // Modificar marca (string)



                cout << "Modificar marca: " ;



                nuevo_dato_str = cargarCadena() ;



                this->setMarca(nuevo_dato_str) ;



                if (archivo.modificar(*this)) {



                    cout << endl << "Marca modificada y guardada con exito en el archivo." << endl ;



                } else {



                    cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;

                }



                system("pause") ;



                break ; }



            case 2: { // Modificar Descripcion



                string nueva_desc ;



                cout << "Nueva descripcion: " ;



                nueva_desc = cargarCadena() ;



                this->setDescripcion(nueva_desc) ;



                if (archivo.modificar(*this)) {



                    cout << endl << "Descripcion modificada y guardada con exito en el archivo." << endl ;



                } else {



                    cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;

                }



                system("pause") ;



                break ;

            }



            case 3: { // Modificar Precio



                float nuevo_precio ;



                cout << "Nuevo precio: $" ;



                cin >> nuevo_precio ;



                this->setPrecioActual(nuevo_precio) ;



                if (archivo.modificar(*this)) {



                    cout << endl << "Precio modificado y guardado con exito en el archivo." << endl ;



                } else {



                    cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;

                }



                system("pause") ;



                break ;

            }



            case 4: {



                int nuevo_tipo ;



                cout << "Nuevo tipo de producto" ;



                cin >> nuevo_tipo ;



                this->setTipoProducto(nuevo_tipo) ;



                if (archivo.modificar(*this)) {



                    cout << endl << "Tipo de producto modificado y guardado con exito en el archivo." << endl ;



                } else {



                    cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;

                }



                system("pause") ;



                break ; }



            case 5: {



                int nueva_garantia ;



                cout << "Nueva garantia" ;



                cin >> nueva_garantia ;



                this->setGarantia(nueva_garantia) ;



                if (archivo.modificar(*this)) {



                    cout << endl << "Garantia modificada y guardada con exito en el archivo." << endl ;



                } else {



                    cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;

                }



                system("pause") ;



                break ; }



            case 6: {



                int nueva_cantidad ;



                cout << "Nueva cantidad" ;



                cin >> nueva_cantidad ;



                this->setCantidadStock(nueva_cantidad) ;



                if (archivo.modificar(*this)) {



                    cout << endl << "Cantidad modificada y guardada con exito en el archivo." << endl ;



                } else {



                    cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;

                }



                system("pause") ;



                break ; }



             case 7: {



                cout << "Finalizando y volviendo al menu anterior" ;



                break ; }





            case 0:



                cout << "Volviendo al menu anterior" << endl ;



                return ;



            default:



                cout << "Opcion invalida." << endl ;



                system("pause") ;

        }



    } while (opcion != 7) ;



    // Guardar el objeto 'this' (con los cambios en memoria) en el archivo



    if (archivo.modificar(*this)) {



        cout << "El producto ha sido modificado y guardado con éxito." << endl ;



    } else {



        cout << "ERROR: No se pudo guardar la modificación en el archivo." << endl ;

    }



}


