#include <bits/stdc++.h>
using namespace std;
int par[1005];
int find(int node)
{
    if (par[node] == -1) // if node is root
    {                    //
        return node;     // return node
    }
    int leader = find(par[node]); // find the leader of the node's parent
    par[node] = leader; // update the node's parent
    return leader;
}
int main()
{
    memset(par, -1, sizeof(par)); // Initialize all elements of par[] as -1
    par[0] = 1;
    par[1] = -1;
    par[2] = 1;
    par[3] = 1;
    par[4] = 5;
    par[5] = 3;

    cout << find(4) << endl;
    for( int i = 0; i < 6; i++){
        cout << i << " ->"<<par[i]<<endl;;
    }
    return 0;
}