// Programmer: Kyle Marut
// Date: 9/25/2024
// File: hw2.cpp
// Assignment: HW2
// Purpose: this file contains the main function of the program acts as a 
//tic-tac-toe game for two players

#include <iostream>
#include <string>
using namespace std;

void printWelcomeMessage();
int displayMenu();
string initializeBoard(const int);
void printBoard(const string, const int);
void updateBoard(string &, const string,const string);
bool checkWin(const string, const int);
bool checkTie(const string);




int main()
{
    //variable declarations
    int option;
    string board, p1, p2, currentPlayer, cell;
    int turnCount;
    bool cont = true;
    cout<<"Please enter the name of Player 1: "<<endl;
    cin>>p1;
    cout<<"Please enter the naem of Player 2: "<<endl;
    cin>>p2;
    
    while(cont)
    {
        option = displayMenu();
        turnCount = 0;
        //swithc case for each variation of the board
        switch (option){
            case 1:
                board = initializeBoard(3);
                break;
            case 2:
                board = initializeBoard(4);
                break;
            case 3:
                board = initializeBoard(5);
                break;
            case 4:
                board = initializeBoard(6);
                break;
            case 5:
                board = initializeBoard(7);
                break;
            case 6:
                board = initializeBoard(8);
                break;
            case 7:
                board = initializeBoard(9);
                break;
            //default is used for any number 8 or above
            default:
                cout<<"Thank you for playing Tic-Tac-Toe!"<<endl;
                cont = false;
                break;
        }
        //loops until game has ended with a winner or a tie
        while(!(checkTie(board) || checkWin(board, option + 2)))
        {
            //switches player
            if(turnCount % 2 == 0)
            {
                currentPlayer = "SS";
            }
            else
            {
                currentPlayer = "TT";
            }
            printBoard(board, option+2);
            cout<<"Choose a cell: "<<endl;
            cin>>cell;
            updateBoard(board, cell,currentPlayer);
            if(checkTie(board))
            {
                printBoard(board, option+2);
                cout<<"The game has ended in a tie!"<<endl;
            }
            if(checkWin(board, option + 2))
            {
                printBoard(board, option+2);
                if (currentPlayer == "SS")
                {
                    cout<<p1;
                }
                else
                {
                    cout<<p2;
                }
                cout<<" has won the game!"<<endl;
            }
            turnCount++;
        }
    }
    return 0;
}

//displays menu and gets value for board size
int displayMenu()
{
    int choice;
    cout<<"Choose the size of the Tic-Tac-Toe board or Quit:"<<endl
    <<"1. 3x3 Board"<<endl
    <<"2. 4x4 Board"<<endl
    <<"3. 5x5 Board"<<endl
    <<"4. 6x6 Board"<<endl
    <<"5. 7x7 Board"<<endl
    <<"6. 8x8 Board"<<endl
    <<"7. 9x9 Board"<<endl
    <<"8. Quit the Program"<<endl
    <<"Enter your choice: "<<endl;
    cin>>choice;
    return choice;
}

//creates the string used for the board
string initializeBoard(const int size)
{
    string board = "";
    for(int i = 1; i <= size*size; i++)
    {
        //adds a 0 if current number is less than 10
        if (i < 10)
        {
            board += std :: to_string(0);
        }
        board += std :: to_string(i) + ' ';
    }
    return board;
}

//displays the board in a user-friendly manner
void printBoard(const string board, const int size)
{
    for(int i = 0; i < board.length(); i++)
    {
        cout << board[i];
        if((i+1)%(size*3) == 0)
        {
            cout<<endl;
        }
    }
}

//replaces the chosen cell with either SS or TT depending on the player
void updateBoard(string & board, string cell, const string currentPlayer)
{
    bool cont = true;
    while(cont)
    {
        //makes sure cell isn't letters to prevent overriding
        if (cell[0]>47 && cell[0]<58)
        {
            //goes through board looking for matching cell
            for (int i = 0; i < board.length()-1; i++)
            {
                if (board[i] == cell[0] && board[i+1] == cell[1])
                {
                    board[i] = currentPlayer[0];
                    board[i+1] = currentPlayer[1];
                    cont = false;
                }
            }
        }
        if(cont)
        {
            cout<<"Invalid option"<<endl<<"Enter a new option:"<<endl;
            cin>>cell;
        }
    }
    return;
}

bool checkWin(const string board, const int size)
{
    int inARow = 1;
    bool win = false;
    //horizontal
    //for loop goes until compares with the final cell
    for (int i = 1; i < board.length()-3; i+=3)
    {
        //compares cell with the next
        if (board[i] == board[i+3])
        {
            inARow++;
        }
        else
        {
            inARow = 1;
        }
        if (inARow == size)
        {
            win= true;
        }
        //resets inARow when end of row is reached
        if((i+2)%(size*3)==0)
        {
            inARow = 1;
        }
    }
    //vertical
    //for loop goes across until it reaches final column
    for (int i = 1; i < size * 3; i += 3)
    {
        inARow = 1;
        //for loop goes until it compares with final row
        for (int k = i; k < 3*(size * (size-1)) + i; k+=size*3)
        {
            if (board[k] == board[k+size*3])
            {
                inARow++;
            }
            else
            {
                inARow = 1;
            }
            if (inARow == size)
            {
                win= true;
            }
        }
    }
    inARow = 1;
    //topleft-bottomright
    //goes until it compares with last row
    for (int i = 0; i < 3*(size * (size-1)); i+=3*(size+1))
    {
        if (board[i] == board[i + (size *3 + 3)] && board[i+1] == board[i + (size *3 + 3)+1])
        {
            
            inARow++;
        }
        else
        {
            inARow = 1;
        }
        if (inARow == size)
        {
            win  = true;
        }
    }
    inARow = 1;
    //topright-bottomeleft
    //goes until it compares with last row
    for (int i = -2+size*3; i < 3*(size*(size-1));i += 3*(size-1))
    {
        if (board[i] == board[i + (size *3 - 3)])
        {
            inARow++;
        }
        else
        {
            inARow = 1;
        }
        if (inARow == size)
        {
            win = true;
        }
    }
    
    
    return win;
}

//checks if all the cells have been taken by the user
bool checkTie(const string board)
{
    bool tie = true;
    for(int i = 0; i < board.length(); i++)
    {
        if (board[i]>47 && board[i]<58)
        {
            tie = false;
        }
    }
    return tie;
}






