#include "Proveedor.h"
#include "ProveedorArchivo.h"
#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std ;

// Constructor


Proveedor::Proveedor() : tipo_proveedor(0) {
}

Proveedor::Proveedor(int tipo_proveedor) {

    setTipo_proveedor(tipo_proveedor) ;
}

// Getters

int Proveedor::getTipo_proveedor() {

    return tipo_proveedor ;
}


string Proveedor::getMail() const {

    return mail ; }

// Setters

void Proveedor::setTipo_proveedor(int tipo_proveedor) {

    this->tipo_proveedor = tipo_proveedor ;
}

void Proveedor::setMail(std::string mail) {

    // strncpy para copiar la cadena al array char[30] de forma segura

    strncpy(this->mail, mail.c_str(), 29) ;

    this->mail[29] = '\0' ; }

// Metodos

void Proveedor::cargar() {

    string datos ;

    int datos2 ;

    Proveedor proveedor1 ;

    ProveedorArchivo archivo;

    int tipo_proveedor ;

    int const cantReg = archivo.getCantidadRegistros() ;

    cout << "Ingrese el CUIT del proveedor: "  ;

    cin >> datos ;

    for (int i = 0; i <cantReg ; i++){

        proveedor1 = archivo.leer(i) ;

        while (strcmp(datos.c_str(), proveedor1.getCuit().c_str()) == 0 && proveedor1.getEstado() == true){

            cout << "El CUIT ya corresponde a un proveedor existente. Desea salir o introducir otro CUIT? (1- Agregar otro CUIT, 2- Salir):" ;

            cin >> datos2 ;

            switch (datos2){

            case 1:

                cout << "Ingrese el nuevo CUIT: "  ;

                cin >> datos ;

                break ;

            case 2:

                cout << endl << "Saliendo..." << endl ;

                return ;

                break ;

            default:

                cout << "La opcion que eligio es invalida. Intentelo de nuevo. " << endl ;

                break ;
            }

        }
    }

    Proveedor::setCuit(datos) ;

    cout << "Ingrese el tipo de proveedor (1-Empresa, 2-Particular, 3-Servicios):  " ;

    cin >> tipo_proveedor ;

    Proveedor::setTipo_proveedor(tipo_proveedor) ;

    cout << "Ingrese el nombre del proveedor: " ;

    datos = cargarCadena() ;

    Proveedor::setNombre(datos) ;

    cout << "Ingrese el numero de telefono del proveedor: " ;

    cin >> datos ;

    Proveedor::setTelefono(datos) ;

    cout << "Ingrese la direccion del proveedor: "  ;

    datos = cargarCadena() ;

    Proveedor::setDireccion(datos) ;

    cout << "Ingrese el mail del proveedor: "  ;

    datos = cargarCadena() ;

    Proveedor::setMail(datos) ;

    Proveedor::setEstado(true) ;

    cout << endl << "El proveedor fue agregado con exito. " << endl ;

}

void Proveedor::mostrar(){

    cout << "Informacion del proveedor: " << endl ;

    cout << endl ;

    cout << "ID del proveedor: " << Proveedor::getID() << endl ;

    cout << "CUIT del proveedor: " << Proveedor::getCuit() << endl ;

    cout << "Tipo de proveedor: " << Proveedor::getTipo_proveedor() << endl ;

    cout << "Nombre del proveedor: " << Proveedor::getNombre() << endl ;

    cout << "Telefono del proveedor: " << Proveedor::getTelefono() << endl ;

    cout << "Direccion del proveedor: " << Proveedor::getDireccion() << endl ;

    cout << "Mail del proveedor: " << Proveedor::getMail() << endl ;

    if(Proveedor::getEstado()){

    cout << "Estado del proveedor: Activo " << endl ; } else { cout << "Estado del proveedor: Inactivo " << endl ; }

    cout << endl;
}
