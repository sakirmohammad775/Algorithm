#include <bits/stdc++.h>
using namespace std;

vector<int>adj[1005];

int main() {
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    for(int i = 0; i <= n; i++) {
        sort(adj[i].rbegin(),adj[i].rend());
    }
    int q;
    cin >> q;
    while(q--){
        int p;
        cin >> p;
        if(adj[p].empty()){
            cout<<"-1\n";
        }
        else{
            for( int i:adj[p]){
                cout<<i<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}