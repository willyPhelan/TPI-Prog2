/// Objetivo: Crear un programa que cargue notas de un ex�men y
/// las vuelque en un archivo (nota y nombre de alumno).

#include <iostream>
#include <fstream>

using namespace std;

class Examen ///Clase Examen

{

private: ///Atributos

    string nombre;

    string apellido;

    float nota;

public: ///Metodos

    Examen (string nombre, string apellido, float nota) //Constructor

    {

        this->nombre = nombre;

        this->nota = nota;

        this->apellido = apellido;

    }

    ~Examen () //Destructor

    {

    }

    ///get

    string getNombre () //get de nombre

    {

        return nombre;

    }

    float getNota () //get de nota

    {

        return nota;

    }

    string getApellido () //get de apellido

    {

        return apellido;

    }

    ///set

    void setNombre (string nombre) //set de nombre

    {

        this->nombre = nombre;

    }

    void setNota (float nota) // set de nota

    {

        if (nota <= 0 || nota >=11)

        {

            cout << "Nota invalida. Intentelo de nuevo." << endl;

        }

        else

        {

        this->nota = nota;

        }

    }

    void setApellido (string apellido) //set de apellido

    {

        this->apellido = apellido;

    }

};

///Fin de clase Examen

int main () ///Inicio del main

{

    Examen examen1 ("renzo", "termine" , 5);

    string nombre, apellido;
    float nota;
    int opcion;

    do //Este ciclo do while permite al usuario cargar varias notas
    {

    system ("cls");

    cout << "Ingrese el nombre del alumno: " << endl; //Se le pide al usuario el nombre del alumno
    cin >> nombre;                                    //Se guarda lo que ponga el usuario en una variable local

    system("cls");

    examen1.setNombre (nombre); //Se usa el setter de la clase Examen para guardar en private el nombre

    cout << "Ingrese el apellido del alumno: " << endl; //Se le pide al usuario el apellido del alumno
    cin >> apellido;                                    //Se guarda lo que ponga el usuario en una variable local

    system("cls");

    examen1.setApellido (apellido); //Se usa el setter de la clase Examen para guardar en private el apellido

    cout << "Ingrese la nota del alumno: " << endl; //Se le pide al usuario la nota del alumno
    cin >> nota;                                    //Se guarda lo que ponga el usuario en una variable local

    if (nota<=0 || nota >=11) //Se hace una verificaci�n de datos, por si el usuario cometi� un error

    {

        while (nota<=0 || nota >=11)

        {

            system ("cls");

            cout << "La nota que ingreso es incorrecta. Intentelo de nuevo. " << endl;
            cout << "Ingrese la nota del alumno: " << endl;
            cin >> nota;

            system ("cls");
        }

    }

    system ("cls");

    examen1.setNota (nota); //Se usa el setter de la clase Examen para guardar en private la nota

    ofstream archivo1; //Se crea el archivo para mas tarde guardar los datos ingresados
    archivo1.open ("datos.txt",ios::app); //Se abre el archivo con el nombre datos, extension .txt. Se lo abre de modo de que si ya hay un archivo preexistente, en vez de borrarlo, se le continuar� escribiendo datos
    if (archivo1.fail()) //Se hace una verificaci�n simple para ver si el archivo fue creado correctamente, si no, se cierra el programa

    {

        cout << "Hubo un error al abrir/crear el archivo" << endl;
        return -1;

    }

    archivo1 << "|| Nombre: " << examen1.getNombre() << " || " << " Apellido: " << examen1.getApellido() << " || " << " Nota: " << examen1.getNota() << " || " << endl; //Se escribe el modo en el que ser�n escritos los datos al archivo
    archivo1.close(); //Se cierra el archivo para evitar problemas

    system ("cls");

    cout << "Desea agregar otra calificacion?" << endl;
    cout << "1. SI                      0. NO" << endl;

    cin >> opcion;

    if (opcion!=0 && opcion!=1) //M�s verificaciones

    {

        while (opcion!=0 && opcion!=1)

        {
            system ("cls");

            cout << "La opcion que ingreso es incorrecta. Intentelo de nuevo" << endl;
            cout << "Desea agregar otra calificacion?" << endl;
            cout << "1. SI                      0. NO" << endl;
            cin >> opcion;

            system ("cls");
        }

    }

    } while (opcion!=0);

    system ("cls");
    system ("pause");

    return 0;

}///Fin del main
