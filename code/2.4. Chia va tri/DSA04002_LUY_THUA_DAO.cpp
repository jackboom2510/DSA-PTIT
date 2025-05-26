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
ll poww(ll n, ll k) {
	if(k == 0) return 1;
	ll x = poww(n, k/2);
	if(k%2==0) return (x*x)%MOD;
	else return ((x*x)%MOD*n)%MOD;
}

void solve() {
	ll n; cin >> n;
	ll m = n, k = 0;
	while(m!=0) {
		k = k*10+m%10;
		m /= 10;
	}
	cout << poww(n, k) << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}