#include <iostream>
using namespace std;

// 6. Escribir un programa que permita ingresar dos fechas en formato AAAAMMDD 
// y determine cuál es la más reciente.

int main() {
    int fecha1, fecha2;
    cout << "Ingrese la fecha 1: (AAAAMMDD): ";
    cin >> fecha1;
    cout << "Ingrese la fecha 2: (AAAAMMDD): ";
    cin >> fecha2;

    if (fecha1 > fecha2) {
        cout << "La fecha 1 es mas reciente que la fecha 2";
    } else if (fecha1 < fecha2) {
        cout << "La fecha 2 es mas reciente que la fecha 1";
    } else {
        cout << "La fecha 1 es igual a la fecha 2";
    }

    return 0;
}