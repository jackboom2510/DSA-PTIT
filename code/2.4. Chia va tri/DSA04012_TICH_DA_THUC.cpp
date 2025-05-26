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

vi tichDaThuc(vi a, vi b) {
	int n = a.size(), m = b.size();
	int sz = n+m-1;
	vi res(sz, 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
		res[i+j] += a[i]*b[j];
	}
	return res;
}

void printDaThuc(vi a) {
	for(auto i:a) cout << i << " ";
	cout << ln;
}

void solve() {
	int n, m; cin >> n >> m;
	vi a(n), b(m);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	printDaThuc(tichDaThuc(a, b));
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}