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
#define int long long
void solve() {
	int n; cin >> n;
	vi a(n+1);
	stack<int> st;
	for(int i = 0; i < n; i++) cin >> a[i];
	a[n] = 0;
	ll maxArea = 0;
	for(int i = 0; i <= n; i++) {
		while(!st.empty() && a[i] < a[st.top()]) {
			int h = a[st.top()];
			st.pop();
			int w = st.empty() ? i : i-st.top()-1;
			maxArea = max(maxArea, h*w);
		}
		st.push(i);
	}
	cout << maxArea << ln;
}

int32_t main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it = 1; it <= t; it++)
		solve();
	return 0;
}