#include <iostream>
#include <cctype> // C Character Type Libary for toupper() function
using namespace std;

char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

char currentMarker;
int currentPlayer;

void drawBoard()
{
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

void drawBoardAfterInput()
{
    int slot;
    while (true)
    {

        cout << "Player " << currentPlayer << " ,enter the cell number (1-9) where you want to place your marker: ";
        cin >> slot;

        // Input Validation
        if (slot < 1 || slot > 9)
        {
            cout << "Invalid slot! Please enter a number between 1 and 9.\n";
            continue;
        }

        // Convert slot into row & col
        int row = (slot - 1) / 3;
        int col = (slot - 1) % 3;
        /*
        Slot: 1 2 3
              4 5 6
              7 8 9

        Slot 1 → [0][0]
        Slot 2 → [0][1]
        Slot 3 → [0][2]
        Slot 4 → [1][0]
        Slot 5 → [1][1]
        Slot 6 → [1][2]
        Slot 7 → [2][0]
        Slot 8 → [2][1]
        Slot 9 → [2][2]
        */
        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            cout << "That cell is already taken! Choose another one.\n";
            continue;
        }

        // Valid move -> Place Marker
        board[row][col] = currentMarker;
        break; // Exit loop after successfull move
    }
    drawBoard();
}

int checkwin()
{
    // TODO: check all rows, cols, diagonals
    // check all the rows for win
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if (board[i][0] == 'X')
                return 1; // if X win we return 1
            if (board[i][0] == 'O')
                return 2; // if O win we return 2
        }
    }

    // check all the columns for win
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if (board[0][i] == 'X')
                return 1;
            if (board[0][i] == 'O')
                return 2;
        }
    }

    // check all the diagonals for win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]))
    {
        if (board[0][0] == 'X')
            return 1;
        if (board[0][0] == 'O')
            return 2;
    }
    else if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]))
    {
        if (board[0][2] == 'X')
            return 1;
        if (board[0][2] == 'O')
            return 2;
    }

    return 0; // if no wins then we return 0
}

bool isTie()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O') // check if there are empty cells in our board
            {
                return false;
            }
        }
    }
    if (checkwin() == 0)
    {
        return true; // we return true for tie
    }
    return false; // we return false for not tie
}

void swapPlayerAndMarkerBoth() // for the next player's turn
{
    if (currentMarker == 'X')
        currentMarker = 'O';
    else
        currentMarker = 'X';

    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    // if alse logic to do the same task
    //  if (currentPlayer == 1)
    //      currentPlayer = 2;
    //  else
    //      currentPlayer = 1;
}

int main()
{

    cout << "--------------------TIC-TAC-TOE----------------\n";
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;
    currentMarker = toupper(currentMarker);
    while (currentMarker != 'X' && currentMarker != 'O')
    {
        cout << "INVALID MARKER : Enter a valid marker!! (X or O): ";
        cin >> currentMarker;
        currentMarker = toupper(currentMarker);
    }
    currentPlayer = 1;

    cout << "\nStarting the game....\n\n";
    drawBoard();
    while (true)
    {
        drawBoardAfterInput();
        if (checkwin() == 1 || checkwin() == 2)
        {
            break;
        }
        if (isTie()) // fuction isTie is already returning true or false
        {
            break;
        }
        swapPlayerAndMarkerBoth();
    }
    if (checkwin() == 1)
        cout << "Player " << currentPlayer << " with X wins!!!" << endl;
    else if (checkwin() == 2)
        cout << "Player " << currentPlayer << " with O wins!!!" << endl;
    else
        cout << "\nIt's a Tie!!!." << endl;

    return 0;
}