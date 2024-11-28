/*
    Dado un número real que representa el importe de una compra informar las posibles formas de pago, según la siguiente tabla
    1 cuota de $: ....
    2 cuotas de $: .... total $ ... (5% de recargo)
    6 cuotas de $: .... total $ ... (40% de recargo)
*/

#include <iostream>
using namespace std;

int main() {
    float importe;
    cout << "Ingrese el importe de la compra: ";
    cin >> importe;

    cout << "1 cuota de $: " << importe << endl;
    cout << "2 cuotas de $: " <<  (importe * 1.05) / 2 << " total $: " << importe * 1.05 << endl;
    cout << "6 cuotas de $: " << (importe * 1.4) / 6 << " total $: " << importe * 1.4 << endl;

    return 0;
}

