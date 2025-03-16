
#include <bits/stdc++.h>
using namespace std;

long long int dp[1005];

int tetra(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (n == 3)
        return 2;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = tetra(n - 1) + tetra(n - 2) + tetra(n - 3) + tetra(n - 4);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << tetra(n) << endl;
    return 0;
}
