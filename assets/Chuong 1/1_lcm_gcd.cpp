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

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int lcm(int a, int b) {
	return a*b/gcd(a, b);
}

void solve() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << " " << lcm(a, b) << endl;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}