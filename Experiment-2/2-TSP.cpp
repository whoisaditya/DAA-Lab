// CPP program to implement traveling salesman
// problem using naive approach.

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
class Graph
{
public:
    // Number of vertex
    int v;

    // Number of edges
    int e;

    // Adjacency matrix
    int **adj;

    // To create the initial adjacency matrix
    Graph(int v, int e);

    // Function to insert a new edge
    void add_edge(int start, int e, int i);

    int travlling_salesman_problem(int s);
};

// Function to fill the empty adjacency matrix
Graph::Graph(int v, int e)
{
    this->v = v;
    this->e = e;
    adj = new int *[v];
    for (int row = 0; row < v; row++)
    {
        adj[row] = new int[v];
        for (int column = 0; column < v; column++)
        {
            adj[row][column] = 0;
        }
    }
}

// Function to add an edge to the adj
void Graph::add_edge(int start, int e, int i)
{
    // Considering a bidirectional edge
    adj[start][e] = i;
    adj[e][start] = i;
}

// Implementation of traveling Salesman Problem
int Graph::travlling_salesman_problem(int s)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < v; i++)
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

// Driver Code
int main()
{
    // matrix representation of graph
    int s = 0;

    int v = 0, e = 0, ch;

    cout<<"Aditya Mitra 20BCE2044\n" << endl;

    while (true)
    {
        cout << "\nMenu\n1. Create your own graph\n2. Use the sample graph\n3. Exit\nYour choice: ";
        cin >> ch;
        cout << "\n";

        switch (ch)
        {
        case 1:
        {
            cout << "Enter Graph Details: " << endl;

            cout << "No. of Vertices : ";
            cin >> v;

            cout << "No. of Edges : ";
            cin >> e;

            // Create the graph
            Graph G(v, e);
            int x, y, z;

            cout << endl;
            for (int j = 0; j < e; j++)
            {
                
                cout << "Edge " << (j+1) << ":" << endl;
                cout << "Starting Node: ";
                cin >> x;

                cout << "Ending Node: ";
                cin >> y;

                cout << "Weight: ";
                cin >> z;

                cout << endl;
                G.add_edge(x, y, z);
            }

            cout << "Adjadency matrix" << endl;

            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < e; j++)
                {
                    cout << G.adj[i][j] << " ";
                }
                cout << endl;
            }

            cout << "\nSolution:" << G.travlling_salesman_problem(s) << endl;

            break;
        }

        case 2:
        {
            v = 4;
            e = 4;

            Graph G(v, e);

            G.add_edge(0, 1, 10);
            G.add_edge(1, 2, 20);
            G.add_edge(2, 3, 40);
            G.add_edge(3, 0, 30);

            cout << "Adjadency matrix" << endl;

            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < e; j++)
                {
                    cout << G.adj[i][j] << " ";
                }
                cout << endl;
            }

            cout << "\nSolution:" << G.travlling_salesman_problem(s) << endl;

            break;
        }

        case 3:
        {
            exit(0);
            break;
        }
        }
    }
}