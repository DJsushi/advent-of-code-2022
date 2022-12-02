#include <stdio.h>
#include <stdlib.h>
/*
 * - X - Lose -- A - Kámen + 3 -- C - Nůžky + 6 
 * - Y - Draw -- B - Papír + 3 -- A - Kámen + 6
 * - Z - Win  -- C - Nůžky + 3 -- B - Papír + 6
 */
int main(){
    int score = 0;
    FILE *input = fopen("input", "r");
    char read[60];
    while(1){
        fgets(read, 60, input);
        if(read[0] == 'A'){ // Kámen
            if(read[2] == 'X'){ // Musím prohrát hraju Nůžky
                score += 3;
            }
            else if(read[2] == 'Y'){ // Musím remízovat hraju Kámen
                score += 4; 
            }
            else if(read[2] == 'Z'){ // Musím vyhrát hraju Papír
                score += 8; 
            }
        }
        else if(read[0] == 'B'){ // Papír
            if(read[2] == 'X'){ // Musím prohrát hraju Kámen
                score += 1;
            }
            else if(read[2] == 'Y'){ // Musím remízovat hraju Papír
                score += 5; 
            }
            else if(read[2] == 'Z'){ // Musím vyhrát hraju nůžky
                score += 9; 
            }
        }
        else if(read[0] == 'C'){ // Nůžky
            if(read[2] == 'X'){ // Musím prohrát hraju Papír
                score += 2;
            }
            else if(read[2] == 'Y'){ // Musím remízovat hraju Nůžky
                score += 6; 
            }
            else if(read[2] == 'Z'){ // Musím vyhrát hraju Kámen
                score += 7; 
            }
        }
        if(feof(input)) break;
    }
    printf("Score - %d\n", score);
}