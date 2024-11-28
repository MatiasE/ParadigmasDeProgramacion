#include <iostream>
using namespace std;

// Dado un mes y el año correspondiente informar cuantos dias tiene el mes.

int main() {
    int dia, mes, anio;
    cout << "Ingrese mes: ";
    cin >> mes;

    cout << "Ingrese anio: ";
    cin >> anio;

    switch (mes)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        dia = 31;
        break;
    case 2:
        if (anio % 4 == 0) {
            dia = 29;
        } else
        {
            dia = 28;
        }
        break;
    case 4: case 6: case 9: case 11:
        dia = 30;
        break;
    default:
        break;
    }

    cout << dia << endl;

    return 0;
}
