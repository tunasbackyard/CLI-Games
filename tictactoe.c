#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define BOARD_SIZE 10
#define NAME_SIZE 10
#define MAX_READ 5

char board[BOARD_SIZE] = {'0',
    '1','2','3',
    '4','5','6',
    '7','8','9'};

typedef struct{
    int id;
    char name[NAME_SIZE];
    char mark;
    int score;
}Player;

int checkWin();
void printBoard(Player,Player,int);
int checkPlace(int );
void clearBoard();

int main(void){
    int isDone=0,
    round=1,playerID,
    choise,
    totalGame=0;

    Player p1;p1.id=1;
    printf("Player 1 name: ");fgets(p1.name,NAME_SIZE,stdin);
    p1.name[strcspn(p1.name, "\n")]=0;// for removing \n putted by fgets
    p1.mark='X';p1.score=0;
    Player p2;p2.id=2;
    printf("Player 2 name: ");fgets(p2.name,NAME_SIZE,stdin);
    p2.name[strcspn(p2.name, "\n")]=0;// for removing \n putted by fgets
    p2.mark='O';p2.score=0;

    while(!isDone){
        printBoard(p1,p2,round);
        if( round>BOARD_SIZE-1 || checkWin() ){
            if(checkWin){
                if(playerID == p1.id){
                    printf("%s won.\n",p1.name);
                    p1.score+=1;
                    sleep(2);
                }

                if(playerID == p2.id){
                    printf("\t%s won\n",p2.name);
                    p2.score+=1;
                    sleep(2);
                }
            }else{
                printf("Draw, no points rewarded.\n");
            }
            char resp;
            printf("Do you wanna play again?(y/n)");scanf(" %c",&resp);
            resp=tolower(resp);
            if(resp=='y'){
                round=0;
                totalGame+=1;
                clearBoard();
                continue;
            }else if(resp == 'n'){
                system("cls");
                // print statistics
                printf("\nGoodbye:)");
                break;
            }else{
                fputs("Invalid option",stderr);
                break;
            }
        }
        playerID=(round%2)? 1 : 2;
        if(playerID==1){
            printf("%s choise: ",p1.name);scanf("%d",&choise);
            if(checkPlace(choise)){
                board[choise]=p1.mark;
            }else{
                printf("\nThe position already chosen by a player.");
                sleep(2);
                round--;
            }
        }else if(playerID==2){
            printf("%s choise: ",p2.name);scanf("%d",&choise);
            if(checkPlace(choise)){
                board[choise]=p2.mark;
            }else{
                printf("\nThe position already chosen by a player.");
                sleep(2);
                round--;
            }
        }else{
            fputs("Invalid Player ID",stderr);
        }
        round++;
    }

    return 0;
}

int checkWin(){
    if(board[1] == board[2] && board[2] == board[3]){
        return 1;
    }else if(board[1] == board[2] && board[2] == board[3]){
        return 1;
    }else if(board[4] == board[5] && board[5] == board[6]){
        return 1;
    }else if(board[7] == board[8] && board[8] == board[9]){
        return 1;
    }else if(board[1] == board[4] && board[4] == board[7]){
        return 1;
    }else if(board[2] == board[5] && board[5] == board[8]){
        return 1;
    }else if(board[3] == board[6] && board[6] == board[9]){
        return 1;
    }else if(board[1] == board[5] && board[5] == board[9]){
        return 1;
    }else if(board[3] == board[5] && board[5] == board[7]){
        return 1;
    }else if(board[1] == board[2] && board[2] == board[3]){
        return 1;
    }else
        return 0;
}

void printBoard(Player p1,Player p2,int round){
    system("cls");
    printf("\tRound (%d)\n",round);
    printf("%s %c (%d) | %s %c (%d)\n",
        p1.name,p1.mark,p1.score,
        p2.name,p2.mark,p2.score);
    printf("\n");
    printf("\t   |   |   \n");
    printf("\t %c | %c | %c \n",board[1],board[2],board[3]);
    printf("\t___|___|___\n");
    printf("\t   |   |   \n");
    printf("\t %c | %c | %c \n",board[4],board[5],board[6]);
    printf("\t___|___|___\n");
    printf("\t   |   |   \n");
    printf("\t %c | %c | %c \n",board[7],board[8],board[9]);
    printf("\t   |   |   \n");
}


int checkPlace(int choise){
    if(board[choise]=='X')
        return 0;
    else if(board[choise]=='0')
        return 0;
    else
        return 1;
}


void clearBoard(){int lIx=1;char num=49;
    for(lIx=1;lIx<BOARD_SIZE;lIx++){
        board[lIx] = num;
        num++;
    }
}



