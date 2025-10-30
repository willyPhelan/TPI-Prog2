#pragma once
#include <string>

class Persona {

public:


    Persona( // constructor por defecto

        int id = 0, const std::string& nombre = "N/A" , const std::string &apellido = "N/A" , const std::string &telefono = "" , const std::string &direccion = "" , const std::string& cuit = "" , bool estado = true );

    // Getters

    int getID() const ;

    std::string getNombre() const ;

    std::string getApellido() const ;

    std::string getTelefono() const ;

    std::string getDireccion() const ;

    std::string getCuit() const ;

    bool getEstado() const ;

    // Setters

    void setID(int id) ;

    void setNombre(const std::string &nombre) ;

    void setApellido(const std::string &apellido) ;

    void setTelefono(const std::string &telefono) ;

    void setDireccion(const std::string &direccion) ;

    void setCuit(const std::string &cuit) ;

    void setEstado(bool estado) ;

    // metodos

    void mostrar() const ;

    void cargar() ;


private:

    int idPersona ;

    char nombre[30] ;

    char apellido[30] ;

    char telefono [20] ;

    char direccion [50] ;

    char cuit [13] ;

    bool estado ;



};
