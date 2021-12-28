#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZE 7
#define LEN strlen(words[rIx])
#define MAX_READ 20

void printPattern(char *,int );

int main(void)
{
    char *words[SIZE] = {
            "apple",
            "banana",
            "water",
            "oat",
            "tea",
            "plane",
            "hello"
    };
    char *descriptions[SIZE] = {
            "a kind of fruit",
            "a kind of fruit",
            "the source of life",
            "best food for diets",
            "british drink",
            "it has wings",
            "hi"
    };

    srand(time(NULL));

    int rIx,
    count=0,rights,isFind,
    lIx;

    char guess[MAX_READ],pattern[6] = {95,95,95,95,95,95};

    rIx = rand() % SIZE;
    rights=LEN+1;
    printf("Tip: ");puts(descriptions[rIx]);
    printPattern(pattern,LEN);
    while(count < LEN)
    {
        if(rights==0){
            isFind = -1;
            break;
        }

        printf("\nTake a guess: ");fgets(guess,MAX_READ,stdin);

        isFind = count;
        for(lIx=0;lIx<LEN;lIx++){
            if(pattern[lIx]!=95)
                continue;

            if(guess[0]==words[rIx][lIx]){
                pattern[lIx] = guess[0];
                count++;
            }
        }
        if(isFind==count)
            rights--;
        printPattern(pattern,LEN);
    }

    if(isFind==-1)
        printf("\n\n :( You Lose. The word was %s.\n",words[rIx]);
    if(count==LEN)
        printf("\n\n :O Congrats. You find it\n.",words[rIx]);

    return 0;
}


void printPattern(char *ptrpat,int length){int lIx;
    printf("\n  ");
    for(lIx=0;lIx<length;lIx++)
        printf("%c ",*(ptrpat+lIx));
    printf("\n");
}
