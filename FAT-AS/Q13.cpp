/*
Approach:  
A cell in 2D matrix can be connected to at most 8 neighbours.
So in Depth First Search, make recursive calls for 8 neighbours of that cell.
Keep a visited Hash-map to keep track of all visited cells.
Also keep track of the visited 1’s in every DFS and update maximum length region.

Take a 4*4 2D matrix from the user.

Define L_Region, a function to find the length of the largest region in the matrix.
If a cell with value 1 is not visited yet, then new region found and call DFS on it.
Store maximum region in result and return it.

Define DFS, a function to implement Depth First Search.
Use two static arrays to store the directions of the 8 neighbours.
If cells are visted then mark them as visited.
Recurr for all the neighbours and increment the length of the region.

Define Is_Safe, a function to check if a cell is safe to be included in the region.

*/

// Program to find the length of the largest region in 2D-matrix
#include <iostream>
#include <cstring>

using namespace std;

#define ROW 4
#define COL 4

// A function to check if a given cell (row, col) can be included in DFS
int Is_Safe(int M[][COL], int row, int col, bool visited[][COL])
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]);
}

// A utility function to do DFS for a 2D boolean matrix.
void DFS(int M[][COL], int row, int col, bool visited[][COL], int &count)
{
    // These arrays are used to get row and column numbers of 8 neighbours of a given cell
    static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Mark this cell as visited
    visited[row][col] = true;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
    {
        if (Is_Safe(M, row + rowNbr[k],
                    col + colNbr[k],
                    visited))
        {
            // Increment region length by one
            count++;
            DFS(M, row + rowNbr[k], col + colNbr[k],
                visited, count);
        }
    }
}

int L_Region(int M[][COL])
{
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    int result = INT_MIN;
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            
            if (M[i][j] && !visited[i][j])
            {
                
                int count = 1;
                DFS(M, i, j, visited, count);

                // maximum region
                result = max(result, count);
            }
        }
    }
    return result;
}

// Driver code
int main()
{
    int arr[ROW][COL];

    cout << "Enter the matrix elements (row wise):\n";
    // Input matrix
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            cout << "Enter the value for M[" << i << "][" << j << "] : ";
            cin >> arr[i][j];
        }
        cout << endl;
    }

    cout << "The largest region is " << L_Region(arr) << endl;

    return 0;
}
