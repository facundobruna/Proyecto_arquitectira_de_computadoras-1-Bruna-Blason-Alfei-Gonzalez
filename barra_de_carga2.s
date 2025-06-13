.text
.global asm_barra_de_carga
.extern mostrar_led
.extern delay_ms
.extern velocidad_ms

asm_barra_de_carga:
    MOV x1, #7          // contador izquierda
    MOV x4, #0          // registro acumulador

carga_izquierda:
    CMP x1, #0
    BLT descarga
    MOV x2, #1
    LSL x2, x2, x1
    ORR x4, x4, x2
    MOV x0, x4
    BL mostrar_led

    ADRP x0, velocidad_ms
    ADD x0, x0, :lo12:velocidad_ms
    LDR x0, [x0]
    BL delay_ms

    SUB x1, x1, #1
    B carga_izquierda

descarga:
    MOV x1, #0

carga_derecha:
    CMP x1, #8
    BGE asm_barra_de_carga
    MOV x2, #1
    LSL x2, x2, x1
    BIC x4, x4, x2
    MOV x0, x4
    BL mostrar_led

    ADRP x0, velocidad_ms
    ADD x0, x0, :lo12:velocidad_ms
    LDR x0, [x0]
    BL delay_ms

    ADD x1, x1, #1
    B carga_derecha
