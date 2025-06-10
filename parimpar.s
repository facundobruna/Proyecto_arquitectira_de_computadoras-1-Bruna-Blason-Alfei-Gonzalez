.text
.global asm_parimpar
asm_parimpar:
    MOV r1, #0b10101010
    MOV r2, #0b01010101
parimpar_loop:
    MOV r0, r1
    BL mostrar_led
    BL delay
    MOV r0, r2
    BL mostrar_led
    BL delay
    B parimpar_loop

mostrar_led:
    BX lr

delay:
    MOV r3, #0x20000
delay_loop:
    SUBS r3, r3, #1
    BNE delay_loop
    BX lr
