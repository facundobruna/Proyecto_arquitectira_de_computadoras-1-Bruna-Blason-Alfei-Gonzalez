.text
.global asm_barra_de_carga
.extern mostrar_led
.extern delay_ms
.extern velocidad_ms

asm_barra_de_carga:
    MOV r1, #7
    MOV r4, #0

carga_izquierda:
    CMP r1, #-1
    BLT descarga
    MOV r2, #1
    LSL r2, r2, r1
    ORR r4, r4, r2
    MOV r0, r4
    BL mostrar_led

   @ LDR r0, =velocidad_ms
    @LDR r0, [r0]
   MOV r0,#300
    BL delay_ms

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


   @ LDR r0, =velocidad_ms
    @LDR r0, [r0]
   MOV r0,#300
    BL delay_ms

    ADD r1, r1, #1
    B carga_derecha


@mostrar_led:
@    BX lr
@
@delay:
 @   MOV r5, #0x30000
@ret_loop:
 @   SUBS r5, r5, #1
  @  BNE ret_loop
   @ BX lr
