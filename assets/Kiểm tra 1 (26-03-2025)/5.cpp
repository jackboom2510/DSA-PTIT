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

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.fi < b.fi;
}

int v(set<int> s, int p) {
	return *(s.
}

void solve() {
	int n, k; cin >> n >> k;
	int a[n], ans = 0;
	set<int> s;
	map<int, int> m;
	for(int i = 0; i < n; i++) {
		bool mark = 1;
		cin >> a[i];
		s.insert(a[i]);
		m[a[i]]++;
	}
	for(int i = 0; i < s.size(); i++) {
		ans += m[s[i]]-1;
		for(int j = i+1; j < s.size(); j++) {
			if(v(s, j) - v(s, i) < k) {
				ans += m[s[i]] * m[s[j]];
			}
		}
	}
	cout << ans << ln;
}
	
int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}