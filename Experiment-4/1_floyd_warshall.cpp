#include <iostream>
#include <conio.h>

using namespace std;

class Graph 
{
    public:
    int n;
    int **adj;

    void floyd_washall();
};

void Graph::floyd_washall()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((adj[i][k] * adj[k][j] != 0) && (i != j))
                {
                    if ((adj[i][k] + adj[k][j] < adj[i][j]) || (adj[i][j] == 0))
                    {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nMinimum Cost With Respect to Node " << i <<" :" << endl;
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Name: Aditya Mitra" << endl;
    cout << "Reg. No. 20BCE2044\n" << endl;

    Graph g;
    
    cout << "Enter the number of nodes: ";
    cin >> g.n;

    g.adj = new int *[g.n];

    cout << "\nEnter Adjacency Matrix" << endl;
    for (int i = 0; i < g.n; i++)
    {
        g.adj[i] = new int[g.n];
        cout << "Enter values for Row " << i + 1 << " :" << endl;
        for (int j = 0; j < g.n; j++)
        {
            cin >> g.adj[i][j];
        }
        cout << endl;
    }

    g.floyd_washall();
}