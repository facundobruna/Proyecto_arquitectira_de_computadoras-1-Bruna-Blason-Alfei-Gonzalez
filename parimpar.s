.text
.global asm_parimpar
.extern mostrar_led
.extern delay_ms
.extern velocidad_ms

asm_parimpar:
    MOV r1, #0b10101010
    MOV r2, #0b01010101

parimpar_loop:
    MOV r0, r1
    BL mostrar_led

    LDR r0, =velocidad_ms
    LDR r0, [r0]
    BL delay_ms

    MOV r0, r2
    BL mostrar_led

    LDR r0, =velocidad_ms
    LDR r0, [r0]
    BL delay_ms

    B parimpar_loop


@mostrar_led:
@    BX lr
@
@delay:
@    MOV r3, #0x20000
@delay_loop:
 @   SUBS r3, r3, #1
  @  BNE delay_loop
   @ BX lr
