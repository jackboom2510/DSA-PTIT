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
#define MAX 12

int a[MAX][MAX], n;
vector<string> ans;
vector<pair<string, pair<int, int>>> vt = {{"D", {1, 0}}, {"R", {0, 1}}};
void Try(int i, int j, string s) {
	if(i == n-1 && j == n-1) {
		ans.pb(s);
		return;
	}
	for(int k = 0; k <= 1; k++) {
		int u = i+vt[k].se.fi;
		int v = j+vt[k].se.se;
		if(u >= 0 && v >= 0 && u <= n-1 && v <= n-1 && a[u][v])
			Try(u, v, s+vt[k].fi);
	}
}

void solve() {
	ans.clear();
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	if(a[0][0]) Try(0, 0, "");
	if(ans.size() == 0) cout << "-1" << ln;
	else {
		for(int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << ln;
	}
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}