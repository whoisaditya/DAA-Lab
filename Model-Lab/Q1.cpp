#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class Graph
{
public:
    int n;
    int **adj;

    int travlling_salesman_problem(int);
};

// Implementation of traveling Salesman Problem
int Graph::travlling_salesman_problem(int s)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < n; i++)
    {
        if (i != s)
        {
            vertex.push_back(i);
        }
    }

    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do
    {
        // store current Path weight(cost)
        int current_pathweight = 0;

        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            current_pathweight += adj[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += adj[k][s];

        // update minimum
        min_path = min(min_path, current_pathweight);

    } while (
        next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

int main()
{
    cout << "Name: Aditya Mitra" << endl;
    cout << "Reg. No. 20BCE2044\n"
         << endl;

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

    cout << "Minimum Cost: " << g.travlling_salesman_problem(0);
}