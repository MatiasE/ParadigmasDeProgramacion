#include <iostream>
#include <vector>
using namespace std;

/*
    Ej. MI-24: Dada una serie de M pares {color, número} que corresponden a los tiros de una ruleta. 
    Se pide informar:
    1. cuántas veces salió el número cero y el número anterior a cada cero
    2. cuántas  veces seguidas llegó a repetirse el color negro
    3. cuántas  veces seguidas llegó a repetirse el mismo número y cuál fue
    4. el mayor número de veces seguidas que salieron alternados el rojo y el negro
    5. el mayor número de veces seguidas que se negó la segunda docenas
*/

struct Color {
    string color;
    int numero;
};

int main() {

    int m;
    cout << "Ingrese la cantidad de tiros: ";
    cin >> m;

    vector<Color> tiros(m);

    for (int i = 0; i < m; i++) {
        cout << "Ingrese el color del tiro " << i + 1 << ": ";
        cin >> tiros[i].color;
        cout << "Ingrese el numero del tiro " << i + 1 << ": ";
        cin >> tiros[i].numero;
    }

    // 1. cuántas veces salió el número cero y el número anterior a cada cero
    int vecesCero = 0;
    int numeroPrevioCero = 0;

    for (int i = 0; i < m; i++) {
        if (tiros[i].numero == 0) {
            vecesCero++;
            if (i > 0) {
                numeroPrevioCero = tiros[i - 1].numero;
            } else {
                cout << "No hay numero anterior al cero" << endl;
            }
            cout << "El numero anterior al cero es: " << numeroPrevioCero << endl;
        }
    }

    cout << "El numero de veces que salio el cero es: " << vecesCero << endl;

    // 2. cuántas veces seguidas llegó a repetirse el color negro
    int maxSecuenciaNegro = 0;    // guarda la secuencia más larga
    int secuenciaActual = 0;      // cuenta la secuencia actual

    for (int i = 0; i < m; i++) {
        if (tiros[i].color == "negro") {
            secuenciaActual++;
            // Actualizamos el máximo si la secuencia actual es mayor
            if (secuenciaActual > maxSecuenciaNegro) {
                maxSecuenciaNegro = secuenciaActual;
            }
        } else {
            secuenciaActual = 0;   // reiniciamos el contador si no es negro
        }
    }

    cout << "La maxima cantidad de veces seguidas que salio negro fue: " << maxSecuenciaNegro << endl;

    // 3. cuántas veces seguidas llegó a repetirse el mismo número y cuál fue
    int maxSecuenciaNumero = 0;    // guarda la secuencia más larga
    int secuenciaActualNumero = 0;      // cuenta la secuencia actual
    int numeroRepetido = 0;

    for (int i = 0; i < m; i++) {
        if (tiros[i].numero == tiros[i + 1].numero) {
            secuenciaActualNumero++;
            if (secuenciaActualNumero > maxSecuenciaNumero) {
                maxSecuenciaNumero = secuenciaActualNumero;
                numeroRepetido = tiros[i].numero;
            }
        } else {
            secuenciaActualNumero = 0;
        }
    }

    cout << "La maxima cantidad de veces seguidas que salio el mismo numero fue: " << maxSecuenciaNumero << endl;
    cout << "El numero que se repitio fue: " << numeroRepetido << endl;

    // 4. el mayor número de veces seguidas que salieron alternados el rojo y el negro
    int maxSecuenciaRojoNegro = 0;
    int secuenciaActualRojoNegro = 0;

    for (int i = 0; i < m; i++) {
        if ((tiros[i].color == "rojo" && tiros[i + 1].color == "negro") || (tiros[i].color == "negro" && tiros[i + 1].color == "rojo")) {
            secuenciaActualRojoNegro++;
            if (secuenciaActualRojoNegro > maxSecuenciaRojoNegro) {
                maxSecuenciaRojoNegro = secuenciaActualRojoNegro;
            }
        } else {
            secuenciaActualRojoNegro = 0;
        }
    }

    cout << "La maxima cantidad de veces seguidas que salio rojo y negro fue: " << maxSecuenciaRojoNegro << endl;

    // 5. el mayor número de veces seguidas que se negó la segunda docena
    int maxSecuenciaNegadaSegundaDocena = 0;
    int secuenciaActualNegadaSegundaDocena = 0;   

    for (int i = 0; i < m; i++) {
        if (!(tiros[i].numero >= 25 && tiros[i].numero <= 36)) {
            secuenciaActualNegadaSegundaDocena++;
            if (secuenciaActualNegadaSegundaDocena > maxSecuenciaNegadaSegundaDocena) {
                maxSecuenciaNegadaSegundaDocena = secuenciaActualNegadaSegundaDocena;
            }
        } else {
            secuenciaActualNegadaSegundaDocena = 0;
        }
    }

    cout << "La maxima cantidad de veces seguidas que se nego la segunda docena fue: " << maxSecuenciaNegadaSegundaDocena << endl;

    return 0;
}

