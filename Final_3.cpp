#include <bits/stdc++.h>
using namespace std;

bool reach(int N)
{
    if (N == 1)
        return true;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        int add3 = current + 3;
        int mul2 = current * 2;
        if (add3 == N || mul2 == N)
        {
            return true;
        }
        if (add3 < N)
        {
            q.push(add3);
        }
        if (mul2 < N)
        {
            q.push(mul2);
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (reach(n) ? "YES" : "NO") << endl;
    }
    return 0;
}