#include <stdio.h>
#include <stdlib.h>

int main(){
    char string[4096];
    FILE *input = fopen("input", "r");
    int idx = 3;
    int checkpos = 0;
    int idxPrintOut = 0;
    for(int i = 0; i < 3; i++){
        string[i] = fgetc(input);
    }
    while(1){
        int check = 0;
        string[idx] = fgetc(input);
        for(int i = checkpos; i < idx + 1; i++){
            for(int j = i + 1; j < idx + 1; j++){
                if(string[i] == string[j]){
                    check++;
                }
            }
        }
        if(check == 0){
            idxPrintOut = idx + 1;
        }
        idx++;
        checkpos++;
    if(feof(input) || idxPrintOut != 0) break;
    }
    printf("result - %d\n", idxPrintOut);
}