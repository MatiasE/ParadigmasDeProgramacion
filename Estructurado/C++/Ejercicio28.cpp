#include <iostream>
using namespace std;

/*
    Desarrollar una función que calcule el máximo común divisor de dos números enteros A, B con el siguiente algoritmo:

    1. Dividir A por B, y calcular el resto (0 < R < B)
    2. Si R = 0, el MCD es B, si no seguir en 3)
    3. Reemplazar A por B, B por R, y volver al paso 1)
*/ 

int maximo_comun_divisor(int, int);
int calcular_resto(int, int);

int main() {
    int num1, num2, mcd;

    cout << "Ingrese el numero 1: " << endl;
    cin >> num1;

    cout << "Ingrese el numero 2: " << endl;
    cin >> num2;

    mcd = maximo_comun_divisor(num1, num2);
    cout << "El maximo comun divisor es: " << mcd << endl;

    return 0;
}

int maximo_comun_divisor(int num1, int num2) {
    int resto;
    resto = calcular_resto(num1, num2);
    if (resto == 0)
    {
        return num2;
    } else {
        return maximo_comun_divisor(num2, resto);
    }    
}

int calcular_resto(int num1, int num2) {
    return num1 % num2;
}