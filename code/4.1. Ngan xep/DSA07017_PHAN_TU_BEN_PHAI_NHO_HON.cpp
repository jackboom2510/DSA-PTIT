#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define debug(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define cbit(mask, i) (mask & (1 << i))
#define sbit(mask, i) (mask | (1 << i))
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ln "\n"

void solve() {
	int n; cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	stack<int> g, s;
	vi gr(n, -1), sm(n, -1);
	for(int i = 0; i < n; i++) {
		while(!g.empty() && a[i] > a[g.top()]) {
			gr[g.top()] = i;
			g.pop();
		}
		while(!s.empty() && a[i] < a[s.top()]) {
			sm[s.top()] = i;
			s.pop();
		}
		g.push(i);
		s.push(i);
	}
	// for(int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }
	// cout << ln;
	// for(int i = 0; i < n; i++) {
	// 	cout << gr[i] << " ";
	// }
	// cout << ln;
	// for(int i = 0; i < n; i++) {
	// 	cout << sm[i] << " ";
	// }
	// cout << ln << ln;
	for(int i = 0; i < n; i++) {
		if(gr[i] != -1 && sm[gr[i]] != -1) cout << a[sm[gr[i]]] << " ";
		else cout << -1 << " ";
	}
	cout << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it = 1; it <= t; it++)
		solve();
	return 0;
}