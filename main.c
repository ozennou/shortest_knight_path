#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "knight.h"

int main(){
    char a[2],b[2];
    while(1){
        printf("\nThe current position:");
        gets(a);
        printf("The destination position:");
        gets(b);
        printf("====>The shortest knight path is %d",knight(a,b));
    }
}