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
	int n, m, h; cin >> n >> m >> h;
	vector<ll> a(n), b(m), c(h);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int j = 0; j < m; j++) cin >> b[j];
	for(int k = 0; k < h; k++) cin >> c[k];
	vector<ll> res;{}
	int i = 0, j = 0, k = 0;
	while(i < n && j < m && k < h) {
		if(a[i] == b[j] && a[i] == c[k]) {
			int val = a[i];
			res.pb(val);
			i++; j++; k++;
		}
		else {
			ll minv = min({a[i],  b[j], c[k]});
			if(i < n && a[i] == minv) i++;
			if(j < m && b[j] == minv) j++;
			if(k < h && c[k] == minv) k++;
		}
	}
	if(res.empty()) cout << "NO";
	else
		for(auto it:res) cout << it << " ";
	cout << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}