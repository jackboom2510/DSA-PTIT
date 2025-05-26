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

void max

void solve() {
	int n, m; cin >> n >> m;
	vector<vi> a(n, vi(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	int maxArea = 0;
	vi h(m, 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			h[j] = (a[i][j] == 0) ? 0 : h[j]+1;
		}
	}
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it = 1; it <= t; it++)
		solve();
	return 0;
}