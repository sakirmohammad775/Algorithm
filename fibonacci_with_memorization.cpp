#include <bits/stdc++.h>
using namespace std;
long long int dp[1005]; //  0(N)
int fibonacci(long long int n)
{
    if (n < 2)
        return n;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return dp[n];
}
int main()
{
    memset(dp,-1,sizeof(dp)); // 
    long long int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}