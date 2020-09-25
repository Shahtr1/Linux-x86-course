# sal destination (shifts the destinaton value left 1 position, which is multiplying by 2)
# sal %cl, destination (shifts the destinaton value left by the amount of times specified by the cl register, which is multiplying by 2)
# sal shifter, destination (shifts the destinaton value left shited as specified by the shifter which is a number, which is multiplying by 2)

.section .data
value1: .int 25
.section .text
.globl _start

_start:
    nop
    movl    $10,%ebx
    sall    %ebx
    movb    $2,%cl
    sall    %cl,%ebx
    sall    $2,%ebx
    sall    value1
    sall    $2,value1
    movl    $1,%eax
    movl    $0,%ebx
    int     $0x80
