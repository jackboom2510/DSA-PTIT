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

vector<vector<string>> ans;
vector<string> ds, kq;
vector<int> m;
string last;
int n;
// 1 2 3 4

void printkq() {
	for(auto i:ans) {
		for(auto j:i) cout << j << " ";
		cout << ln;
	}
}

void Try(vector<string> kq, int i) {
	if(i == n-1) {
		kq[i] = last;
		ans.pb(kq);
		return;
	}
	for(int j = 0; j < n-1; j++) {
		if(!m[j]) {
			m[j] = 1;
			kq[i] = ds[j];
			Try(kq, i+1);
			m[j] = 0;
		}
	}
}

void solve() {
	cin >> n;
	vector<string> x(n);
	ds.clear();
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	cin >> last;
	for(int i = 0; i < n; i++) {
		if(x[i] != last) ds.pb(x[i]);
	}
	sort(all(ds));
	m.resize(n);
	vector<string> kq(n);
	Try(kq, 0);
	printkq();
}

int main() {
	fast_cin();
	ll t = 1;
	// cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}