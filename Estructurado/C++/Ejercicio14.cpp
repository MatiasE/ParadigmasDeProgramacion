#include <iostream>
#include <vector>
using namespace std;

/*
    En un torneo de futbol participan K equipos.
    El torneo se juega con el sistema de todos contra todos.
    Por cada partido disputado por un equipo se ingresa el 1. Nro. de Equpo y 2. codigo de resultado.
    Se arma un lote de datos con todos los resultados del torneo.
    Se pide:
    1) Por cada equipo, su numero y el puntaje total que obtuvo.(suma 3 si gana, 1 si empata y 0 si pierde)
    2) Nro de Equipo que totalizo la menor cantidad de puntos. (Hay solo uno)
*/

struct Equipo
{
    int nroEquipo;
    int puntajeTotal;
};

int main()
{
    int cantEquipos;
    char codResultado;
    int equipoQueMenosPuntoSaco;
    int limite = 1000;
    
    cout << "Ingrese la cantidad de equipos: " << endl;
    cin >> cantEquipos;

    int cantPartidos = cantEquipos - 1;
    vector<Equipo> Equipo(cantEquipos);

    for (int i = 1; i <= cantEquipos; i++)
    {   
        Equipo[i].nroEquipo = i;
        Equipo[i].puntajeTotal = 0;

        for (int j = 1; j <= cantPartidos; j++) {

            cout << "Ingrese el codigo de resultado: " << "Equipo: " << i << endl;
            cin >> codResultado;
            
            if (codResultado == 'G')
            {
                Equipo[i].puntajeTotal += 3;
            }

            if (codResultado == 'E')
            {
                Equipo[i].puntajeTotal += 1;
            }

            if (codResultado == 'P')
            {
                Equipo[i].puntajeTotal += 0;
            }
        }
    }

    // 1.
    for (int i = 1; i <= cantEquipos; i++)
    {   
        cout << "Equipo " << Equipo[i].nroEquipo << " - Puntaje total: " << Equipo[i].puntajeTotal << endl;
    }

    // 2.
    for (int i = 1; i <= cantEquipos; i++)
    {
        if (Equipo[i].puntajeTotal < limite)
        {
            equipoQueMenosPuntoSaco = Equipo[i].nroEquipo;           
            limite = Equipo[i].puntajeTotal;
        }
    }
    cout << equipoQueMenosPuntoSaco << endl;

    return 0;
}