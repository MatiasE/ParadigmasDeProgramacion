#include <iostream>
using namespace std;

/*
    Dados 10 valores informar el mayor.
*/

int main() {
    int valor, maximo, minimo = -50000;

    for (int i = 0; i < 10; i++)
    {
        cout << "Ingrese un valor (no menor a 5000): " << endl;
        cin >> valor;

        if(valor > minimo) {
            maximo = valor;
        }
    }

    cout << "El maximo es: " << maximo << endl;

    return 0;
}
