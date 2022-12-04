#include <stdio.h>
#include <stdlib.h>

char comp[100];
char comp1[100];
char comp2[100];
int idx;
int index1, index2;
int result;
int main(){
    FILE *input = fopen("input", "r");
    while(1){
        fgets(comp, 100, input);
        //printf("%s", comp);
        for(int i = 0; i < 100; i++){
            if(comp[i] == '\n' || comp[i] == EOF){
                idx = i;
                break;
            }
        }
        //printf("%d\n", idx);
        int j = 0;
        for(int i = 0; i < idx; i++){
            if(i < idx / 2){
                comp1[i] = comp[i];
            }
            else if(i >= idx / 2){
                comp2[j] = comp[i];
                j++;
            }
        }
        //printf("%s - %s\n", comp1, comp2);
        index1 = idx / 2;
        index2 = idx - index1;
        //printf("%d - %d\n", index1, index2);

        int cnt = 0;
        for(int i = 0; i < index1; i++){
            for(int j = 0; j < index2; j++){
                if(comp1[i] == comp2[j]){
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
        if(feof(input)) break;
    }
    printf("result - %d\n", result);
}