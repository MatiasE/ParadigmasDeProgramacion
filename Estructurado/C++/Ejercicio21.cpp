#include <iostream>
using namespace std;

/*
    Dado un conjunto de valores, que finaliza con un valor nulo, determinar e imprimir (si hubo valores):
    a) El valor máximo negativo 
    b) El valor mínimo positivo
    c) El valor mínimo dentro del rango -17.3 y 26.9
    d) El promedio de todos los valores.
*/

int main() {
    float valor; 
    float valorMaximoNegativo = -50000, valorMinimoPositivo = 50000, valorMinimoEnUnRango = 30;    
    float cantValores = 0, sumaDeTodos = 0, promedioDeTodos = 0;

    cout << "Ingrese un valor: " << endl;
    cin >> valor;

    while (valor != 0)
    {
        if (valor < 0) {
            if (valor > valorMaximoNegativo)
            {
                valorMaximoNegativo = valor;
            }
        } else {
            if (valor < valorMinimoPositivo) {
                valorMinimoPositivo = valor;
            }
        }

        if (valor > 17.3 && valor < 26.9)
        {
            if (valor < valorMinimoEnUnRango) {
                valorMinimoEnUnRango = valor;
            }
        }
        
        cantValores++;
        sumaDeTodos += valor;

        cout << "Ingrese un valor: " << endl;
        cin >> valor;
    }
    
    promedioDeTodos = sumaDeTodos / cantValores;

    cout << "El valor maximo negativo es: " << valorMaximoNegativo << endl;
    cout << "El valor minimo positivo es: " << valorMinimoPositivo << endl;
    cout << "El valor minimo dentro de un rango es: " << valorMinimoEnUnRango << endl;
    cout << "El promedio de todos es: " << promedioDeTodos << endl;

    return 0;
}
