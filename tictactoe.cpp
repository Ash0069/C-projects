#include<iostream>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char currentplayer='X';

void draw(){
    cout<<"_______"<<endl;
    for(int i=0;i<3;i++){
        cout<<"|";
        for(int j=0;j<3;j++){
            cout<<board[i][j]<<"|";
        }
        cout<<endl;
        cout<<"_______"<<endl;
    }
}

bool checkwin(){
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            return true;
        }
    }
    for(int i=0;i<3;i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            return true;
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        return true;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        return true;
    }
    return false;
}

bool checktie(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] != 'X' && board[i][j] != 'O'){
                return false;
            }
        }
    }
    return true;
}

void switchp(){
    if(currentplayer=='X'){
        currentplayer='O';
    }
    else{
        currentplayer='X';
    }
}

void turn(){
    int choice;
    cout<<"Player "<<currentplayer<<", choose a number : ";
    cin>>choice;
    int row = (choice-1)/3;
    int col = (choice-1)%3;
    if(board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col]=currentplayer;
    }
    else{
        cout<<"Chosen space is occupied, try again"<<endl;
        turn();
    }
}

int main(){
    draw();
    while(!checkwin() && !checktie()){
        turn();
        draw();
        switchp();
    }
    if(checkwin()){
        switchp();
        cout<<"Player "<<currentplayer<<" wins!"<<endl;
    }
    else{
        cout<<"Game tied!"<<endl;
    }
    return 0;
}