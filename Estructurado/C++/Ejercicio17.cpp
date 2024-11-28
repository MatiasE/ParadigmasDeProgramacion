#include <iostream>
using namespace std;

/*
    Dado un valor M determinar y emitir un listado con los M primeros múltiplos de 3 que no lo sean de 5, 
    dentro del conjunto de los números naturales.
*/

int main() {
    int limite = 10000;
    int valor;
    cout << "Ingrese un valor: " << endl;
    cin >> valor;

    for (int i = 1; i < limite; i++)
    {
        if((i % 3 == 0) && (i % 5 != 0)) {
            cout << i << endl;
            valor--;
        }
        if(valor == 0) {
            break;
        }
    }

    cout << "Ingrese un valor: " << endl;
    cin >> valor;

    int i=1;
    while (valor != 0)
    {
        if((i % 3 == 0) && (i % 5 != 0)) {
            cout << i << endl;
            valor--;
        }
        i++;
    }
    

    return 0;
}
