#include <iostream>
using namespace std;

/*
    Dado un número entero positivo entre 1 y 3999 informar su correspondiente número Romano 
*/ 

int main() {
    // Pedimos al usuario que ingrese un número entre 1 y 3999
    int numero;
    cout << "Ingrese un numero entero positivo entre 1 y 3999: ";
    cin >> numero;

    // Validamos que el número esté en el rango permitido
    if (numero < 1 || numero > 3999) {
        cout << "El numero ingresado no es valido." << endl;
        return 0;
    }

    // Definimos arrays con los símbolos romanos para cada posición decimal
    // El índice 0 está vacío porque representa el 0, que no existe en números romanos
    string unidades[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; // Del 0 al 9
    string decenas[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}; // Del 0 al 90
    string centenas[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; // Del 0 al 900
    string miles[] = {"", "M", "MM", "MMM"}; // Del 0 al 3000

    // Separamos el número en sus componentes individuales
    int m = numero / 1000;         // Obtenemos los miles dividiendo por 1000
    cout << "Miles: " << m << endl;
    int c = (numero / 100) % 10;   // Obtenemos las centenas dividiendo por 100 y tomando el resto de dividir por 10
    cout << "Centenas: " << c << endl;
    int d = (numero / 10) % 10;    // Obtenemos las decenas dividiendo por 10 y tomando el resto de dividir por 10
    cout << "Decenas: " << d << endl;
    int u = numero % 10;           // Obtenemos las unidades tomando el resto de dividir por 10
    cout << "Unidades: " << u << endl;

    // Construimos el número romano concatenando los símbolos correspondientes
    // Cada componente se usa como índice en su respectivo array
    cout << "El numero romano correspondiente es: " << miles[m] << centenas[c] << decenas[d] << unidades[u] << endl;

    return 0;
}
