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
	int n; cin >> n;
	int a[n], p[n], c[n], l[n], indexc = 0, indexl = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(a[i] % 2 == 0) {
			c[indexc++] = a[i];
			p[i] = 0;
		}
		else {
			l[indexl++] = a[i];
			p[i] = 1;
		}
	}
	sort(c, c+indexc);
	sort(l, l+indexl, greater<int>());
	// for(int i = 0; i < indexc; i++) {
	// 	cout << c[i] << " ";
	// }
	// cout << ln;
	// for(int i = 0; i < indexl; i++) {
	// 	cout << l[i] << " ";
	// }
	cout << ln;
	int i = 0, j = 0;
	for(int index = 0; index < n; index++) {
		if(p[index] == 1) {
			cout << l[i++] << " ";
		}
		else {
			cout << c[j++] << " ";
		}
	}
}

int main() {
	fast_cin();
	solve();
	return 0;
}