#include <iostream>
using namespace std;

// Se ingresa una edad, mostrar por pantalla alguna de las siguientes leyendas:
// 'menor' si la edad es menor o igual a 12.
// 'cadete' si la edad esta comprendida entre 13 y 18.
// 'juvenil' si la edad es mayor que 18 y no supera los 26.
// 'mayor' en el caso que no cumpla ninguna de las condiciones anteriores.

int main() {
    int edad;

    cout << "Ingrese una edad: " << endl;
    cin >> edad;

    switch (edad)
    {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
        cout << "menor" << endl;
        break;
    case 13: case 14: case 15: case 16: case 17: case 18:
        cout << "cadete" << endl;
        break;
    case 19: case 20: case 21: case 22: case 23: case 24: case 25: case 26:
        cout << "juvenil" << endl;
        break;
    default:
        cout << "mayor" << endl;
        break;
    }

    return 0;
}
