#include <stdio.h>
#include <stdlib.h>
/*
 * - X - Kámen -- A - Kámen + 3 -- C - Nůžky + 6 
 * - Y - Papír -- B - Papír + 3 -- A - Kámen + 6
 * - Z - Nůžky -- C - Nůžky + 3 -- B - Papír + 6
 */
int main(){
    int score = 0;
    FILE *input = fopen("input", "r");
    char read[60];
    while(1){
        fgets(read, 60, input);
        if(read[2] == 'X'){ // Kámen
            score+= 1;
            if(read[0] == 'A'){
                score += 3;
            }
            else if(read[0] == 'C'){
                score += 6; 
            }
        }
        else if(read[2] == 'Y'){ // Papír
            score+= 2;
            if(read[0] == 'B'){
                score += 3;
            }
            else if(read[0] == 'A'){
                score += 6; 
            }
        }
        else if(read[2] == 'Z'){ // Nůžky
            score+= 3;
            if(read[0] == 'C'){
                score += 3;
            }
            else if(read[0] == 'B'){
                score += 6; 
            } 
        }
        //printf("%s", read);
        if(feof(input)) break;
    }
    printf("Score - %d\n", score);
}