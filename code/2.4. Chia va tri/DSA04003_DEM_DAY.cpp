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
ll MOD = 123456789;
ll poww(ll n, ll k) {
	if(k == 0) return 1;
	ll t = poww(n, k/2);
	if(k%2==0) return (t*t)%MOD;
	else return ((t*t)%MOD*n)%MOD;
}
void solve() {
	ll n; cin >> n;
	cout << poww(2, n-1) << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}