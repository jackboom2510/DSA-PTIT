#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
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
        vector<int> a(n + 1);
        vector<vector<int>> b;
        for (int i = 1; i <= n; i++)
            a[i] = i;
        while (1)
        {
            b.push_back(a);
            int ok = 0;
            for (int i = n - 1; i >= 1; i--)
            {
                if (a[i] < a[i + 1])
                {
                    ok = 1;
                    sort(a.begin() + i + 1, a.end());
                    for (int j = i + 1; j <= n; j++)
                        if (a[j] > a[i])
                        {
                            swap(a[i], a[j]);
                            break;
                        }
                    break;
                }
            }
            if (ok == 0)
                break;
        }
        for(int i=1;i<=n;i++) cout<<b[b.size()-1][i];
        for(int i=b.size()-2;i>=0;i--){
        	cout<<",";
        	for(int j=1;j<=n;j++) cout<<b[i][j];
		}
		cout<<endl;
    }
}