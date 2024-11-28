#include <iostream>
using namespace std;

// Dado un triangulo representado por sus lados L1, L2, L3, determinar e imprimir una leyenda segun sea: equilatero, isosceles o escaleno.

int main() {
    int l1, l2, l3;
    
    cout << "Ingrese l1: ";
    cin >> l1;

    cout << "Ingrese l2: ";
    cin >> l2;

    cout << "Ingrese l3: ";
    cin >> l3;

    if (l1 == l2 && l2 == l3)
    {
        cout << "Es un triangulo equilatero " << endl;
    } 
    else if ((l1 == l2 && l2 != l3) || (l1 != l2 && l2 == l3))
    {
        cout << "Es un triangulo isosceles" << endl;    
    } else {
        cout << "Es un triangulo escaleno" << endl; 
    }

    return 0;
}
