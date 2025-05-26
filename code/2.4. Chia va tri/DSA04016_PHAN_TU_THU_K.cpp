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
	int n, m, k; cin >> n >> m >> k;
	k--;
	vi a(n), b(m), c;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		c.pb(a[i]);
	}
	for(int i = 0; i < m; i++) {
		cin >> b[i];
		c.pb(b[i]);
	}
	sort(all(c));
	cout << c.at(k) << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}