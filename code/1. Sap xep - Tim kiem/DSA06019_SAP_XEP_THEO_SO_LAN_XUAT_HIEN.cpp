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

bool cmp(pii a, pii b) {
	return a.se > b.se || (a.se == b.se && a.fi < b.fi);
}

void solve() {
	int n; cin >> n;
	vi a(n);
	vpii vp(n);
	map<int, int> mp;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	for(auto it:mp) vp.pb(it);
	sort(all(vp), cmp);
	for(auto it:vp) {
		for(int i = 0; i < it.se; i++)
				cout << it.fi << " ";
	}
	cout << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}