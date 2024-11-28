#include <iostream>
using namespace std;

int main() {
    int n, m; 
    int producto1, producto2 = 0;

    cout << "Ingrese n: " << endl;
    cin >> n;

    cout << "Ingrese m: " << endl;
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        producto1 += m;
    }

    for (int i = 0; i < m; i++)
    {
        producto2 += n;
    }

    cout << producto1 << " y " << producto2 << endl;

    return 0;
}