/*
    "constraint"(variable)
    a : eax, rax, ax, al
    b : ebx, rbx, bx, bl
    c : ecx, ...
    .
    .
    .
    r : any GPR
    g : use any GPR mem location

    __asm__("assembly code" : "=a"(result) : "d"(data1), "c"(data2))
    this means : edx = data1, ecx = data2, result = eax
*/

#include <stdio.h>

int main(){

    int data1 = 10;
    int data2 = 20;
    int result;

    __asm__(
        "imull %%edx, %%ecx \n\t"
        "movl %%ecx, %%eax"

        : "=a"(result)
        : "d"(data1),"c"(data2)
    );

    printf("The result is %d\n",result);

    return 0;
}