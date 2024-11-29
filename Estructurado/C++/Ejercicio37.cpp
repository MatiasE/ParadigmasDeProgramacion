#include <iostream>
#include <string>
using namespace std;

/*
    Dados los siguientes dibujos que corresponden a distintos tipos de registros realice su declaración en 
    C++ utilizando la sección Struct, y especifique la nomenclatura para acceder al registro y cada uno 
    de sus campos.

    Nombre (20 caracteres)
    FechaNacimiento
        Dia (1..31)
        Mes (1..12)
        Anio (4 dígitos)

    Legajo (8 dígitos)
    ApellidoNombre
        Apellido (20 caracteres)
        Nombre (20 caracteres)
    Calificaciones
        Nota1
        Nota2
        Nota3
*/

struct FechaNacimiento {
    int dia, mes, anio;
};

struct Persona {
    string nombre;
    FechaNacimiento fechaNacimiento;
};

struct Calificaciones {
    float nota1;
    float nota2;
    float nota3;
};

struct ApellidoNombre {
    string apellido;
    string nombre;
};

struct Alumno {
    int legajo;
    ApellidoNombre apellidoNombre;
    Calificaciones calificaciones;
};



/*
    Realice la codificación y el seguimiento para el desarrollo del siguiente enunciado.

    Enunciado: Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), 
    que finaliza con un Nombre = ‘FIN’, informar el nombre de la persona de mayor edad.
*/

struct ListaPersonas {
    Persona persona;
    ListaPersonas *siguiente;
};


int main() {
    // Inicializamos los punteros de la lista enlazada como NULL
    // Sí, esto crea dos punteros nulos que se usarán para manejar una lista enlazada:
    // - lista: apuntará al primer elemento de la lista (inicialmente vacía)
    // - actual: se usará para mantener la referencia al último elemento agregado
    ListaPersonas *lista = NULL;   // Puntero al inicio de la lista (NULL = lista vacía)
    ListaPersonas *actual = NULL;  // Puntero al elemento actual (NULL = no hay elementos)

    // Variables para almacenar los datos ingresados por el usuario
    string nombre;
    int fechaNacimiento;

    // Solicitamos el primer nombre
    cout << "Ingrese el nombre: ";
    getline(cin, nombre);

    // Bucle que se ejecuta mientras no se ingrese "FIN"
    while (nombre != "FIN") {
        // Creamos un nuevo nodo para la lista
        ListaPersonas *nuevaPersona = new ListaPersonas();
        // Asignamos el nombre ingresado al nuevo nodo
        nuevaPersona->persona.nombre = nombre;
        // El siguiente nodo será NULL por ahora
        nuevaPersona->siguiente = NULL;

        // Solicitamos la fecha de nacimiento en formato AAAAMMDD
        cout << "Ingrese la fecha de nacimiento (AAAAMMDD): ";
        cin >> fechaNacimiento;
        cin.ignore();

        // Separamos la fecha en año, mes y día usando división y módulo
        nuevaPersona->persona.fechaNacimiento.anio = fechaNacimiento / 10000;
        nuevaPersona->persona.fechaNacimiento.mes = (fechaNacimiento / 100) % 100;
        nuevaPersona->persona.fechaNacimiento.dia = fechaNacimiento % 100;

        // Si la lista está vacía, el nuevo nodo será el primero
        if (lista == NULL) {
            lista = nuevaPersona;
            actual = nuevaPersona;
        } else {
            // Si no, agregamos el nuevo nodo al final de la lista
            actual->siguiente = nuevaPersona;
            actual = nuevaPersona;
        }

        // Solicitamos el siguiente nombre
        cout << "Ingrese el nombre: ";
        getline(cin, nombre);
    }

    // Variables para almacenar los datos de la persona de mayor edad
    int mayorEdad = 9999;
    int mayorEdadMes = 12;
    int mayorEdadDia = 31;
    string nombreMayorEdad = "";

    // Recorremos la lista para encontrar la persona de mayor edad
    actual = lista;
    while (actual != NULL) {
        // Comparamos las fechas considerando año, mes y día
        if (actual->persona.fechaNacimiento.anio < mayorEdad || 
           (actual->persona.fechaNacimiento.anio == mayorEdad && 
            actual->persona.fechaNacimiento.mes < mayorEdadMes) ||
           (actual->persona.fechaNacimiento.anio == mayorEdad && 
            actual->persona.fechaNacimiento.mes == mayorEdadMes &&
            actual->persona.fechaNacimiento.dia < mayorEdadDia)) {
            
            mayorEdad = actual->persona.fechaNacimiento.anio;
            mayorEdadMes = actual->persona.fechaNacimiento.mes;
            mayorEdadDia = actual->persona.fechaNacimiento.dia;
            nombreMayorEdad = actual->persona.nombre;
        }
        
        // Movemos al siguiente nodo
        actual = actual->siguiente;
    }

    // Liberamos la memoria utilizada por la lista
    actual = lista;
    while (actual != NULL) {
        ListaPersonas *temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    // Mostramos los resultados
    cout << "El nombre de la persona de mayor edad es: " << nombreMayorEdad << endl;
    cout << "La fecha de nacimiento es: " << mayorEdadDia << "/" << mayorEdadMes << "/" << mayorEdad << endl;
        
    return 0;   
}