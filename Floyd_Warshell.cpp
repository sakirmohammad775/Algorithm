#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) // adjacency matrix 
        {
            if (i == j) // diagonal elements
            {
                adj_mat[i][j] = 0; // self loop
            }
            else
            {
                adj_mat[i][j] = INT_MAX;
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
    return 0;
}