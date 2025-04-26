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
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.pb(x);
	}
	int x, c = 0;
	cin >> x;
	for(auto it = v.begin(); it != v.end(); it++) {
		if(*it == x) {
			v.erase(it);
			c++;
			it--;
		}
	}
	// cout << c << ln;
	for(auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
}

int main() {
	fast_cin();
	solve();
	return 0;
}