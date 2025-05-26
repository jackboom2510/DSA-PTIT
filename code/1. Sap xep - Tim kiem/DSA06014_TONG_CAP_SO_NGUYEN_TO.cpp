#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) x.begin(), x.end()
#define cbit(mask, i) (mask & (1 << i))
#define sbit(mask, i) (mask | (1 << i))
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ln "\n"

bool isPrime(int n) {
	if(n < 2) return false;
	if(n != 2 && n%2 == 0) return false;
	for(int i = 3; i <= sqrt(n); i += 2)
		if(n%i == 0) return false;
	return true;
}

void solve() {
	int n; cin >> n;
	for(int i = 2; i <= n/2; i++) {
		if(isPrime(i) && isPrime(n-i)) {
			cout << i << " " << n-i << ln;
			return;
		}
	}
	cout << -1 << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}