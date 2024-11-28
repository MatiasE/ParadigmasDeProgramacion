#include <iostream>
using namespace std;

/*
    1. Escribir un programa que pida al usuario un número entero y muestre por pantalla si es par 
    o impar.
*/ 

int main() {
    int numero;
    cout << "Ingrese un numero entero: ";
    cin >> numero;
    if (numero % 2 == 0) {
        cout << "El numero es par." << endl;
    } else {
        cout << "El numero es impar." << endl;
    }
    return 0;
}