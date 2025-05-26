#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define debug(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define cbit(mask, i) (mask & (1 << i))
#define sbit(mask, i) (mask | (1 << i))
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ln "\n"

void solve() {
    int n; cin >> n;
    vi a(n), l(n), r(n);
    // l[n], r[n] là các biên trong (inclusive) của 
    stack<int> st;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        // Loại bỏ các phần tử trong stack >= chiều cao hiện tại
        while(!st.empty() && a[st.top()] >= st.top()) {
            st.pop();
        }
        if(st.empty()) {
            l[i] = 0;
        }
        else {
            l[i] = st.top() + 1;
        }
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n-1; i >= 0; i--) {
        // Loại bỏ các phần tử trong stack >= chiều cao hiện tại
        while(!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if(st.empty()) {
            r[i] = n-1;
        }
        else {
            r[i] = st.top() - 1;
        }
        st.push(i);
    }
    int maxSide = 0;
    for(int i = 0; i < n; i++) {
        if(r[i] - l[i] + 1 >= a[i]) {
            maxSide = max(maxSide, a[i]);
        }
    }
    cout << maxSide << ln;
}

int main() {
    fast_cin();
    ll t;
    cin >> t;
    for(int it = 1; it <= t; it++)
        solve();
    return 0;
}