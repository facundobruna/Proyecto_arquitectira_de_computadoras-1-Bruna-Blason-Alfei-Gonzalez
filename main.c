#include <stdio.h>
//#include "funciones2.h"
#include "Funciones.h"

int main() {
    int option;
   // pioInit();
    password();
    while (option!=5) {
          printf("\n---Opcion de luces: ---\n");
    printf("1. El auto fantastico\n");
    printf("2. El choque\n");
    printf("3. Secuencia personal 1\n");
    printf("4. Secuencia personal 2\n");
    printf("5. Salir del programa\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &option);
        while (getchar() != '\n'); 
        switch (option) {
            case 1:
                auto_fantastico();
                break;
            case 2:
                choque();
                break;
            case 3:
                 barra_de_carga();
                break;
            case 4:
                luces_alternadas();
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida\n");

                break;
        }
    }
}