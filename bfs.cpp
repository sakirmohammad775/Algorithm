#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

void bfs(int src)
{
    queue<int> q; // take a queue  
    q.push(src); //pussh source code in queue
    vis[src] = true; // mark source node as visited 

    while (!q.empty()) // while queue is not empty
    {
        // get front element of queue
        int par = q.front(); 
        q.pop();

        // print the element of queue
        cout << par << " ";

        // Dequeue
        for (int child : adj_list[par])
        {
            if (vis[child] == false)
            {

                q.push(child);
                vis[child] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    ;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    bfs(0);

    return 0;
}