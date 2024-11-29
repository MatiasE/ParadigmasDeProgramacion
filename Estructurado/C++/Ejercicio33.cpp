#include <iostream>
using namespace std;

/*
    Desarrollar un procedimiento que imprima una fecha en formato DD/MM/AA. 
    El dato que recibe es un longint con una fecha en formato aaaammdd.
*/

void fecha(int);

int main() {
    int fec;
    cout << "Ingrese una fecha en formato aaaammdd: ";
    cin >> fec;
    fecha(fec);

    return 0;
}

void fecha(int fecha) {
    // Explicación:
    // fecha/10000 obtiene el día dividiendo el número entre 10000 (ej: 20231205/10000 = 2023)
    // (fecha/100)%100 obtiene el mes: primero divide entre 100 (20231205/100 = 202312) 
    // y luego obtiene el resto de dividir entre 100 (202312%100 = 12)
    // fecha%100 obtiene el día como el resto de dividir entre 100 (20231205%100 = 05)
    cout << "La fecha es: " << fecha/10000 << "/" << (fecha/100)%100 << "/" << fecha%100 << endl;
}
