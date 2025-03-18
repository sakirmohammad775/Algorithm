#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.length() != s2.length())
        {
            cout << "NO" << endl;
            continue;
        }
        vector<int> frq1(26, 0);
        vector<int> frq2(26, 0);
        for (char ch : s1)
        {
            frq1[ch - 'a']++;
        }
        for (char ch : s2)
        {
            frq2[ch - 'a']++;
        }
        if (frq1 == frq2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
