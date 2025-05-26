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

bool cmp(pii a, pii b) {
	if(a.se != b.se) return a.se < b.se;
	return a.fi < b.fi;
}

void solve() {
	int n; cin >> n;
	vector<pii> dt(n);
	for(int i = 0; i < n; i++) cin >> dt[i].fi >> dt[i].se;
	sort(all(dt), cmp);
	int cnt = 1, ht = dt[0].se;
	for(int i = 1; i < n; i++) {
		if(dt[i].fi < ht) continue;
		ht = dt[i].se;
		cnt++;
	}
	cout << cnt << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}