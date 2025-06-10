.text
.global asm_barra_de_carga
asm_barra_de_carga:
    MOV r1, #7
    MOV r4, #0          @ usamos r4 para acumular el estado de los LEDs

carga_izquierda:
    CMP r1, #-1
    BLT descarga
    MOV r2, #1
    LSL r2, r2, r1
    ORR r4, r4, r2
    MOV r0, r4          @ pasar valor al primer argumento (r0)
    BL mostrar_led
    BL delay
    SUB r1, r1, #1
    B carga_izquierda

descarga:
    MOV r1, #0

carga_derecha:
    CMP r1, #8
    BGE asm_barra_de_carga
    MOV r2, #1
    LSL r2, r2, r1
    BIC r4, r4, r2
    MOV r0, r4
    BL mostrar_led
    BL delay
    ADD r1, r1, #1
    B carga_derecha

mostrar_led:
    BX lr

delay:
    MOV r5, #0x30000
ret_loop:
    SUBS r5, r5, #1
    BNE ret_loop
    BX lr
