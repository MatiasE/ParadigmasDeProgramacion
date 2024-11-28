/*
    Quisiera hacer un compilador de C.
*/

#include <stdio.h>
#include <string.h>

int main() {
    printf("Hola, mundo!\n");
    printf("Ingrese su nombre: ");
    char nombre[100];
    char nombre2[100];
    // scanf("%s", nombre);
    fgets(nombre2, 100, stdin);
    nombre2[strcspn(nombre2, "\n")] = '\0';
    // printf("Hola, %s!\n", nombre);
    printf("Hola, %s!\n", nombre2);
    
    return 0;
}
