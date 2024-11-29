#include <iostream>
using namespace std;

/*
    Desarrollar una función tal que dado un  número entero positivo calcule y retorne su factorial.
*/

int factorial(int);

int main() {
    int numero, fact;
    cout << "Ingrese un numero: " << endl;
    cin >> numero;

    fact = factorial(numero);
    cout << "El factorial es: " << fact << endl;

    return 0;
}

int factorial(int numero) {
    int fact = 1;
    for (int i = 1; i <= numero; i++)
    {
        fact *= i;
    }
    return fact;
}