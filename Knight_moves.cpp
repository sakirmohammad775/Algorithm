#include <bits/stdc++.h>
using namespace std;
char grid[8][8];
bool vis[8][8];
int level[8][8];
vector<pair<int, int>> d = { {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
{2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
int n,m;
bool valid(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
    {
        return false;
    }
    if (grid[i][j] != '.')
    {
        return false;
    }
    if (vis[i][j])
    {
        return false;
    }
    return true;
}
void bfs(int si,int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    while(!q.empty()){
        pair<int,int>par=q.front();
        q.pop();
        int par_i=par.first;
        int par_j=par.second;
        for(int i=0;i<8;i++){
            int ci=par_i+d[i].first;
            int cj=par_j+d[i].second;
            if(valid(ci,cj)&& !vis[ci][cj]&&grid[ci][cj]=='.'){
                q.push({ci,cj});
                vis[ci][cj]=true;
                level[ci][cj]=level[par_i][par_j]+1;
            }
        }
    }
}
int main() {
    n=8,m=8;
    int t;cin>>t;
while(t--){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    cout<<si<<" "<<sj<<" "<<di<<" "<<dj<<endl;
    memset( vis, false, sizeof (vis) );
    memset( level, -1, sizeof (level) );
    bfs(si,sj);
}
    
    return 0;
}