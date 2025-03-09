#include <bits/stdc++.h>
using namespace std;
char grid[1001][1001];
bool vis[1001][1001];
int distance[1001][1001];
pair<int,int>parent[1001][1001];

void bfs(int si,int sj){
    vis[si][sj]=true;
    dist [si][sj]=0;
}
int main() {
    int n,m;
    cin>>n>>m;
    int si,sj,di,dj;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A'){
                si=i;
                sj=j;
            }
            if(grid[i][j]=='B'){
                di=i;
                dj=j;
            }
        }
    }
    memset(vis,false,sizeof(vis));
    memset(distance,0,sizeof(distance));
    bfs(si,sj);
    return 0;
}