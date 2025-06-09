.text
.global _start
_start:
    MOV r1, #7 @ LED encendido (bit mas alto)
    MOV r0, #0
    carga_izquierda:
    cmp r1, #-1
   BLT descarga @ si r1<0 salta a la carga derecha
   MOV r2, #1
   LSL r2, r2, r1
   ORR r0, r0, r2 @ ORR r0 con 1 (bit mas alto)
    BL mostrar_led @ llama subrutina que muestra a r1
    BL delay 
    SUB r1, r1, #1

    B carga_izquierda @ vuelve al inicio del bucle
descarga:
MOV r1, #0 @ reinicia r1 a 0
carga_derecha:
CMP r1, #7 @ compara r1 con 7
BGT _start @ si r1>7 vuelve al inicio
MOV r2, #1
LSL r2, r2, r1 @ desplaza 1 a la izquierda r1 veces
BIC r0, r0, r2 @ limpia el bit correspondiente en r0
BL mostrar_led @ llama subrutina que muestra a r1
BL delay
ADD r1, r1, #1 @ incrementa r1
B carga_derecha @ vuelve al inicio del bucle
mostrar_led:
BX lr

delay:
MOV r5, #0x30000
ret_loop:
SUBS r5, r5, #1
BNE ret_loop
BX lr