
#include <iostream>
using namespace std;

void print_board(char board[9][9], int start=0)
{
    for(int l=0;l<start;l++)  cout <<"\t";
    for(int l=0;l<9;l++)cout << "-";
    cout <<"\n";
    for (int i = 0; i < 9; i++)
    {
        for(int l=0;l<start;l++)
            cout <<"\t";
        for (int j = 0; j < 9; j++)
        {
            
            cout << board[i][j];
        }
        cout << "\n";
    }

    for(int l=0;l<start;l++)     cout <<"\t";
    for(int l=0;l<9;l++) cout << "-";
    cout <<"\n";
    
}

bool check_row(char board[9][9], int i, char v)
{
    bool found = false;
    for (int j = 0; j < 9; j++)
    {
        if (board[i][j] == v)
        {
            found = true;

            break;
        }
    }
    return !found;
}

bool check_col(char board[9][9], int j, char v)
{
    bool found = false;
    for (int i = 0; i < 9; i++)
    {
        if (board[i][j] == v)
        {
            found = true;

            break;
        }
    }
    return !found;
}

bool check_square(char board[9][9], int n, char v)
{
    int i = (n / 3) * 3;
    int j = (n % 3) * 3;
    bool found = false;
    for (int di = 0; di < 3; di++)
    {
        for (int dj = 0; dj < 3; dj++)
        {
            if (board[di + i][dj + j] == v)
            {
                found = true;
                break;
            }
        }
    }
    return !found;
}

long solve(char board[9][9], int start=0)
{
    long sum=1;
    if (start == 81)
    {
        cout << "There is a solution \n";
        print_board(board);
        cout << "\n\n";
    }
    else
    {
        #ifdef _DEBUG_
             print_board(board,start);
        #endif
        int row = start / 9;
        int col = start % 9;
        if (board[row][col] == ' ')
        {
            // try all the valid values and then go to the next loc
            for (int v = 1; v < 10; v++)
            {
                int n = (row / 3) * 3 + (col / 3);
                char vchar = v + '0';
                bool check = check_row(board, row, vchar) && check_col(board, col, vchar)
                             && check_square(board, n, vchar);
                if (!check)
                    continue;
            
                board[row][col] = vchar; //<<
                sum=sum+solve(board, start + 1);
                board[row][col] = ' '; //<<
            }
        }
        else
            sum=sum+solve(board, start + 1);
    }
return sum;
}
int main()
{
  /*  char board[9][9]={{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { '6', ' ', ' ', '1', '9', '5', ' ', ' ', ' ' },
        { ' ', '9', '8', ' ', ' ', ' ', ' ', '6', ' ' },
        { '8', ' ', ' ', ' ', '6', ' ', ' ', ' ', '3' },
        { '4', ' ', ' ', '8', ' ', '3', ' ', ' ', '1' },
        { '7', ' ', ' ', ' ', '2', ' ', ' ', ' ', '6' },
        { ' ', '6', ' ', ' ', ' ', ' ', '2', '8', ' ' },
        { ' ', ' ', ' ', '4', '1', '9', ' ', ' ', '5' },
        { ' ', ' ', ' ', ' ', '8', ' ', ' ', '7', '9' }
    };*/
    /*char board[9][9] =
        {
            {' ', ' ', ' ', '2', ' ', ' ', '7', '8', ' '}, // row 0
            {' ', '8', ' ', ' ', ' ', ' ', '1', ' ', ' '}, // row 1
            {' ', ' ', '1', '9', ' ', ' ', ' ', ' ', ' '}, // row 2
            {' ', ' ', '3', ' ', ' ', '5', ' ', ' ', ' '}, // row 3
            {' ', ' ', ' ', ' ', ' ', '7', '8', ' ', ' '}, // row 4
            {' ', '2', ' ', ' ', ' ', ' ', ' ', ' ', '9'}, // row 5
            {'8', ' ', ' ', '1', ' ', ' ', '5', '6', ' '}, // row 6
            {' ', '6', ' ', '3', ' ', ' ', ' ', '2', ' '}, // row 7
            {' ', ' ', ' ', ' ', ' ', '4', ' ', ' ', ' '}  // row 8
        };*/
        char board[9][9]=
          {
            {' ', ' ', '1', '7', ' ', ' ', ' ', '4', '3'}, // row 0
            {' ', ' ', ' ', ' ', ' ', ' ', '9', ' ', ' '}, // row 1
            {' ', ' ', '6',  ' ', '5', ' ', ' ', ' ', ' '}, // row 2
            {'4', ' ', ' ', ' ', ' ', ' ', ' ', '7', '2'}, // row 3
            {' ', '7', ' ', ' ', '6', ' ', ' ', ' ', ' '}, // row 4
            {'9', '2', '3', ' ', '8', ' ', ' ', ' ', ' '}, // row 5
            {' ', ' ', ' ', ' ', ' ', '5', '4', ' ', ' '}, // row 6
            {' ', '3', ' ', ' ', '1', ' ', '8', ' ', ' '}, // row 7
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', '5', '1'}  // row 8
        };


    print_board(board);
    long s=solve(board);
    cout <<s;
}