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
const ll MOD = 1e9+7;
void solve() {
	ll n; cin >> n;
	vll a(n);
	for(ll i = 0; i < n; i++) cin >> a[i];
	priority_queue<ll, vll, greater<ll>> pq(all(a));
	ll res = 0;
	while(pq.size() > 1) {
		ll first = pq.top(); pq.pop();
		ll second = pq.top(); pq.pop();
		ll s = (first+second)%MOD;
		res = (res+s)%MOD;
		pq.push(s);
	}
	cout << res << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}