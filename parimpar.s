.text
.global _start
_start:
  MOV r1, #0b10101010  @ Inicializa r1 con un patrón de bits
  MOV r0, #0b01010101  @ Inicializa r0 con un valor base
  parimpar_loop:
  MOV r2,r1
  BL mostrar_led  @ Llama a la subrutina para mostrar el valor de r1
  BL delay
  MOV r2, r0
  BL mostrar_led
  BL delay
  B parimpar_loop

mostrar_led:
bx lr 
delay:
MOV r3, #0x20000
delay_loop:
SUBS r3, r3, #1
BNE delay_loop
BX lr