#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool check(string a)
{
    int n = a.size();
    if (a[0] != 'H' || a[n - 1] != 'A')
        return 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == 'H' && a[i + 1] == 'H')
            return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a;
        for (int i = 0; i < n; i++)
            a += 'A';
        while (1)
        {
            if (check(a))
                cout << a << endl;
            int ok = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] == 'A')
                {
                    ok = 1;
                    a[i] = 'H';
                    for (int j = i + 1; j < n; j++)
                        a[j] = 'A';
                    break;
                }
            }
            if (ok == 0)
                break;
        }
    }
}w