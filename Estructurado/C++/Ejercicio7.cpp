#include <iostream>
using namespace std;

// Dadas 3 Temperaturas, indicar cual es la mayor.

int main() {
    int temp1, temp2, temp3;

    cout << "Ingrese la Primera temperatura: ";
    cin >> temp1;

    cout << "Ingrese la Segunda temperatura: ";
    cin >> temp2;

    cout << "Ingrese la Tercera temperatura: ";
    cin >> temp3;

    if ((temp1 > temp2) && (temp1 > temp3))
    {
        cout << temp1 << " es la mayor." << endl;
    } else if (temp2 > temp3)
    {
        cout << temp2 << " es la mayor." << endl;
    } else {
        cout << temp3 << " es la mayor." << endl;
    }
    
    
    

    return 0;
}