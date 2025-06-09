.text
.global_start
_start:
MOV r4,#0 @i=0
choque_ext_centro: 
CMP r4, #4
BEQ choque_centro_ext
MOV r1, #1
LSL r2,r1,r4     @left=1<<i
MOV r1,#1
RSB r3,r4,#7    @r3=7-i
LSL r3,r1,r3    @ right = 1 << (7 - i)
ORR r0,r2,r3    @r0= left | right
BL mostrar_led
BL delay
ADD r4,r4,#1
B choque_ext_centro
choque_centro_ext:
MOV r4,#2
choque_centro_loop:
CMP r4,#-1
BLT _start @vuelve a empezar la secuencia
MOV r1,#1
LSL r2,r1,r4  @left= 1<<i
MOV r1, #1
RSB r3,r4,#7
LSL r3,r1,r3  @right = 1<<(7-i)
ORR r0, r2,r3 @r0=left|right
BL mostrar_led
BL delay
SUB r4, r4, #1
B choque_centro_loop
mostrar_led:
BX lr

delay:
MOV r5, #0x30000
ret_loop:
SUBS r5, r5, #1
BNE ret_loop
BX lr