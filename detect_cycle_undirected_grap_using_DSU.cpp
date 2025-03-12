#include <bits/stdc++.h>
using namespace std;
int par[1005];
int group_size[1005];
int find(int node)
{
    if (par[node] == -1) // if node is root
    {                    //
        return node;     // return node
    }
    int leader = find(par[node]); // find the leader of the node's parent
    par[node] = leader;           // update the node's parent
    return leader;
}
void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;                     // make leader1 the parent of leader2
        group_size[leader1] += group_size[leader2]; // update the group size of leader1
    }
    else
    {
        par[leader1] = leader2;                     // make leader2 the parent of leader1
        group_size[leader2] += group_size[leader1]; // update the group size of leader
    }
}
int main()
{
    memset(par, -1, sizeof(par));              // Initialize all elements of par[] as -1
    memset(group_size, 1, sizeof(group_size)); // Initialize all elements of group_size[] as 1
    int n, e;
    cin >> n >> e;
    bool cycle = false;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);
        if (leaderA == leaderB) // if a and b are already in the same group
        {
            cycle = true;
        }
        else
        {
            dsu_union(a, b); // 
        }
    }
    if (cycle)
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle detected" << endl;
    return 0;
}