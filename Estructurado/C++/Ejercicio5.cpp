#include <iostream>
using namespace std;

// Dado dos valores enteros y distintos, emitir una leyenda apropiada que informe cual es el mayor.
int main() {
    int valor1, valor2;
    
    cout << "Ingrese el primer valor: ";
    cin >> valor1;
    cout << "Ingrese el segundo valor: ";
    cin >> valor2;

    if (valor1 > valor2) {
        cout << "El primer valor es mayor." << endl;
    } else {
        cout << "El segundo valor es mayor." << endl;
    }

    return 0;
}