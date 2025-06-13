.text
.global asm_parimpar
.extern mostrar_led
.extern delay_ms
.extern velocidad_ms

asm_parimpar:
    MOV x1, #0b10101010      // Patrón par
    MOV x2, #0b01010101      // Patrón impar

parimpar_loop:
    MOV x0, x1
    BL mostrar_led

    ADRP x0, velocidad_ms
    ADD x0, x0, :lo12:velocidad_ms
    LDR x0, [x0]
    BL delay_ms

    MOV x0, x2
    BL mostrar_led

    ADRP x0, velocidad_ms
    ADD x0, x0, :lo12:velocidad_ms
    LDR x0, [x0]
    BL delay_ms

    B parimpar_loop
