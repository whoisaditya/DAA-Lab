// C++ program for Knight Tour problem
#include <bits/stdc++.h>
using namespace std;

class Board
{
public:
    int N;

    int solveKTUtil(int x, int y, int movei, int **sol,
                    int *xMove, int *yMove);

    int isSafe(int x, int y, int **sol);

    void printSolution(int **sol);

    int solveKT(int a, int b);
};

int Board::isSafe(int x, int y, int **sol)
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

void Board::printSolution(int **sol)
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            cout << " " << setw(2) << sol[x][y] << " ";
        }
        cout << endl;
    }
}

int Board::solveKT(int a, int b)
{
    int **sol = new int *[N];

    for (int x = 0; x < N; x++)
    {
        sol[x] = new int[N];
        for (int y = 0; y < N; y++)
        {
            sol[x][y] = -1;
        }

        int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

        sol[a][b] = 0;

        if (solveKTUtil(a, b, 1, sol, xMove, yMove) == 0)
        {
            cout << "Solution does not exist";
            return 0;
        }
        else
        {
            printSolution(sol);
        }

        return 1;
    }
}

int Board::solveKTUtil(int x, int y, int movei, int **sol,
                       int xMove[8], int yMove[8])
{
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;

    for (k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol))
        {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                            xMove, yMove) == 1)
            {
                return 1;
            }
            else
            {
                sol[next_x][next_y] = -1;
            }
        }
    }
    return 0;
}

// Driver Code
int main()
{

    cout << "Aditya Mitra 20BCE2044\n";
    Board b;
    cout << "Enter the size of the board: ";
    cin >> b.N;

    int x, y;
    cout << "Enter the starting position: ";
    cin >> x >> y;

    // Function Call
    b.solveKT(x, y);
    return 0;
}
