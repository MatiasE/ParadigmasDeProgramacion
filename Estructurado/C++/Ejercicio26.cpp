#include <iostream>
using namespace std;

/*
    Dado un conjunto de valores enteros, calcular e informar 
    a) cuántos valores cero hubo, 
    b) promedio de valores positivos, 
    c) sumatoria de valores negativos.

    Resolver el ejercicio para los siguientes lotes de datos:
    1. 167 valores enteros
    2. N valores, donde el valor de N debe ser leído previamente
    3. El conjunto de valores termina con un valor igual al anterior
    4. Se dan N valores, pero el proceso deberá finalizar si se procesan todos los valores o si  la cantidad de ceros supera a cuatro 
    5. Se dan N valores, pero el proceso deberá finalizar si se cumple alguna de las condiciones de 4) o si el promedio de positivos resulta mayor que seis.
*/

int main() {
    int opcion;

    cout << "Ingrese una opcion: " << endl;
    cin >> opcion;
            
    
    switch (opcion) {
        case 1: {
            // 167 valores enteros
            int cantidadCeros = 0;
            int cantidadPositivos = 0; 
            int sumaPositivos = 0;
            int sumaNegativos = 0;
            int valor;

            // Lectura de los 167 valores
            for (int i = 0; i < 10; i++) {
                cout << "Ingrese el valor " << (i+1) << ": ";
                cin >> valor;
                
                // Procesamos los datos
                if (valor == 0) {
                    cantidadCeros++;
                }
                else if (valor > 0) {
                    cantidadPositivos++;
                    sumaPositivos += valor;
                }
                else {
                    sumaNegativos += valor;
                }
            }

            cout << "La cantidad de ceros es: " << cantidadCeros << endl;
            
            if (cantidadPositivos > 0) {
                cout << "El promedio de valores positivos es: " << (float) sumaPositivos / cantidadPositivos << endl;
            } else {
                cout << "No hubo valores positivos" << endl;
            }
            
            cout << "La sumatoria de valores negativos es: " << sumaNegativos << endl;
            break;
        }
        case 2: {
            // N valores, donde el valor de N debe ser leído previamente
            int N;
            cout << "Ingrese el valor de N: ";
            cin >> N;

            int cantidadCeros = 0;
            int cantidadPositivos = 0; 
            int sumaPositivos = 0;
            int sumaNegativos = 0;
            int valor;

            // Lectura de los 167 valores
            for (int i = 0; i < N; i++) {
                cout << "Ingrese el valor " << (i+1) << ": ";
                cin >> valor;
                
                // Procesamos los datos
                if (valor == 0) {
                    cantidadCeros++;
                }
                else if (valor > 0) {
                    cantidadPositivos++;
                    sumaPositivos += valor;
                }
                else {
                    sumaNegativos += valor;
                }
            }

            cout << "La cantidad de ceros es: " << cantidadCeros << endl;
            
            if (cantidadPositivos > 0) {
                cout << "El promedio de valores positivos es: " << (float) sumaPositivos / cantidadPositivos << endl;
            } else {
                cout << "No hubo valores positivos" << endl;
            }
            
            cout << "La sumatoria de valores negativos es: " << sumaNegativos << endl;
            break;
        }
        case 3: {
            // El conjunto de valores termina con un valor igual al anterior
            int cantidadCeros = 0;
            int cantidadPositivos = 0; 
            int sumaPositivos = 0;
            int sumaNegativos = 0;
            int valor;
            int valorAnterior = 0;

            while (valor != valorAnterior) {
                valorAnterior = valor;
                cout << "Ingrese el valor: ";
                cin >> valor;
                // Procesamos los datos
                if (valor == 0) {
                    cantidadCeros++;
                }
                else if (valor > 0) {
                    cantidadPositivos++;
                    sumaPositivos += valor;
                }
                else {
                    sumaNegativos += valor;
                }
            }

            cout << "La cantidad de ceros es: " << cantidadCeros << endl;
            
            if (cantidadPositivos > 0) {
                cout << "El promedio de valores positivos es: " << (float) sumaPositivos / cantidadPositivos << endl;
            } else {
                cout << "No hubo valores positivos" << endl;
            }
            
            cout << "La sumatoria de valores negativos es: " << sumaNegativos << endl;
            break;
        }
        case 4: {
            // Se dan N valores, pero el proceso deberá finalizar si se procesan todos los valores o si  la cantidad de ceros supera a cuatro 
            int N;
            cout << "Ingrese el valor de N: ";
            cin >> N;

            int cantidadCeros = 0;
            int cantidadPositivos = 0; 
            int sumaPositivos = 0;
            int sumaNegativos = 0;
            int valor;
            int i = 0;

            // Lectura de los N valores
            while ((i < N) && (cantidadCeros <= 4)) {
                cout << "Ingrese el valor " << (i+1) << ": ";
                cin >> valor;
                i++;

                // Procesamos los datos
                if (valor == 0) {
                    cantidadCeros++;
                }
                else if (valor > 0) {
                    cantidadPositivos++;
                    sumaPositivos += valor;
                }
                else {
                    sumaNegativos += valor;
                }
            }

            cout << "La cantidad de ceros es: " << cantidadCeros << endl;
            
            if (cantidadPositivos > 0) {
                cout << "El promedio de valores positivos es: " << (float) sumaPositivos / cantidadPositivos << endl;
            } else {
                cout << "No hubo valores positivos" << endl;
            }
            
            cout << "La sumatoria de negativos es: " << sumaNegativos << endl;
            break;
        }
        case 5:
            // Se dan N valores, pero el proceso deberá finalizar si se cumple alguna de las condiciones de 4) o si el promedio de positivos resulta mayor que seis.
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
    }

    return 0;
}

