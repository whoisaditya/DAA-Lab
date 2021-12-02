// Ford-Fulkerson algorith in C++

#include <limits.h>
#include <string.h>

#include <iostream>
#include <queue>
using namespace std;

class Graph
{
public:
    int n;
    int s;
    int t;
    int **adj;
    int **r_adj;

    int ford_fulkerson();
    bool bfs(int *parent);
};

// Using BFS as a searching algorithm
bool Graph::bfs(int *parent)
{
    bool visited[n];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        for (int j = 0; j < n; j++)
        {
            if (visited[j] == false && r_adj[i][j] > 0)
            {
                q.push(j);
                parent[j] = i;
                visited[j] = true;
            }
        }
    }

    return (visited[t] == true);
}

// Applying ford_fulkerson algorithm
int Graph::ford_fulkerson()
{
    r_adj = new int *[n];

    for (int i = 0; i < n; i++)
    {
        r_adj[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            r_adj[i][j] = adj[i][j];
        }
    }

    int *parent = new int[n];
    int max_flow = 0;

    // Updating the residual values of edges
    while (bfs(parent))
    {
        int path_flow = INT_MAX;

        for (int j = t; j != s; j = parent[j])
        {
            int i = parent[j];
            path_flow = min(path_flow, r_adj[i][j]);
        }

        for (int j = t; j != s; j = parent[j])
        {
            int i = parent[j];
            r_adj[i][j] -= path_flow;
            r_adj[j][i] += path_flow;
        }

        // Adding the path flows
        max_flow += path_flow;
    }

    return max_flow;
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

    cout << "\nEnter the source and sink nodes: ";
    cin >> g.s >> g.t;

    cout << "\nMax Flow: " << g.ford_fulkerson() << endl;
}