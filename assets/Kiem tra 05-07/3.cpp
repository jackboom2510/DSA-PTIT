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
const int s = 2;

void solve() {
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	vll a(s), b(s);
	ll ms = INT_MAX, Ms = INT_MIN;
	for(int i = 0; i < s; i++) {
		cin >> a[i] >> b[i];
		ms = min(ms, a[i]);
		Ms = max(Ms, b[i]);
	}
	for(int i )
}
N X Y Z
A1 

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}