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

ll find(ll n, ll k) {
	if(n == 1) return 1;
	ll mid = (1ll << (n-1));
	if(mid == k) return n;
	else if(k > mid) return find(n-1, k-mid);
	else return find(n-1, k);
}

void solve() {
	ll n, k; cin >> n >> k;
	cout << find(n, k) << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}