#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool Var(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s, k;
        cin >> s;
        stack<string> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (Var(s[i]))
                st.push(string(1, s[i]));
            else
            {
                k = st.top();
                st.pop();
                k = s[i] + k;
                k = st.top() + k;
                st.pop();
                st.push(k);
            }
        }
        cout << st.top() << endl;
    }
}