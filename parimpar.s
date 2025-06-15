.global asm_parimpar
.extern mostrar_led
.extern delay_ms
.extern velocidad_ms

.section .text

asm_parimpar:
    push {lr}             @ Guardar el link register

parimpar_loop:
    mov r0, #170          @ 10101010 en binario (pares)
    bl mostrar_led

    ldr r1, =velocidad_ms
    ldr r0, [r1]
    bl delay_ms

    mov r0, #85           @ 01010101 en binario (impares)
    bl mostrar_led

    ldr r1, =velocidad_ms
    ldr r0, [r1]
    bl delay_ms

    b parimpar_loop       @ Repetir infinitamente

    pop {lr}
    bx lr
