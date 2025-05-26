#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vii = vector<pii>;
using mt = vector<vll>;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ln "\n"

const ll MOD = 1e9+7;
mt operator*(mt a, mt b) {
	int n = a.size();
	mt res(n, vll(n ,0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				res[i][j] += a[i][k]*b[k][j]%MOD;
			}
			res[i][j] %= MOD;
		}
	}
	return res;
}

mt powerm(mt a, ll n) {
	int sz = a.size();
	mt res(sz, vll(sz, 0));
	for(int i = 0; i < sz; i++) res[i][i] = 1;
	while(n > 0) {
		if(n%2==1) {
			res = res*a;
		}
		a = a*a;
		n /= 2;
	}
	return res;
}

void printmt(mt a) {
	int sz = a.size();
	for(int i = 0; i < sz; i++) {
		for(int j = 0; j < sz; j++) cout << a[i][j] << " ";
		cout << ln;
	}
}

void solve() {
	ll n, k; cin >> n >> k;
	mt a(n, vll(n, 0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) cin >> a[i][j];
	printmt(powerm(a, k));
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}