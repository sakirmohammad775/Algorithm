#include <bits/stdc++.h>
using namespace std;

bool vis[1005][1005];

int main()
{
    int n, m;
    cin >> n >> m;
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        vis[u][v] = true;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << "YES\n";
        }
        else if (vis[a][b])
        {

            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}