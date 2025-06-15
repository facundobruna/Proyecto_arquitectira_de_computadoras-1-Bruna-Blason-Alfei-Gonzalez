.global asm_barra_de_carga
.extern mostrar_led
.extern delay_ms
.extern velocidad_ms

.section .text

asm_barra_de_carga:
    push {lr}           @ Guardar link register

    mov r4, #0          @ r4 será el estado de los LEDs (registro acumulador)
    mov r5, #0          @ r5 será el índice (de 0 a 7)
    mov r6, #1          @ Dirección: 1 = derecha, 0 = izquierda

carga_izquierda:
    cmp r5, #8
    bge cambio_a_izquierda

    mov r2, #1
    lsl r2, r2, r5      @ r2 = 1 << r5
    orr r4, r4, r2      @ r4 |= (1 << r5)
    mov r0, r4
    bl mostrar_led

    ldr r1, =velocidad_ms
    ldr r0, [r1]
    bl delay_ms

    add r5, r5, #1
    b carga_izquierda

cambio_a_izquierda:
    sub r5, r5, #1
    b carga_derecha

carga_derecha:
    cmp r5, #0
    blt asm_barra_de_carga

    mov r2, #1
    lsl r2, r2, r5
    bic r4, r4, r2      @ r4 &= ~(1 << r5)
    mov r0, r4
    bl mostrar_led

    ldr r1, =velocidad_ms
    ldr r0, [r1]
    bl delay_ms

    sub r5, r5, #1
    b carga_derecha

    pop {lr}
    bx lr
