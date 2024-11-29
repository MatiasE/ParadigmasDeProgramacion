#include <iostream>
using namespace std;

/* 
    Se dispone de un lote de valores enteros positivos que finaliza con un número negativo. El lote está dividido en sublotes por medio 
de valores cero. Desarrollar un programa que determine e informe:

    1. por cada sublote el promedio de valores
    2. el total de sublotes procesados
    3. el valor máximo del conjunto, indicando en que sublote se encontró y la posición relativa del mismo dentro del sublote 
    4. valor mínimo de cada sublote

    Nota: el lote puede estar vacío (primer valor negativo), o puede haber uno, varios o todos los sublotes vacíos (ceros consecutivos) 
*/

int main() {
    int valorPositivo;
    int cantValores = 0, sumaValores = 0;
    int cantSublotes = 0;
    int maximoConjunto = -1, posicion = 0, posicionMaximo = 0;
    int minimoSublote = 99999;

    cout << "Ingrese un valor(> a 0): " << endl;
    cin >> valorPositivo;

    while (valorPositivo >= 0) {
        while (valorPositivo != 0) {
            posicion++;
            cantValores++;
            sumaValores += valorPositivo;

            if(valorPositivo > maximoConjunto) {
                maximoConjunto = valorPositivo;
                posicionMaximo = posicion;
            }

            if(valorPositivo < minimoSublote) {
                minimoSublote = valorPositivo;
            }

            cout << "Ingrese un valor(!= de 0): " << endl;
            cin >> valorPositivo;
        }
        cantSublotes++;

        cout << "El promedio es: " << (sumaValores / cantValores) << endl;
        cout << "El minimo del sublote es: " << minimoSublote << endl;

        posicion = 0;
        cantValores = 0;
        sumaValores = 0;
        minimoSublote = 0;
        minimoSublote = 99999;

        cout << "Ingrese un valor(> a 0): " << endl;
        cin >> valorPositivo;
    }

    cout << "La cantidad de sublote son: " << cantSublotes << endl;
    cout << "El maximo del conjunto es: " << maximoConjunto << " y su posicion es: " << posicionMaximo << endl;

    return 0;
}
