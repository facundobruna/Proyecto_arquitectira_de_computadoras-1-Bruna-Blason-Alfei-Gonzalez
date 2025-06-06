.text
.global _start
_start:
MOV r1,#0x80 @LED encendido(bit mas alto)
loop_left:
BL mostrar_led @llama subrutina que muestra a r1
BL delay 
LSR r1,r1,#1 @desplaza r1 a la derecha(siguiente bit)
CMP r1,#0x01
BHI loop_left @si aun no llegamos al bit 0 segir
MOV r1,#0x02 @segundo bit(evita repetir el anterior)
loop_right:
BL mostrar_led 
BL delay
LSL r1,r1,#1 @desplaza r1 a la izquierda(siguiente bit)
CMP r1,#0x80
BLO loop_right @si aun no llegamos al bit 7 seguir
B _start @vuelve al principio
@subrutina de delay
delay:
MOV r2,#0x40000 @valor grande para loop de retardo
del_loop:
SUBS r2,r2,#1
BNE del_loop
BX lr
@ ----------------------------------
@ Subrutina para mostrar el valor de r1 (simulada)
@ hacer STR r1, [r0]  
@ ----------------------------------
mostrar_led:
STR r1, [r0] @ Simula mostrar el valor de r1 en un registro de salida
BX lr 