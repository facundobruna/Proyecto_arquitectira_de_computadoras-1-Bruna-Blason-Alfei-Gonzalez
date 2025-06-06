#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int velocidad_ms =300;

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

int controlar_velocidad_o_salir() {

    if (kbhit()) {
        int ch = getch();
        if (ch == 224) {  // Flecha
            ch = getch();
            if (ch == 72 && velocidad_ms > 50)        // Flecha ↑
                velocidad_ms -= 50;
            else if (ch == 80 && velocidad_ms < 1000) // Flecha ↓
                velocidad_ms += 50;
            return 0;
        } else {
            return 1;

        }
    }
    return 0;
}


void choque(void) {
    printf("\n Secuencia Choque\n ");
    while (1) {
        if (controlar_velocidad_o_salir()) {
            disp_binary(0);
            return;
        }
        // Del exterior al centro
        for (int i = 0; i < 4; i++) {
            if (controlar_velocidad_o_salir()) {
                disp_binary(0);
                return;
            }
            unsigned char left = 1 << i;
            unsigned char right = 1 << (7 - i);
            disp_binary(left | right);
            delay_ms(velocidad_ms);
        }

        // Del centro al exterior
        for (int i = 2; i >= 0; i--) {  // Cambié el límite para detenerse en 7
            if (controlar_velocidad_o_salir()) {
                disp_binary(0);
                return;
            }
            unsigned char left = 1 << i;
            unsigned char right = 1 << (7 - i);
            disp_binary(left | right);
            delay_ms(velocidad_ms);
        }
    }
}


void auto_fantastico(void) {
    printf("\n Secuencia Auto fantastico\n ");
while (1) {
    if (controlar_velocidad_o_salir()) {
        disp_binary(0);
        return;
    }

    for (int i = 7; i >= 0; i--) {
        if (controlar_velocidad_o_salir()) {
            disp_binary(0);
            return;
        }
        unsigned char led = 1 << i;
        disp_binary(led);
        delay_ms(velocidad_ms);
    }

    for (int i = 1; i < 8; i++) {
        if (controlar_velocidad_o_salir()) {
            disp_binary(0);
            return;
        }
        unsigned char led = 1 << i;
        disp_binary(led);
        delay_ms(velocidad_ms);
    }
}
}

void barra_de_carga(void) {
    unsigned char barra = 0;
    printf("\n Secuencia Barra de carga\n ");
    while (1) {
        // Carga: de izquierda (bit 7) a derecha (bit 0)
        for (int i = 7; i >= 0; i--) {
            if (controlar_velocidad_o_salir()) {
                disp_binary(0);
                return;
            }
            barra |= (1 << i);
            disp_binary(barra);
            delay_ms(velocidad_ms);
        }

        // Descarga: de derecha (bit 0) a izquierda (bit 7)
        for (int i = 0; i <= 7; i++) {
            if (controlar_velocidad_o_salir()) {
                disp_binary(0);
                return;
            }
            barra &= ~(1 << i);
            disp_binary(barra);
            delay_ms(velocidad_ms);
        }
    }
}

void luces_alternadas(void) {
    printf("\n Secuencia Par impar\n ");
    unsigned char tabla[] = {
        0b10101010, // LEDs pares
        0b01010101  // LEDs impares
    };
    int i = 0;

    while (1) {
        if (controlar_velocidad_o_salir()) {
            disp_binary(0);
            return;
        }
        disp_binary(tabla[i]);
        delay_ms(velocidad_ms);
        i = 1 - i; // alternar entre 0 y 1
    }
}



