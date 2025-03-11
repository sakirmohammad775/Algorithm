#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];          // adjacency matrix
    for (int i = 0; i < n; i++) // initialize adjacency matrix
    {
        for (int j = 0; j < n; j++) // adjacency matrix
        {
            if (i == j) // diagonal elements
            {
                adj_mat[i][j] = 0; // self loop
            }
            else
            {
                adj_mat[i][j] = INT_MAX; // infinity
            }
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c; // directed graph
        // adj_mat[b][a] = c; undirected graph
    }

    for (int k = 0; k < n; k++) //  floyd warshall algorithm
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX &&
                    adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    bool cycle = false; // check for negative weight cycle
    for (int i = 0; i < n; i++)
    {
        if (adj_mat[i][i] < 0)
        {
            cycle = true;
        }
    }
    if (cycle)
    {
        cout << "Graph contains negative weight cycle" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj_mat[i][j] == INT_MAX)
                {
                    cout << "INF" << " ";
                }
                else
                {

                    cout << adj_mat[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}