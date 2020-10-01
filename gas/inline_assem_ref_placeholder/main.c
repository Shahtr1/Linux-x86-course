#include <stdio.h>

int main(){
    
    int data1 = 10;
    int data2 = 20;

    __asm__(
        "imull %1, %0"
        : "=r"(data2)
        : "r"(data1),"0"(data2)
    );

    printf("The result is %d\n", data2);

    return 0;
}