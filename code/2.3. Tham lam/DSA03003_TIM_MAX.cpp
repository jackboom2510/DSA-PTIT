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
void solve() {
	ll n, s = 0; cin >> n;
	vector<ll> a(n);
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	sort(all(a));
	// sort(a.begin()+1, a.end(), greater<ll>());
	for(ll i = 0; i < n; i++)
		s += a[i]*i%MOD;
	cout << s%MOD << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}