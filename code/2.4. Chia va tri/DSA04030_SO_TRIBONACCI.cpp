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
using mt = vector<vll>;
const ll MOD = 1e15+7, n = 4;

// ll nhan(ll a, ll b) {
//     ll res = 0;
//     a %= MOD;
//     while (b > 0) {
//         if (b & 1) res = (res + a) % MOD;
//         a = (a + a) % MOD;
//         b >>= 1;
//     }
//     return res;
// }

mt operator*(mt a, mt b) {
	mt res(a.size(), vll(b.size(), 0));
	for(int i = 0; i < a.size(); i++) {
		for(int j = 0; j < b.size(); j++) {
			ll tmp = 0;
			for(int k = 0; k < b[0].size(); k++) {
				// tmp = (tmp%MOD + nhan(a[i][k]%MOD, b[k][j]%MOD))%MOD;
				tmp += a[i][k]*b[k][j];
			}
			res[i][j] = tmp%MOD;
		}
	}
	return res;
}

mt powerm(mt a, ll k) {
	mt res(n, vll(n, 0));
	for(int i= 0; i < n; i++) res[i][i] = 1;
	while(k > 0) {
		if(k%2==1) res = res*a;
		a = a*a;
		k /= 2;
	}
	return res;
}

ll tongTribonacci(ll k) {
	if(k <= 3) return k*(k+1)/2;
	mt base = {
		{1, 1, 1, 0},
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{1, 1, 1, 1}
	};
	mt v3 = {{3}, {2}, {1}, {6}};
	mt res = powerm(base, k-3)*v3;
	return res[3][0];
}

void solve() {
	ll k; cin >> k;
	cout << tongTribonacci(k) << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}