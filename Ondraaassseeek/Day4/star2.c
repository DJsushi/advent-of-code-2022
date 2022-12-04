#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *input = fopen("input", "r");
    int section1Low, section1High;
    int section2Low, section2High;
    int result = 0;
    while(1){
        fscanf(input, "%d-%d,%d-%d", &section1Low, &section1High, &section2Low, &section2High);
        if(section1Low > section2High || section2Low > section1High){
            result++;
        }   

        if(feof(input)) break;    
    }
    printf("result - %d\n", 1000 - result);
}