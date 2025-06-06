#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>


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
            printf("Bienvenido al sistema\n");
            return;
        }else {
            printf("Password incorrecta, ");
            intentos++;
            printf("Le quedan %d intentos\n", 3 - intentos);
        }
    }
    printf("Se ha quedado sin intentos\n");
    exit(1);

}
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
    usleep(ms * 1000);
}


void choque(void) {
    while (1) {
        if (kbhit()) return;
        // Del exterior al centro
        for (int i = 0; i < 4; i++) {
            unsigned char left = 1 << i;
            unsigned char right = 1 << (7 - i);
            disp_binary(left | right);
            delay_ms(300);
        }

        // Del centro al exterior
        for (int i = 2; i >= 0; i--) {  // Cambié el límite para detenerse en 7
            unsigned char left = 1 << i;
            unsigned char right = 1 << (7 - i);
            disp_binary(left | right);
            delay_ms(300);
        }

        printf("\n");
    }
}

void parImpar(void) {

    unsigned char led1,led2,led3,led4,led5,led6,led7,led8;

    while(1){
        for (int i=0;i<8;i++) {
           if (i==0) {

           }


            delay_ms(200);
        }




    }
}

void auto_fantastico(void) {

    for (int i = 7; i >= 0; i--) {
        unsigned char led = 1 << i;
        disp_binary(led);
        delay_ms(100);
    }

    for (int i = 1; i < 8; i++) {
        unsigned char led = 1 << i;
        disp_binary(led);
        delay_ms(100);
    }
}

void barra_de_carga(void) {
    unsigned char barra = 0;

    while (1) {
        // Carga: de izquierda (bit 7) a derecha (bit 0)
        for (int i = 7; i >= 0; i--) {
            if (kbhit()) return;
            barra |= (1 << i);
            disp_binary(barra);
            delay_ms(150);
        }

        // Descarga: de derecha (bit 0) a izquierda (bit 7)
        for (int i = 0; i <= 7; i++) {
            if (kbhit()) return;
            barra &= ~(1 << i);
            disp_binary(barra);
            delay_ms(150);
        }
    }
}




