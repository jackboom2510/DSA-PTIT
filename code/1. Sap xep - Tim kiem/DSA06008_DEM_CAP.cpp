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

int count(int x, vi y, int n, vi a) {
	if(x == 0) return 0;
	if(x == 1) return a[0];
	int res = n - (upper_bound(all(y), x)-y.begin());
	res += a[0] + a[1];
	if(x == 2) res -= a[3]+a[4];
	if(x == 3) res += a[2];
	return res;
}

void solve() {
	int n, m; cin >> n >> m;
	vi x(n), y(m), a(5, 0);
	for(int i = 0; i < n; i++) cin >> x[i];
	for(int i = 0; i < m; i++) {
		cin >> y[i];
		if(y[i] < 5) a[y[i]]++;
	}
	sort(all(y));
	int res = 0;
	for(int i = 0; i < n; i++)
		res += count(x[i], y, m, a);
	cout << res << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}