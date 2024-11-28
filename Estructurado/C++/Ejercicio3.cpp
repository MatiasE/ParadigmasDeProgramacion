/*
    Dada una terna de numeros naturales que representan al dia, mes y al año de una determinada fecha informarla como un 
    solo numero natural de 8 digitos (AAAAMMDD)
*/

#include <iostream>
using namespace std;

int main() {
    int dia, mes, anio;
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;

    cout << anio * 10000 + mes * 100 + dia << endl;
    return 0;
}