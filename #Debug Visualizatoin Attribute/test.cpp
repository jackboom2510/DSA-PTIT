#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) x.begin(), x.end()
#define cbit(mask, i) (mask & (1 << i))
#define sbit(mask, i) (mask | (1 << i))
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ln "\n"

string pt = "+-*/";
int isPT(char c) {
    return pt.find(c);
}

bool isNumber(const string& s) {
    for (char c : s) {
        if (!isdigit(c) && c != '-' && c != '+') {
            return false;
        }
    }
    return !s.empty();
}

int calc(ll n1, ll n2, char c) {
    switch(c) {
        case '+':
            return n1+n2;
        case '-':
            return n1-n2;
        case '*':
            return n1*n2;
        case '/':
            return n1/n2;
    }
    return 0;
}

void solve() {
    int n; cin >> n;
    cin.ignore();
    stack<ll> st;
    string s;
    ll n1, n2;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(isPT(s[0]) != -1 && s.size() == 1) {
            n2 = st.top(); st.pop();
            n1 = st.top(); st.pop();
            st.push(calc(n1, n2, s[0]));
        }
        else {
            if(isNumber(s))
                st.push(stoll(s));
        }
    }
    cout << st.top() << ln;
}

int main() {
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++)
        solve();
    return 0;
}