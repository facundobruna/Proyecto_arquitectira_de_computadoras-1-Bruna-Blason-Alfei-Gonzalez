#pragma once
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
//#include "EasyPIO.h"
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <fcntl.h>
int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr); // Guardar atributos
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO); // Modo sin buffer y sin eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr); // Aplicar cambios
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); // Restaurar atributos
    return ch;
}

int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt); // Guardar atributos actuales
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Modo sin buffer
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0); // Guardar flags
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restaurar terminal
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

#endif



int velocidad_ms =300;
/*int leds[] = {14, 15, 18, 23, 24, 25, 8, 7};
void mostrar_leds(unsigned char value) {
    pinsMode(leds, 8, OUTPUT);
    digitalWrites(leds, 8, value);
}*/
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
   // delayMillis(ms);
    usleep(ms*1000);
}

int controlar_velocidad_o_salir() {
    if (kbhit()) {
        int ch = getch();
#ifdef _WIN32
        if (ch == 224) {
            ch = getch();
            if (ch == 72 && velocidad_ms > 50)        // ↑
                velocidad_ms -= 50;
            else if (ch == 80 && velocidad_ms < 1000) // ↓
                velocidad_ms += 50;
            return 0;
        } else {
            return 1;
        }
#else
        if (ch == 27) { // ESC
            if (kbhit() && getch() == '[') {
                ch = getch();
                if (ch == 'A' && velocidad_ms > 50)        // ↑
                    velocidad_ms -= 50;
                else if (ch == 'B' && velocidad_ms < 1000) // ↓
                    velocidad_ms += 50;
                return 0;
            }
        } else {
            return 1; // cualquier otra tecla sale
        }
#endif
    }
    return 0;
}


void choque(void) {
    printf("\n Secuencia Choque\n ");
  //  pinsMode(leds, 8, OUTPUT);
    while (1) {
        if (controlar_velocidad_o_salir()) {
            disp_binary(0);
           // mostrar_leds(0);
            return;
        }
        // Del exterior al centro
        for (int i = 0; i < 4; i++) {
            if (controlar_velocidad_o_salir()) {
                disp_binary(0);
              //  mostrar_leds(0);
                return;
            }
            unsigned char left = 1 << i;
            unsigned char right = 1 << (7 - i);
            disp_binary(left | right);
           // mostrar_leds(left|right);
            delay_ms(velocidad_ms);
        }

        // Del centro al exterior
        for (int i = 2; i >= 0; i--) {  // Cambié el límite para detenerse en 7
            if (controlar_velocidad_o_salir()) {
                disp_binary(0);
               // mostrar_leds(0);
                return;
            }
            unsigned char left = 1 << i;
            unsigned char right = 1 << (7 - i);
            disp_binary(left | right);
          //  mostrar_leds(left|right);
            delay_ms(velocidad_ms);
        }
    }
}


void auto_fantastico(void) {
    printf("\n Secuencia Auto fantastico\n ");
  //  pinsMode(leds, 8, OUTPUT);
while (1) {
    if (controlar_velocidad_o_salir()) {
        disp_binary(0);
      //  mostrar_leds(0);
        return;
    }

    for (int i = 7; i >= 0; i--) {
        if (controlar_velocidad_o_salir()) {
            disp_binary(0);
         //   mostrar_leds(0);
            return;
        }
        unsigned char led = 1 << i;
        disp_binary(led);
       // mostrar_leds(led);
        delay_ms(velocidad_ms);
    }

    for (int i = 1; i < 8; i++) {
        if (controlar_velocidad_o_salir()) {
            disp_binary(0);
           // mostrar_leds(0);
            return;
        }
        unsigned char led = 1 << i;
        disp_binary(led);
      //  mostrar_leds(led);
        delay_ms(velocidad_ms);
    }
}
}

void barra_de_carga(void) {
    unsigned char barra = 0;
    printf("\n Secuencia Barra de carga\n ");
   // pinsMode(leds, 8, OUTPUT);
    while (1) {
        // Carga: de izquierda (bit 7) a derecha (bit 0)
        for (int i = 7; i >= 0; i--) {
            if (controlar_velocidad_o_salir()) {
                disp_binary(0);
              //  mostrar_leds(0);
                return;
            }
            barra |= (1 << i);
            disp_binary(barra);
          //  mostrar_leds(barra);
            delay_ms(velocidad_ms);
        }

        // Descarga: de derecha (bit 0) a izquierda (bit 7)
        for (int i = 0; i <= 7; i++) {
            if (controlar_velocidad_o_salir()) {
                disp_binary(0);
              //  mostrar_leds(0);
                return;
            }
            barra &= ~(1 << i);
            disp_binary(barra);
         //   mostrar_leds(barra);
            delay_ms(velocidad_ms);
        }
    }
}

void luces_alternadas(void) {
    printf("\n Secuencia Par impar\n ");
  //  pinsMode(leds, 8, OUTPUT);
    unsigned char tabla[] = {
        0b10101010, // LEDs pares
        0b01010101  // LEDs impares
    };
    int i = 0;

    while (1) {
        if (controlar_velocidad_o_salir()) {
            disp_binary(0);
         //   mostrar_leds(0);
            return;
        }
        disp_binary(tabla[i]);
      //  mostrar_leds(tabla[i]);
        delay_ms(velocidad_ms);
        i = 1 - i; // alternar entre 0 y 1
    }
}



