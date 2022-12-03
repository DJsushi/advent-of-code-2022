#include <stdio.h>
#include <stdlib.h>

char comp1[100];
char comp2[100];
char comp3[100];
int index1, index2, index3;
int result;
int main(){
    FILE *input = fopen("input", "r");
    while(1){
        fgets(comp1, 100, input);
        fgets(comp2, 100, input);
        fgets(comp3, 100, input);
        //printf("%s", comp);
        for(int i = 0; i < 100; i++){
            if(comp1[i] == '\n' || comp1[i] == '\0'){
                index1 = i;
                break;
            }
        }
        for(int i = 0; i < 100; i++){
            if(comp2[i] == '\n' || comp2[i] == '\0'){
                index2 = i;
                break;
            }
        }
        for(int i = 0; i < 100; i++){
            if(comp3[i] == '\n' || comp3[i] == '\0'){
                index3 = i;
                break;
            }
        }

        for(int i = 0; i < index1; i++){
            for(int j = 0; j < index2; j++){
                for(int k = 0; k < index3; k++){
                    if(comp1[i] == comp2[j] && comp2[j] == comp3[k]){
                        printf("%c\n", comp1[i]);
                        if(comp1[i] >= 97){
                            result += (int)comp1[i] - 96;
                            i = index1;
                            j = index2;
                        }
                        else{
                            result += (int)comp1[i] - 38;
                            i = index1;
                            j = index2;
                        }
                    }
                }
            }
        }
        if(feof(input)) break;
    }
    printf("result - %d\n", result);
}