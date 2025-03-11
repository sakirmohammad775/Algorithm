#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e, q;
    cin >> n >> e >> q;
    long long int adj_mat[n+5][n+5]; // adjacency matrix
    for (int i = 1; i <= n; i++)  // initialize adjacency matrix
    {
        for (int j = 1; j <= n; j++) // adjacency matrix
        {
            if (i == j) // diagonal elements
            {
                adj_mat[i][j] = 0; // self loop
            }
            else
            {
                adj_mat[i][j] = LLONG_MAX; // infinity
            }
        }
    }

    while (e--)
    {
        long long int a, b, c;
        cin >> a >> b >> c; // input edge
        adj_mat[a][b] =min(adj_mat[a][b], c);  // directed graph
        adj_mat[b][a] = min(adj_mat[a][b], c);  // undirected graph
    }

    for (int k = 1; k <= n; k++) //  floyd warshall algorithm
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX &&
                    adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    while (q--)
    {
        int s, d;
        cin >> s >> d; // input source and destination with query
        if (adj_mat[s][d] == LLONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {

            cout << adj_mat[s][d] << endl;
        }
    }

    return 0;
}