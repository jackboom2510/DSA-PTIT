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

int n, m, c;
vector<vector<int>> a;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}};
void Try(int i, int j) {
	if(i == n-1 && j == m-1) {
		c++;
		return;
	}
	for(int k = 0; k <= 1; k++) {
		int u = i+dir[k].fi;
		int v = j+dir[k].se;
		if(u >= 0 && v >= 0 && u <= n-1 && v <= m-1)
			Try(u, v);
	}
}
void solve() {
	c = 0;
	cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; i++) {
		a[i].resize(m);
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	Try(0, 0);
	cout << c << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}