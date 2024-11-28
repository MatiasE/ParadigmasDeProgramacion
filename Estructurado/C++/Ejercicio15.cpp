#include <iostream>
using namespace std;

/*
    Ingresar e informar valores, mientras que el valor ingresado no sea negativo.
    Informar la cantidad de valores ingresados.
*/

int main() {
    int valor;
    int cantValores = 0;

    cout << "Ingrese un valor: " << endl;
    cin >> valor;
    while (valor >= 0)
    {
        cantValores++;
        cout << valor << endl;
        cout << "Ingrese un valor: " << endl;
        cin >> valor;
    }
    cout << "Cantidad de Valores Ingresados: " << cantValores << endl;

    return 0;
}
