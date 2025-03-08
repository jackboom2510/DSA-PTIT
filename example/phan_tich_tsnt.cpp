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

void solve() {
	int n, c;
	cin >> n;
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			c = 0;
			while(n % i == 0) {
				c++;
				n /= i;
			}
			cout << i << "(" << c << ") ";
		}
	}
	if(n != 1) cout << n << "(1)";
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++) {
		cout << "Test " << it << ": ";
		solve();
		cout << ln;
	}
	return 0;
}