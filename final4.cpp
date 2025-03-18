#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int max_weight, vector<int> &weights, vector<int> &values)
{
    vector<vector<int>> dp(n + 1, vector<int>(max_weight + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= max_weight; w++)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][max_weight];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, max_weight;
        cin >> n >> max_weight;
        vector<int> weights(n), values(n);
        for (int i = 0; i < n; i++)
            cin >> weights[i];
        for (int i = 0; i < n; i++)
            cin >> values[i];
        cout << knapsack(n, max_weight, weights, values) << endl;
    }

    return 0;
}
