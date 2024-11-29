#include <iostream>
#include <string>
using namespace std;

/*
    Dada el siguiente dibujo de un  registro y su correspondiente declaración en C++, 
    especifique la nomenclatura para acceder al registro y cada uno de sus campos, 
    y las operaciones que se pueden realizar a nivel registro y a nivel campos. 
    Defina otro registro del mismo tipo de datos.  

    Legajo: 8 digitos,
    ApellidoNombre: 25 caracteres,
    Nota1: 0..10.
*/

struct Alumno {
    int legajo;
    string apellidoNombre;
    float nota1;
};

int main() {
    Alumno alumno;

    cout << "Ingrese el legajo: ";
    cin >> alumno.legajo;
    cin.ignore();

    cout << "Ingrese el apellido y nombre: ";
    getline(cin, alumno.apellidoNombre);

    cout << "Ingrese la nota del primer parcial: ";
    cin >> alumno.nota1;
    cin.ignore();

    cout << "Legajo: " << alumno.legajo << endl;
    cout << "Apellido y nombre: " << alumno.apellidoNombre << endl;
    cout << "Nota del primer parcial: " << alumno.nota1 << endl;

    return 0;
}
