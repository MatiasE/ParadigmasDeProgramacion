#include <iostream>
using namespace std;

// A partir de un valor entero ingresado por teclado, se pide informar:
// 1. La quinta parte de dicho valor.
// 2. El resto de la division por 5.
// 3. La septima parte del resultado del punto 1.

int main() {
    int valor;
    cout << "Ingrese un valor entero: ";
    cin >> valor;

    cout << "La quinta parte de dicho valor es: " << valor / 5 << endl;
    cout << "El resto de la division por 5 es: " << valor % 5 << endl;
    cout << "La septima parte del resultado del punto 1 es: " << (valor / 5) / 7 << endl;
    
    return 0;
}