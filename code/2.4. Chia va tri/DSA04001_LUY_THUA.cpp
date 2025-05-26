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
ll MOD = 1e9+7;
ll power(int x, int n) {
	if(n == 0) return 1;
	ll t = power(x, n/2);
	if(n%2==0) return (t*t)%MOD;
	return ((t*t)%MOD*x)%MOD;
}

void solve() {
	int x, n; cin >> x >> n;
	cout << power(x, n)<< ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}