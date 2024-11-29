#include <iostream>
#include <fstream>

using namespace std;

/*
    Se conoce de cada alumno de un curso los siguientes datos: 
    legajo (8dígitos) y  las notas de 2 parciales (0..10), que finaliza con un legajo negativo.

	Se pide desarrollar un programa que ingrese los datos de los alumnos por teclado y grabe un 
    archivo de texto CURSO.TXT con una línea por cada alumno, con el número de legajo y su promedio (real).
*/

int main() {
    int legajo;
    float nota1, nota2, promedio;
    ofstream archivo;
    archivo.open("CURSO.TXT");

    cout << "Ingrese el legajo: ";
    cin >> legajo;

    while (legajo > 0) {
        cout << "Ingrese la nota del primer parcial: ";
        cin >> nota1;
        cout << "Ingrese la nota del segundo parcial: ";
        cin >> nota2;
        promedio = (nota1 + nota2) / 2;

        // TODO: Guardar en un archivo de texto CURSO.TXT
        archivo << "Legajo: " << legajo << " Promedio: " << promedio << endl;

        cout << "Ingrese el legajo: ";
        cin >> legajo;
    }

    archivo.close();
    cout << "Archivo guardado correctamente." << endl;

    return 0;
}