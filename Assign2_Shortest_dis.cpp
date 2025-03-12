#include <bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;
long long dist[101][101];

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], (long long)c);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) { 
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF)
            cout << "-1\n";
        else
            cout << dist[a][b] << "\n";
    }

    return 0;
}
