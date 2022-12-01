#include <stdio.h>
#include <stdlib.h>

int main(){
    int elf1, elf2, elf3;
    elf1 = elf2  = elf3 = 0;
    int max1, max2, max3;
    max1 = max2 = max3 = 0;

    int total = 0;
    int index = 1;
    char read[10];
    FILE *input = fopen("input", "r");

    while(1){
        fgets(read, 60, input);
        if(strtol(read, NULL, 10) != 0){
            total += strtol(read, NULL, 10);
        }
        else{
            if(total > max1){
                max2 = max1;
                elf2 = elf1;
                max1 = total;
                elf1 = index;
            }
            else if(total > max2){
                max3 = max2;
                elf3 = elf2;
                elf2 = index;
                max2 = total;
            }
            else if(total > max3){
                max3 = total;
                elf3 = index;
            }
            total = 0;
            index++;
        }
        if(feof(input)) break;
    }
    printf("elf - %d, cal - %d\n", elf1, max1);
    printf("elf - %d, cal - %d\n", elf2, max2);
    printf("elf - %d, cal - %d\n", elf3, max3);
    printf("soucet - %d\n", max1 + max2 + max3);
}