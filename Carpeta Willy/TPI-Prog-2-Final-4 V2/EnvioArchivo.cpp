#include "EnvioArchivo.h"
#include <iostream>

using namespace std ;

int EnvioArchivo::getCantidadRegistros(){

    FILE* p = fopen(archivo_Envio, "rb") ;

    if (p == nullptr){ return 0 ; }

    fseek(p, 0, SEEK_END) ;

    long bytes = ftell(p) ;

    fclose(p) ;

    if (bytes == 0){ return 0 ; }

    return bytes / sizeof(Envio) ;
}

int EnvioArchivo::obtenerID(){

    return getCantidadRegistros() + 1 ;
}

int EnvioArchivo::buscarPosicion(int id_envio){

    Envio reg ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++){

        reg = leer(i) ;

        if (reg.getID_Envio() == id_envio){

            return i ;
        }
    }

    return -1 ;
}

int EnvioArchivo::buscarPosicionPorID_Venta(int id_venta){

    Envio reg ;

    int cantidad = getCantidadRegistros() ;

    for (int i = 0; i < cantidad; i++){

        reg = leer(i) ;

        if (reg.getID_Venta() == id_venta){

            return i ;
        }
    }

    return -1 ;
}


bool EnvioArchivo::guardar(const Envio &reg){

    FILE* p = fopen(archivo_Envio, "ab") ;

    if (p == nullptr){ return false ; }

    int escrito = fwrite(&reg, sizeof(Envio), 1, p) ;

    fclose(p) ;

    return escrito  ;
}


Envio EnvioArchivo::leer(int pos){

    Envio reg ;

    FILE* p = fopen(archivo_Envio, "rb") ;

    if (p == nullptr || pos < 0){ return reg ; }

    fseek(p, pos * sizeof(Envio), SEEK_SET) ;

    fread(&reg, sizeof(Envio), 1, p) ;

    fclose(p) ;

    return reg ;
}


bool EnvioArchivo::modificar(const Envio &reg){

    int pos = buscarPosicion(reg.getID_Envio()) ;

    if (pos == -1){ return false ; }

    FILE* p = fopen(archivo_Envio, "rb+") ;

    if (p == nullptr){ return false ; }

    fseek(p, pos * sizeof(Envio), SEEK_SET) ;

    int escrito = fwrite(&reg, sizeof(Envio), 1, p) ;

    fclose(p) ;

    return escrito  ;
}

bool EnvioArchivo::bajaLogica(int id_envio){

    int pos = buscarPosicion(id_envio) ;

    if (pos == -1){ return false ; }

    Envio reg = leer(pos) ;

    if (reg.getEstado () == false){ return false ; }

    reg.setEstado(false) ;

    return modificar(reg) ;
}

bool EnvioArchivo::altaLogica(int id_envio){

    int pos = buscarPosicion(id_envio) ;

    if (pos == -1){ return false ; }

    Envio reg = leer(pos) ;

    if (reg.getEstado() == true) { return false ; }

    reg.setEstado(true) ;

    return modificar(reg) ;
}


void EnvioArchivo::modificarCampos(){

    int id_a_buscar ;

    int opcion ;

    int nuevo_dato_int ;

    cout << "Modificar un campo especifico de un envio" << endl ;

    cout << "-------------------------------------------" << endl ;

    cout << "Ingrese el ID del envio a modificar: " ;

    cin >> id_a_buscar ;

    int pos = buscarPosicion(id_a_buscar) ;

    if (pos == -1){

        cout << "ERROR: ID de envio no encontrado." << endl ;

        system("pause") ;

        return ;
    }

    Envio envio_modificar = leer(pos) ;

    do{

        system("cls") ;

        cout << "Envio a modificar (ID: " << envio_modificar.getID_Envio() << "):" << endl ;

        cout << "-----------------------------" << endl ;

        envio_modificar.mostrar() ;

        cout << endl << "Seleccione el campo a modificar:" << endl ;

        cout << "1. Fecha de entrega" << endl ;

        cout << "2. Valor del envio" << endl ;

        cout << "3. Estado del envio" << endl ;

        cout << "0. Volver al menu anterior " << endl ;

        cout << endl << "Opcion: " ;

        cin >> opcion ;

        cout << endl ;

        switch (opcion){

        case 1: {

            int dia, mes, anio ;

            Fecha nueva_fecha ;

            VentaArchivo archivoVenta ;

            Venta ventaAsociada ;

            Fecha fechaVenta ;

            int idVenta = envio_modificar.getID_Venta() ;

            int posVenta = archivoVenta.buscarPosicion(idVenta) ;

            if (posVenta != -1){

                ventaAsociada = archivoVenta.leer(posVenta) ;

                fechaVenta = ventaAsociada.getFechaVenta() ;

                cout << "La fecha de la venta original es: " ;

                fechaVenta.mostrar() ;

                cout << endl ; }

            else {

                cout << "Advertencia: No se pudo encontrar la Venta (ID " << idVenta << ") asociada." << endl ; }

            bool fechaValida = false ;

            do {

                cout << "-----------------------------------" << endl ;

                cout << "Ingrese la nueva fecha de entrega" << endl ;

                cout << "Dia de entrega: " ;

                cin >> dia ;

                while (dia < 1 || dia > 31){

                    cout << "El dia que ingreso es invalido. Intentelo de nuevo." << endl ;

                    cout << "Dia: " ;

                    cin >> dia ; }


                cout << "Mes de entrega: " ;

                cin >> mes ;

                while (mes < 1 || mes > 12){

                    cout << "El mes que ingreso es invalido. Intentelo de nuevo." << endl ;

                    cout << "Mes: " ;

                    cin >> mes ; }

                cout << "Anio de entrega: " ;

                cin >> anio ;

                while (anio < 2000 || anio > 2025){

                    cout << "El anio que ingreso es invalido. Intentelo de nuevo." << endl ;

                    cout << "Anio: " ;

                    cin >> anio ;
                }

                nueva_fecha.setDia(dia) ;

                nueva_fecha.setMes(mes) ;

                nueva_fecha.setAnio(anio) ;


                if (nueva_fecha.esMayorOIgualA(fechaVenta)){

                    envio_modificar.setFecha_Entrega(nueva_fecha) ;

                    fechaValida = true ; }

                else {

                    cout << endl << "ERROR: La fecha de entrega (" ;

                    nueva_fecha.mostrar() ;

                    cout << ") debe ser IGUAL O POSTERIOR a la fecha de la venta (" ;

                    fechaVenta.mostrar() ;

                    cout << "). Intente de nuevo." << endl << endl ; }

            } while(!fechaValida) ;

            if (modificar(envio_modificar)){

                cout << endl << "Fecha de entrega modificada y guardada con exito." << endl ; }

            else {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ; }

        case 2: {

            float nuevo_valor ;

            cout << "Nuevo valor del envio: $" ;

            cin >> nuevo_valor ;

            envio_modificar.setValor_Envio(nuevo_valor) ;

            if (modificar(envio_modificar)){

                cout << endl << "Valor del envio modificado y guardado con exito." << endl ; }

            else{

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ;
            }

            system("pause") ;

            break ;
        }

        case 3: {

            cout << "Nuevo Estado (1-Pendiente, 2-En curso, 3-Entregado): " ;

            cin >> nuevo_dato_int ;

            while (nuevo_dato_int < 1 || nuevo_dato_int > 3){

                cout << "La opcion que ingreso es invalida. Intentelo de nuevo." << endl;

                cout << "Estado de Entrega (1- Pendiente, 2- En curso, 3- Entregado): " ;

                cin >> nuevo_dato_int ;

            }

            envio_modificar.setEstado_Entrega(nuevo_dato_int) ;

            if (modificar(envio_modificar)){

                cout << endl << "Estado del envio modificado y guardado con exito." << endl ;

            } else {

                cout << endl << "ERROR: No se pudo guardar la modificacion en el archivo." << endl ; }

            system("pause") ;

            break ;
        }

        case 0:

            cout << "Volviendo al menu anterior." << endl ;

            return ;

        default:

            cout << "Opcion invalida. Intente de nuevo." << endl ;

            system("pause") ;
        }

    }

    while (opcion != 0) ;
}

bool EnvioArchivo::hacerBackup (){

    FILE* pArchivoOriginal = fopen(archivo_Envio,"rb") ;

    if(pArchivoOriginal == nullptr){ return false ; }

    FILE* pBackup = fopen(archivo_Envio_Backup,"wb") ;

    if(pBackup == nullptr){

        fclose(pArchivoOriginal) ;

        return false ; }

    char temporal[1024] ;

    int bytesLeidos ;

    while((bytesLeidos = fread(temporal, 1, 1024, pArchivoOriginal)) > 0){

    fwrite(temporal, 1, bytesLeidos, pBackup) ; }

    fclose(pArchivoOriginal) ;

    fclose(pBackup) ;

    return true ;

}

bool EnvioArchivo::restaurarBackup (){

    FILE* pArchivoBkp = fopen(archivo_Envio_Backup, "rb") ;

    if (pArchivoBkp == nullptr){ return false ;}

    FILE* pArchivoOriginal = fopen(archivo_Envio, "wb") ;

    if (pArchivoOriginal == nullptr){

        fclose(pArchivoBkp) ;

        return false ;
    }

    char temporal[1024] ;

    int bytesLeidos ;

    while ((bytesLeidos = fread(temporal, 1, 1024, pArchivoBkp)) > 0){

        fwrite(temporal, 1, bytesLeidos, pArchivoOriginal) ; }

    fclose(pArchivoBkp) ;

    fclose(pArchivoOriginal) ;

    return true ;

}
