#include <iostream>
#include <string>
using namespace std;

/*
    Dada una serie de caracteres que conforman una oración, donde cada palabra está separada de la siguiente por un carácter blanco y la 
oración finaliza con un punto. Se pide informar:

    1. cantidad de veces que apareció cada vocal
    2. cantidad de palabras que contiene la oración
    3. cantidad de letras que posee la palabra más larga.
*/

int main() {
    string oracion;

    cout << "Ingrese una oracion: " << endl;
    getline(cin, oracion);
    cout << oracion << endl;

    int cantidadPalabras = 0;
    int cantidadLetras = 0;
    int cantidadLetrasPalabraMasLarga = 0;
    int cantidadVocales = 0;

    for (int i = 0; i < oracion.length(); i++) {
        // 1. Cantidad de veces que apareció cada vocal
        if (oracion[i] == 'a' || oracion[i] == 'e' || oracion[i] == 'i' || oracion[i] == 'o' || oracion[i] == 'u' ||
            oracion[i] == 'A' || oracion[i] == 'E' || oracion[i] == 'I' || oracion[i] == 'O' || oracion[i] == 'U') {
            cantidadVocales++;
        }

        // Contamos letras de la palabra actual
        if (oracion[i] != ' ' && oracion[i] != '.') {
            cantidadLetras++;
        }

        
        if (oracion[i] == ' ' || oracion[i] == '.' || i == oracion.length() - 1) {
            cantidadPalabras++;
            if (cantidadLetras > cantidadLetrasPalabraMasLarga) {
                cantidadLetrasPalabraMasLarga = cantidadLetras;
            }
            cantidadLetras = 0;  // Solo reiniciamos aquí
        }
    }

    cout << "Cantidad de palabras: " << cantidadPalabras << endl;
    cout << "Cantidad de vocales: " << cantidadVocales << endl;
    cout << "Cantidad de letras de la palabra mas larga: " << cantidadLetrasPalabraMasLarga << endl;

    return 0;
}
