#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
void password(){
    char contrasenia_correcta[6]="12345";
    char contrasenia_ingresada[6];
    char caracter;


    int intentos=0;
    while (intentos<3) {
        int i=0;
        printf("Ingrese la contrasenia\n");
        while (i < 5) {
            caracter = getch();
            if (caracter >= '0' && caracter <= '9') {
                contrasenia_ingresada[i] = caracter;
                i++;
                printf("*");
            }
        }
        contrasenia_ingresada[5] = '\0';
        if (strcmp(contrasenia_ingresada,contrasenia_correcta)==0) {
            printf("bienvenido al sistema\n");
            return;
        }else {
            printf("password incorrecta, ");
            intentos++;
            printf("Le quedan %d intentos\n", 3 - intentos);
        }
    }
    printf("se ha quedado sin intentos\n");
    exit(1);

}
/*int main(){
    password();
}*/
#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

void disp_binary(unsigned char value) {
    for (int i = 7; i >= 0; i--) {
        if ((value >> i) & 1)
            printf("* ");
        else
            printf(". ");
    }
    printf("\n");
}


void delay_ms(int ms) {
    usleep(ms * 1000);  // usar Sleep(ms) en Windows si necesario
}
void choque(void){
    while (1) {
        // Del exterior al centro
        for (int i = 0; i < 4; i++) {
            unsigned char left = 1 << i;
            unsigned char right = 1 << (7 - i);
            disp_binary(left | right);
            delay_ms(300);
        }

        // Del centro al exterior
        for (int i = 2; i != 255; i--) {
            unsigned char left = 1 << i;
            unsigned char right = 1 << (7 - i);
            disp_binary(left | right);
            delay_ms(300);
        }

        printf("\n");// Espaciado entre ciclos

    }

}
int main() {
    int option;
    password();
    printf("\n---Opcion de luces: ---\n");
    printf("1. El auto fantastico\n");
    printf("2. El choque\n");
    printf("3. Secuencia personal 1\n");
    printf("4. Secuencia personal 2\n");
    printf("5. Salir del programa\n");

    while (option!=5) {
        printf("Seleccione una opcion: ");
        scanf("%d", &option);

        switch (option) {
            case 1:

                break;
            case 2:
                choque();
                break;
            case 3:

                break;
            case 4:

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