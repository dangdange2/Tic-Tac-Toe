#include <stdio.h>
#include <stdlib.h>

void print_board(char[3][3]);
void init_board(char[3][3]);
void cmp_pick(char[3][3]);
double get_score(char, char, char);
char check_done(char[3][3]);
int main()
{
    char board[3][3];
    int isgameover = 0;
    int x, y;
    init_board(board);
    print_board(board);
    //gameloop
    while(isgameover==0){
        cmp_pick(board);
        print_board(board);
        isgameover=check_done(board);
        if(isgameover!=0) break;
        scanf("%d %d", &x, &y);
        board[x][y] = 'O';
        print_board(board);
        isgameover=check_done(board);

    }
    if(isgameover!='t')printf("\'%c\' is the winner!", isgameover);
    else printf("There's no winner");
    return 0;
}
void print_board(char board[3][3]){
    printf("     0   1   2 \n");
    printf("    ___ ___ ___\n");
    printf(" 0 | %c | %c | %c |\n", board[0][0],board[0][1],board[0][2]);
    printf("    ___ ___ ___\n");
    printf(" 1 | %c | %c | %c |\n", board[1][0],board[1][1],board[1][2]);
    printf("    ___ ___ ___\n");
    printf(" 2 | %c | %c | %c |\n", board[2][0],board[2][1],board[2][2]);
    printf("    ___ ___ ___\n");
}
void init_board(char board[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j]=' ';
        }
    }
}
void cmp_pick(char board[3][3]){
    int Ocount=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j]=='O') Ocount++;
        }
    }
    double R1= get_score(board[0][0],board[0][1],board[0][2]);
    double R2= get_score(board[1][0],board[1][1],board[1][2]);
    double R3= get_score(board[2][0],board[2][1],board[2][2]);
    double C1= get_score(board[0][0],board[1][0],board[2][0]);
    double C2= get_score(board[0][1],board[1][1],board[2][1]);
    double C3= get_score(board[0][2],board[1][2],board[2][2]);
    double DC= get_score(board[0][0],board[1][1],board[2][2]);
    double UC= get_score(board[2][0],board[1][1],board[0][2]);
    double max = (R1>=R2) ? R1 : R2;
    max = (max>=R3) ? max : R3;
    max = (max>=C1) ? max : C1;
    max = (max>=C2) ? max : C2;
    max = (max>=C3) ? max : C3;
    max = (max>=DC) ? max : DC;
    max = (max>=UC) ? max : UC;
    if(Ocount==4){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i][j]==' '){
                    board[i][j] = 'X';
                    break;
                }
            }
        }
    }
    if(board[1][1]==' ') board[1][1] = 'X';
    else if(max==R1){
        if(board[0][0]==' ') board[0][0] = 'X';
        else if(board[0][1]==' ') board[0][1] = 'X';
        else if(board[0][2]==' ') board[0][2] = 'X';
    }
    else if(max==R2){
        if(board[1][0]==' ') board[1][0] = 'X';
        else if(board[1][1]==' ') board[1][1] = 'X';
        else if(board[1][2]==' ') board[1][2] = 'X';
    }
    else if(max==R3){
        if(board[2][0]==' ') board[2][0] = 'X';
        else if(board[2][1]==' ') board[2][1] = 'X';
        else if(board[2][2]==' ') board[2][2] = 'X';
    }
    else if(max==C1){
        if(board[0][0]==' ') board[0][0] = 'X';
        else if(board[1][0]==' ') board[1][0] = 'X';
        else if(board[2][0]==' ') board[2][0] = 'X';
    }
    else if(max==C2){
        if(board[0][1]==' ') board[0][1] = 'X';
        else if(board[1][1]==' ') board[1][1] = 'X';
        else if(board[2][1]==' ') board[2][1] = 'X';
    }
    else if(max==C3){
        if(board[0][2]==' ') board[0][2] = 'X';
        else if(board[1][2]==' ') board[1][2] = 'X';
        else if(board[2][2]==' ') board[2][2] = 'X';
    }
    else if(max==DC){
        if(board[0][0]==' ') board[0][0] = 'X';
        else if(board[1][1]==' ') board[1][1] = 'X';
        else if(board[2][2]==' ') board[2][2] = 'X';
    }
    else if(max==UC){
        if(board[0][2]==' ') board[0][2] = 'X';
        else if(board[1][1]==' ') board[1][1] = 'X';
        else if(board[2][0]==' ') board[2][0] = 'X';
    }

}
double get_score(char a,char b,char c){
    int Xcount=0;
    int Ocount=0;
    if(a=='O') Ocount++;
    if(b=='O') Ocount++;
    if(c=='O') Ocount++;
    if(a=='X') Xcount++;
    if(b=='X') Xcount++;
    if(c=='X') Xcount++;
    if((Ocount!=0)&&(Xcount==0)) return Ocount;
    else if((Ocount==0)&&(Xcount!=0)) return 1.1*Xcount;
    else return 0;
}
char check_done(char board[3][3]){
    if((board[0][0]==board[0][1])&&(board[0][1]==board[0][2])&&board[0][0]!=' '){
        if(board[0][0]=='O') return 'O';
        else return 'X';
    }
    else if((board[1][0]==board[1][1])&&(board[1][1]==board[1][2])&&board[1][0]!=' '){
        if(board[1][0]=='O') return 'O';
        else return 'X';
    }
    else if((board[2][0]==board[2][1])&&(board[2][1]==board[2][2])&&board[2][0]!=' '){
        if(board[2][0]=='O') return 'O';
        else return 'X';
    }
    else if((board[0][0]==board[1][0])&&(board[1][0]==board[2][0])&&board[0][0]!=' '){
        if(board[0][0]=='O') return 'O';
        else return 'X';
    }
    else if((board[0][1]==board[1][1])&&(board[1][1]==board[2][1])&&board[0][1]!=' '){
        if(board[0][1]=='O') return 'O';
        else return 'X';
    }
    else if((board[0][2]==board[1][2])&&(board[1][2]==board[2][2])&&board[0][2]!=' '){
        if(board[0][2]=='O') return 'O';
        else return 'X';
    }
    else if((board[0][0]==board[1][1])&&(board[1][1]==board[2][2])&&board[0][0]!=' '){
        if(board[0][0]=='O') return 'O';
        else return 'X';
    }
    else if((board[0][2]==board[1][1])&&(board[1][1]==board[2][0])&&board[0][2]!=' '){
        if(board[0][2]=='O') return 'O';
        else return 'X';
    }
    else if((board[0][0]!=' ')&&(board[0][1]!=' ')&&(board[0][2]!=' ')&&(board[1][0]!=' ')&&(board[1][1]!=' ')&&(board[1][2]!=' ')&&(board[2][0]!=' ')&&(board[2][1]!=' ')&&(board[2][2]!=' ')) return 't';
    else return 0;
}
