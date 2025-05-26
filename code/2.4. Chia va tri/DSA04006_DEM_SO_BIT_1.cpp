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

ll Try(ll n, ll k, ll mid) {
	if(k&1) return 1;
	if(k == mid) return n%2;
	if(k > mid) return Try(n/2, k-mid, mid/2);
	else return Try(n/2, k, mid/2);
}

void solve() {
	ll n, L, R; cin >> n >> L >> R;
	ll mid = 1ll << ((ll)log2(n)), ans = 0;
	// ll mid = pow(2, (ll)log2(n)), ans = 0;
	for(ll i = L; i <= R; i++) {
		// if(!(i%4)) cout << " ";
		// cout << Try(n, i, mid);
		// if(!(i%4)) cout << " ";
		ans += Try(n, i, mid);
	}
	cout << ans << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}