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

int isGreedySorted(vector<int> a, int n) {
	vector<int> b = a;
	sort(all(b));
	for(int i = 0; i < n; i++) {
		if(a[i] != b[i] && a[i] != b[n-1-i]) return 0;
	}
	return 1;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	if(isGreedySorted(a, n)) cout << "Yes" << ln;
	else cout << "No" << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}