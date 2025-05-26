#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vii = vector<pii>;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ln "\n"

void solve() {
	int n; cin >> n;
	vi a(n); for(int i = 0; i < n; i++) cin >> a[i];
	map<int, int> dp;
	int maxLen = 0;
	for(int i = 0; i < n; i++) {
		dp[a[i]] = dp[a[i]-1]+1;
		maxLen = max(maxLen, dp[a[i]]);
	}
	// for(auto it:dp) cout << it.fi << " " << it.se << ln;
	cout << n-maxLen << ln;
	// cout << ln;
}

int main() {
	fast_cin();
	ll t = 1;
	// cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}