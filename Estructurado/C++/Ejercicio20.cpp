#include <iostream>
using namespace std;

// Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que finaliza con un Nombre = ‘FIN’, 
// informar el nombre de la persona con mayor edad y el de la más joven.

int main() {
    string nombre, nombreMinimo = "", nombreMaximo = "";
    int fecNacimiento, fecActual = 20241128, maximo = 99999999, minimo = 00000000;

    cout << "Ingrese el Nombre: " << endl;
    cin >> nombre;

    cout << "Ingrese fecha de nacimiento (AAAAMMDD): " << endl;
    cin >> fecNacimiento;

    while (nombre != "FIN")
    {
        if(fecNacimiento < maximo) {
            maximo = fecNacimiento;
            nombreMaximo = nombre;
        }

        if(fecNacimiento > minimo) {
            minimo = fecNacimiento;
            nombreMinimo = nombre;
        }

        cout << "Ingrese el Nombre: " << endl;
        cin >> nombre;

        cout << "Ingrese fecha de nacimiento (AAAAMMDD): " << endl;
        cin >> fecNacimiento;
    }
    
    cout << "El mas viejo es: " << nombreMaximo << " y el mas joven es: " << nombreMinimo << endl;

    return 0;
}
