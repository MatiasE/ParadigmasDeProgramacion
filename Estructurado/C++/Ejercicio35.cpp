#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // ifstream (input file stream) se usa para leer datos de archivos
    ifstream archivoEntrada("CURSO.TXT");
    // ofstream (output file stream) se usa para escribir datos en archivos
    ofstream archivoSalida("APROBADOS.TXT");

    if (!archivoEntrada.is_open() || !archivoSalida.is_open()) {
        cout << "Error al abrir los archivos" << endl;
        return 1;
    }

    string linea;
    int legajo;
    float promedio;

    while (getline(archivoEntrada, linea)) {
        // Extraemos legajo y promedio de la línea
        sscanf(linea.c_str(), "Legajo: %d Promedio: %f", &legajo, &promedio);
        
        // Si el promedio es mayor a 7, escribimos en el nuevo archivo
        if (promedio > 7) {
            archivoSalida << "Legajo: " << legajo << " Promedio: " << promedio << endl;
        }
    }

    archivoEntrada.close();
    archivoSalida.close();

    cout << "Archivo de aprobados creado exitosamente" << endl;
    return 0;
}