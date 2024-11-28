#include <iostream>
using namespace std;

// Dados N valores informar el mayor, el menor y en que posición del conjunto fueron ingresados.

int main() {
    int valor, cantValores;
    int mayor = -50000, menor = 50000, posicionMinimo, posicionMaximo;

    cout << "Ingrese una cantidad de valores: " << endl;
    cin >> cantValores;

    for (int i = 1; i <= cantValores; i++)
    {
        cout << "Ingrese el valor: " << endl;
        cin >> valor;

        if (valor > mayor)
        {
            mayor = valor;
            posicionMaximo = i; 
        }
        if (valor < menor) 
        {
            menor = valor;
            posicionMinimo = i;
        }
    }
    
    cout << "El menor es: " << menor << " y su posicion es: " << posicionMinimo << endl;
    cout << "El mayor es: " << mayor << " y su posicion es: " << posicionMaximo << endl;

    return 0;
}
