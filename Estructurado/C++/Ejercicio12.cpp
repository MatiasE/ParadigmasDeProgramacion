#include <iostream>
using namespace std;

// Generar los 100 primeros numeros naturales, acumular la suma e informarlos.

int main() {
    int suma = 0;
    cout << "Los primeros 100 numeros naturales son: " << endl;

    for (int i = 1; i <= 100; i++)
    {
        cout << i << endl;
        suma += i;
    }
    
    cout << "La suma de los primeros 100 numeros naturales son: " << suma << endl;

    return 0;
}
