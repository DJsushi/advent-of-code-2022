#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct row{
    char content[100];
    int size;
};


int main(){
    FILE *input = fopen("input.txt", "r");
    struct row rows[9];
    strcpy(rows[0].content, "DLVTMHF");
    rows[0]. size = 7;

    strcpy(rows[1].content, "HQGJCTNP");
    rows[1]. size = 8;
    
    strcpy(rows[2].content, "RSDMPH");
    rows[2]. size = 6;
    
    strcpy(rows[3].content, "LBVF");
    rows[3]. size = 4;
    
    strcpy(rows[4].content, "NHGLQ");
    rows[4]. size = 5;
    
    strcpy(rows[5].content, "WBDGRMP");
    rows[5]. size = 7;
    
    strcpy(rows[6].content, "GMNRCHLQ");
    rows[6]. size = 8;
    
    strcpy(rows[7].content, "CLW");
    rows[7]. size = 3;
    
    strcpy(rows[8].content, "RDLQJZMT");
    rows[8]. size = 8;

    int count, from, to;
    while(1){
        fscanf(input, "%d %d %d", &count, &from, &to);
        //printf("%d %d %d\n", count, from, to);
        for(int i = count; i > 0; i--){
            //printf("%d\n", i);
            if(rows[from - 1].size != 0){
                rows[to - 1].content[rows[to - 1].size + count - i] = rows[from - 1].content[rows[from - 1].size - i];
            }
        }
        rows[to - 1].size += count;
        rows[from - 1].size -= count;

        if(feof(input)) break;
    }
    printf("%c %c %c %c %c %c %c %c %c",rows[0].content[rows[0].size - 1], rows[1].content[rows[1].size - 1], rows[2].content[rows[2].size - 1], rows[3].content[rows[3].size - 1], rows[4].content[rows[4].size - 1], rows[5].content[rows[5].size - 1], rows[6].content[rows[6].size - 1], rows[7].content[rows[7].size - 1], rows[8].content[rows[8].size - 1]);
}