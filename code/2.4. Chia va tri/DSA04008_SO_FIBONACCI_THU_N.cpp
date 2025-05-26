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
vector<vll> operator*(vector<vll> a, vector<vll> b) {
	vector<vll> res(2, vll(2, 0));
	res[0][0] = (a[0][0]*b[0][0]%MOD + a[0][1]*b[1][0]%MOD)%MOD;
	res[0][1] = (a[0][0]*b[0][1]%MOD + a[0][1]*b[1][1]%MOD)%MOD;
	res[1][0] = (a[1][0]*b[0][0]%MOD + a[1][1]*b[1][0]%MOD)%MOD;
	res[1][1] = (a[1][0]*b[0][1]%MOD + a[1][1]*b[1][1]%MOD)%MOD;
	return res;
}

vector<vll> powm(vector<vll> a, int n) {
	vector<vll> res = {{1, 0,}, {0, 1}};
	while(n > 0) {
		if(n%2 == 1) {
			res = res*a;
		}
		a = a*a;
		n /= 2;
	}
	return res;
}

ll fibo(ll n) {
	if(n == 0) return 0;
	vector<vll> a = {{1, 1}, {1, 0}};
	vector<vll> res = powm(a, n-1);
	return res[0][0];
}

void solve() {	
	ll n; cin >> n;
	cout << fibo(n) << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}