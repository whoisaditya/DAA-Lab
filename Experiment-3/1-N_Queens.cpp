#include <iostream>
#define N 8

using namespace std;

void print_solution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                cout << "_"
                     << "\t";
            }
            if (board[i][j] == 1)
            {
                cout << "Q"
                     << "\t";
            }
        }
        cout << "\n"
             << endl;
    }
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

bool solve_N_Queens_Util(int board[N][N], int col)
{

    if (col >= N)
    {
        return true;
    }

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            if (solve_N_Queens_Util(board, col + 1))
            {
                return true;
            }

            board[i][col] = 0;
        }
    }
    return false;
}

bool solve_N_Queens()
{
    int board[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    if (solve_N_Queens_Util(board, 0) == false)
    {
        cout << "Solution does not exist";
        return false;
    }

    print_solution(board);
    return true;
}

int main()
{

    cout << "Aditya Mitra 20BCE2044" << endl;
    cout << "Solution: " << endl;
    solve_N_Queens();
    return 0;
}
