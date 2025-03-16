#include <iostream>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1 || n == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    if (n == 3)
    {
        cout << 2 << endl;
        return 0;
    }

    long long int T0 = 0, T1 = 1, T2 = 1, T3 = 2, Tn;
    for (int i = 4; i <= n; i++)
    {
        Tn = T0 + T1 + T2 + T3;
        T0 = T1;
        T1 = T2;
        T2 = T3;
        T3 = Tn;
    }

    cout << Tn << endl;
    return 0;
}
