#include <iostream>
using namespace std;

/*
    Dada una serie de números enteros, informar:
    1. su factorial
    2. cuantos múltiplos de 3
    3. cuantos múltiplos de 5
    4. cuantos múltiplos de 3 y de 5
    5. Utilice las funciones de ejercicios anteriores.
*/ 

int factorial(int);
int multiplosDe3(int);
int multiplosDe5(int);
int multiplosDe3Y5(int);

int main() {
    int numero, fact = 0, multiplos3 = 0, multiplos5 = 0, multiplos3y5 = 0;
    cout << "Ingrese un numero: ";
    cin >> numero;

    while (numero > 0) {
        fact = factorial(numero);
        multiplos3 = multiplosDe3(numero);
        multiplos5 = multiplosDe5(numero);
        multiplos3y5 = multiplosDe3Y5(numero);

        cout << "El factorial de " << numero << " es " << fact << endl;
        cout << "El numero de multiplos de 3 es " << multiplos3 << endl;
        cout << "El numero de multiplos de 5 es " << multiplos5 << endl;
        cout << "El numero de multiplos de 3 y 5 es " << multiplos3y5 << endl;

        cout << "Ingrese un numero: ";
        cin >> numero;
    }

    return 0;
}

int factorial(int numero) {
    int fact = 1;
    for (int i = 1; i <= numero; i++)
    {
        fact *= i;
    }
    return fact;
}

int multiplosDe3(int numero) {
    int multiplos = 0;
    for (int i = 1; i <= numero; i++)
    {
        if (i % 3 == 0)
        {
            multiplos++;
        }
    }
    return multiplos;
}

int multiplosDe5(int numero) {
    int multiplos = 0;
    for (int i = 1; i <= numero; i++)
    {
        if (i % 5 == 0)
        {
            multiplos++;
        }
    }
    return multiplos;
}

int multiplosDe3Y5(int numero) {
    int multiplos = 0;
    for (int i = 1; i <= numero; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            multiplos++;
        }
    }
    return multiplos;
}
