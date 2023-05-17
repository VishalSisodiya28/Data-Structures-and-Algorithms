#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

char player = 'X';

void displayBoard()
{
    cout << " \n   1    2    3  " << endl;
    cout << "   -------------" << endl;

    for (int i = 0; i < 3; i++)
    {

        cout << i + 1;
        cout << "  | ";
        for (int j = 0; j < 3; j++)
        {

            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "   ------------- " << endl;
    }
}

void switchPlayer()
{

    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}

bool isGameDraw()
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }

    return true;
}

bool isValidMove(int row, int col)
{

    if (row > 2 || col > 2 || row < 0 || col < 0)
    {
        return false;
    }

    if (board[row][col] != ' ')
    {
        return false;
    }

    return true;
}

bool checkWin()
{

    for (int i = 0; i < 3; i++)
    {

        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
        {
            return true;
        }

        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
        {
            return true;
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
    {
        return true;
    }

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
    {
        return true;
    }

    return false;
}

void play()
{

    while (true)
    {

        int row, col;

        cout << "Player " << player << " Enter the row and col position to play : ";
        cin >> row >> col;

        row--;
        col--;

        if (isValidMove(row, col))
        {

            board[row][col] = player;

            displayBoard();

            if (checkWin())
            {
                cout << "Player " << player << " Won !" << endl;
                return;
            }
            if (isGameDraw())
            {

                cout << "Game is Draw !";
                return;
            }
            switchPlayer();
        }

        else
        {

            cout << "Invalid move ! Try Again.." << endl;

            continue;
        }
    }
}

int main()
{

    displayBoard();
    play();

    return 0;
}
