#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Integrante {
    string nombre;
    string apellido;
    int edad;
    char sexo;
    char nivelEstudio;
    char indicador;
};

struct Familia {
    string domicilio;
    char tipoVivienda;
    int cantidadIntegrantes;
    Integrante integrantes[100];
};

int main() {
    int cantidadFamilias;
    cout << "Ingrese la cantidad de familias a encuestar: ";
    cin >> cantidadFamilias;
    cin.ignore();

    vector<Familia> familias(cantidadFamilias);
    
    // Variables para estadísticas
    int totalPersonas = 0;
    int analfabetos = 0;
    int maxIntegrantesDepartamento = 0;
    string domicilioMaxDepartamento;
    double edadTotalCiudad = 0;
    int contadorFemenino = 0;
    int contadorMasculino = 0;
    int nivelEstudioIncompletos[5] = {0}; // N, P, S, T, U

    // Ingreso de datos
    for (int i = 0; i < cantidadFamilias; i++) {
        Familia& familia = familias[i];
        
        cout << "\n--- Familia " << i + 1 << " ---\n";
        cout << "Ingrese el domicilio: ";
        getline(cin, familia.domicilio);

        cout << "Ingrese el tipo de vivienda (C: casa, D: departamento): ";
        cin >> familia.tipoVivienda;
        cin.ignore();

        cout << "Ingrese la cantidad de integrantes: ";
        cin >> familia.cantidadIntegrantes;
        cin.ignore();

        double edadTotalFamilia = 0;

        for (int j = 0; j < familia.cantidadIntegrantes; j++) {
            cout << "\nIntegrante " << j + 1 << ":\n";
            cout << "Nombre: ";
            getline(cin, familia.integrantes[j].nombre);

            cout << "Apellido: ";
            getline(cin, familia.integrantes[j].apellido);

            cout << "Edad: ";
            cin >> familia.integrantes[j].edad;

            cout << "Sexo (F/M): ";
            cin >> familia.integrantes[j].sexo;

            cout << "Nivel de estudios (N/P/S/T/U): ";
            cin >> familia.integrantes[j].nivelEstudio;

            cout << "Indicador (I/C): ";
            cin >> familia.integrantes[j].indicador;
            cin.ignore();

            // Acumulamos estadísticas
            edadTotalFamilia += familia.integrantes[j].edad;
            edadTotalCiudad += familia.integrantes[j].edad;

            if (familia.integrantes[j].sexo == 'F') contadorFemenino++;
            else if (familia.integrantes[j].sexo == 'M') contadorMasculino++;

            // Contamos analfabetos (mayores de 10 sin estudios)
            if (familia.integrantes[j].edad > 10 && familia.integrantes[j].nivelEstudio == 'N') {
                analfabetos++;
            }

            // Contamos estudios incompletos
            if (familia.integrantes[j].indicador == 'I') {
                switch(familia.integrantes[j].nivelEstudio) {
                    case 'N': nivelEstudioIncompletos[0]++; break;
                    case 'P': nivelEstudioIncompletos[1]++; break;
                    case 'S': nivelEstudioIncompletos[2]++; break;
                    case 'T': nivelEstudioIncompletos[3]++; break;
                    case 'U': nivelEstudioIncompletos[4]++; break;
                }
            }
        }

        totalPersonas += familia.cantidadIntegrantes;

        // Verificamos si es el departamento con más integrantes
        if (familia.tipoVivienda == 'D' && familia.cantidadIntegrantes > maxIntegrantesDepartamento) {
            maxIntegrantesDepartamento = familia.cantidadIntegrantes;
            domicilioMaxDepartamento = familia.domicilio;
        }

        // Mostramos edad promedio de esta familia
        cout << "\nEdad promedio de la familia: " << edadTotalFamilia / familia.cantidadIntegrantes << endl;
    }

    // Mostramos resultados
    cout << "\n=== RESULTADOS DE LA ENCUESTA ===\n";

    // 1. Personas con primario completo
    cout << "\n1. Personas con primario completo:\n";
    for (const auto& familia : familias) {
        for (int j = 0; j < familia.cantidadIntegrantes; j++) {
            if (familia.integrantes[j].nivelEstudio == 'P' && familia.integrantes[j].indicador == 'C') {
                cout << familia.integrantes[j].nombre << " " 
                     << familia.integrantes[j].apellido << endl;
            }
        }
    }

    // 2. Porcentaje de analfabetismo
    double porcentajeAnalfabetismo = (analfabetos * 100.0) / totalPersonas;
    cout << "\n2. Porcentaje de analfabetismo: " << porcentajeAnalfabetismo << "%\n";

    // 3. Familia más numerosa en departamento
    cout << "\n3. Departamento con más integrantes: " << domicilioMaxDepartamento 
         << " (" << maxIntegrantesDepartamento << " integrantes)\n";

    // 4. Edad promedio de la ciudad
    cout << "\n4. Edad promedio de la ciudad: " << edadTotalCiudad / totalPersonas << endl;

    // 5. Cantidad por nivel de estudios incompletos
    cout << "\n5. Estudios incompletos:\n";
    cout << "Sin estudios: " << nivelEstudioIncompletos[0] << endl;
    cout << "Primario: " << nivelEstudioIncompletos[1] << endl;
    cout << "Secundario: " << nivelEstudioIncompletos[2] << endl;
    cout << "Terciario: " << nivelEstudioIncompletos[3] << endl;
    cout << "Universitario: " << nivelEstudioIncompletos[4] << endl;

    // 6. Porcentaje por sexo
    cout << "\n6. Porcentaje por sexo:\n";
    cout << "Femenino: " << (contadorFemenino * 100.0) / totalPersonas << "%\n";
    cout << "Masculino: " << (contadorMasculino * 100.0) / totalPersonas << "%\n";    

    return 0;
}
