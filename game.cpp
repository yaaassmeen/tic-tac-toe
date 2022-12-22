//Tic Tac Toe Game in C++

#include <iostream>
#include <stdlib.h>
using namespace std;

//2-D Array OF CHAR FOR THE BOARD

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

//Variable Declaration
int choice;
int row,column;
char turn = 'X';
bool Tie = false;

//Function to show the current status of the gaming board

void displayGameBoard(){

    //Rander Game Board LAYOUT

    cout<<"PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}

//Function to get the player input and update the board

void nextPlayer(){
    if(turn == 'X'){
        cout<<"\n\tPlayer - 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\n\tPlayer - 2 [O] turn : ";
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

    cin>> choice;

    //switch case to get which row and column will be update

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"ENTER VALID MOVE!"<<endl;
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }else {
        //if input position already filled
        cout<<"Box already filled!\n Please choose another Box!!\n\n";
        nextPlayer();
    }
    /* Ends */
    displayGameBoard();
}

//Function to get the game status e.g. GAME WON, GAME DRAW, GAME IN CONTINUE MODE

bool matchDecider(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //Checking the if game already draw
    Tie = true;
    return false;
}

//Program Main Method

int main()
{
    cout<<"\n\t\t\tT I C K -- T A C -- T O E -- G A M E\t\t\t";
    cout<<"\n\t\t\t\tFOR 2 PLAYERS\n\t\t\t"<<endl;
    while(matchDecider()){
        displayGameBoard();
        nextPlayer();
        matchDecider();
    }
    if(turn == 'X' && Tie == false){
        cout<<"\n\nCongratulations! Player with 'O' has won the game. XD";
        cout<<"\n\t\t Player with 'X' looses. ;)";
    }
    else if(turn == 'O' && Tie == false){
        cout<<"\n\nCongratulations! Player with 'X' has won the game. XD";
        cout<<"\n\t\t Player with 'O' looses. ;)";
    }
    else
    cout<<"\n\t\t\tTIE!!!\n\n";
    
} 