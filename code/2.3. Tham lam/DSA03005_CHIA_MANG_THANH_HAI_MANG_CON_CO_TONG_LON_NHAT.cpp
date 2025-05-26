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
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++)	cin >> v[i];
	sort(all(v));
	ll M = 0, m = 0;
	if(n-k>k) k = n-k;
	for(int i = 0; i < n; i++) {
		if(i < n-k) m += v[i];
		else M += v[i];
	}
	// cout << M << " " << m << " ";
	cout << M-m << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}