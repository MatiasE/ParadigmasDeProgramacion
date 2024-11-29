#include <iostream>
using namespace std;

/*
    Dada la fracción P/Q, para P y Q naturales informar la mayor cantidad de simplificaciones. 
    Desarrolle y utilice una función que reciba dos números naturales y retorne el menor factor común. 
    Ej: 360/60 = 180/30 = 90/15 = 30/5 = 6/1
*/

int mayorFactorComun(int, int);

int main() {
    int p, q, mfc, mcd;

    cout << "Ingrese el numerador: ";
    cin >> p;
    cout << "Ingrese el denominador: ";
    cin >> q;

    mfc = mayorFactorComun(p, q);
    
    cout << p << "/" << q << " = " << p/mfc << "/" << q/mfc << endl;

    cout << "La fraccion se ha simplificado a su minima expresion" << endl;
    
    return 0;
}

int mayorFactorComun(int p, int q) {
    int mfc = 1;
    for (int i = 1; i <= p && i <= q; i++)
    {
        if (p % i == 0 && q % i == 0)
        {
            mfc = i;
        }
    }
    return mfc;
}