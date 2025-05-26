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

template <typename Iterator>
Iterator advanceit(Iterator it, int n) {
	advance(it, n);
	return it;
}

void solve() {
	int n, k; cin >> n >> k;
	int a[n], ans = 0;
	map<int, int> m;
	for(int i = 0; i < n; i++) {
		bool mark = 1;
		cin >> a[i];
		m[a[i]]++;
	}
	for(auto &it:m) {
		auto i = lower_bound(, m.end(), k-it.fi);
	}
	cout << ans << ln;
}
	
int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}