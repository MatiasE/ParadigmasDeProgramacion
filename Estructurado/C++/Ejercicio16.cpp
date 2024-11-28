#include <iostream>
using namespace std;

/*
    Se ingresa un conjunto de valores reales, cada uno de los cuales representan el sueldo de un empleado, excepto el último valor que es cero 
e indica el fin del conjunto. Se pide desarrollar un programa que determine e informe:
    a. Cuántos empleados ganan menos $1.520.
    b. Cuántos ganan  $1.520 o más pero menos de $2.780.
    c. Cuántos ganan $2.780 o más pero menos de $5.999.
    d. Cuántos ganan $5.999 o más.
*/

int main() {
    int sueldoMenorAMilQuinientos;
    int sueldoMenorADosMilOchocientos;
    int sueldoMenorASeisMil;
    int sueldoMayorASeisMil;
    int sueldo = 0;

    cout << "Ingrese un sueldo: " << endl;
    cin >> sueldo;

    while(sueldo != 0) {
        if (sueldo < 1500)
        {
            sueldoMenorAMilQuinientos++;
        } else if (sueldo < 2800) 
        {
            sueldoMenorADosMilOchocientos++;
        } else if (sueldo < 6000) 
        {
            sueldoMenorASeisMil++;
        } else {
            sueldoMayorASeisMil++;
        }

        cout << "Ingrese un sueldo: " << endl;
        cin >> sueldo;
    }

    cout << "Empleados que ganan menos que 1500: " << sueldoMenorAMilQuinientos << endl;
    cout << "Empleados que ganan menos que 2800: " << sueldoMenorADosMilOchocientos << endl;
    cout << "Empleados que ganan menos que 6000: " << sueldoMenorASeisMil << endl;
    cout << "Empleados que ganan mas de 6000: " << sueldoMayorASeisMil << endl;

    return 0;
}