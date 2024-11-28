#include <iostream>
using namespace std;

// Dados dos numeros, mostrar un menu con opciones de sumar, restar o multiplicar dichos numeros. Solicite elegir una opcion:
// (Suma, resta, multiplicacion, division)

int main() {
    int num1, num2, operacion;

    cout << "Ingrese un numero: ";
    cin >> num1;

    cout << "Ingrese otro numero: ";
    cin >> num2;

    cout << "Ingrese un numero para operacion (1-2-3-4) para (suma, resta, multiplicacion, division) respectivamente: ";
    cin >> operacion;

    switch (operacion)
    {
    case 1:
        cout << num1+num2 << endl;
        break;
    case 2:
        cout << num1-num2 << endl;
        break;
    case 3:
        cout << num1*num2 << endl;
        break;
    case 4:
        cout << num1/num2 << endl;
        break;
    default:
        cout << "Operacion no conocida." << endl;
        break;
    }

    return 0;
}
