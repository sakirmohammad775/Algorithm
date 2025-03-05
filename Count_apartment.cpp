#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    if (vis[i][j])
    {
        return false;
    }
    if (grid[i][j]=='#')
    {
        return false;
    }
    return true;
}
void bfs(int si,int sj){
    queue<pair<int,int>>q;
    q.push({si,sj});
    vis[si][sj]=true;
    while(!q.empty()){
        auto [par_i,par_j]=q.front();
        q.pop();
        for( int i=0;i<4;i++){
            int ci=par_i+d[i].first;
            int cj=par_j+d[i].second;
            if(valid(ci,cj)){
                q.push({ci,cj});
                vis[ci][cj]=true;
            }
        }
    }
}
int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                bfs(i, j);
                count++;
            }
        }
    }

    cout << count << "\n";
    return 0;
}