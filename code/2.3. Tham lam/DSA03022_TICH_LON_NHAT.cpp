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
	int n, x; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(all(a));
	ll maxP = max({
		a[n-1]*a[n-2],
		a[n-1]*a[n-2]*a[n-3],
		a[0]*a[1],
		a[0]*a[1]*a[n-1]
	});
	cout << maxP << ln;
}

int main() {
	fast_cin();
	solve();
	return 0;
}