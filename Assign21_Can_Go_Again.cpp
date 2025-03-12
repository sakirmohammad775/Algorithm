#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;
int dis[1005];
int n, e;

bool bellman_ford(int s)
{
    for (int i = 0; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[s] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool updated = false;
        for (auto ed : edge_list)
        {
            int a = ed.a, b = ed.b, c = ed.c;
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
                updated = true;
            }
        }
        if (!updated)
            break;
    }

    for (auto ed : edge_list)
    {
        if (dis[ed.a] != INT_MAX && dis[ed.a] + ed.c < dis[ed.b])
        {
            cout << "Negative Cycle Detected\n";
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> e;
    edge_list.clear();

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    int s;
    cin >> s;

    if (!bellman_ford(s))
        return 0;
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        if (dis[d] == INT_MAX)
            cout << "Not Possible\n";
        else
            cout << dis[d] << "\n";
    }

    return 0;
}
