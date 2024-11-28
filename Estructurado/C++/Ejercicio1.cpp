/*
    A partir de dos valores enteros A y B, informar la suma, diferencia y producto de ambos.
*/

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Ingrese el valor de A: ";
    cin >> a;
    cout << "Ingrese el valor de B: ";
    cin >> b;
    cout << "La suma de A y B es: " << a + b << endl;
    cout << "La diferencia de A y B es: " << a - b << endl;
    cout << "El producto de A y B es: " << a * b << endl;   

    return 0;
}
