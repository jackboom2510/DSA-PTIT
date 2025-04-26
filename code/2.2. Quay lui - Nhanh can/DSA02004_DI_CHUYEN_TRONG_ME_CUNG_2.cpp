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

class Direction {
public:
	string d;
	int dx, dy;
public:
	Direction(string d_, int dx_, int dy_) : d(d_), dx(dx_), dy(dy_) {}
};
Direction D[4] = {
	Direction("D", 1, 0),
	Direction("L", 0, -1),
	Direction("R", 0, 1),
	Direction("U", -1, 0)
};
vector<vi> a;
vector<string> ans;
int n;
void Try(int i, int j, string s) {
	if(i == n-1 && j == n-1) {
		ans.pb(s);
		return;
	}
	for(int k = 0; k < 4; k++) {
		int u = i+D[k].dx;
		int v = j+D[k].dy;
		if(u >= 0 && v >= 0 && u < n && v < n && a[u][v]) {
			// a[i][j] = 0;
			a[u][v] = 0;
			Try(u, v, s+D[k].d);
			// a[i][j] = 1;
			a[u][v] = 1;
		}
	}
} 
void init() {
	cin >> n;
	a.clear(); ans.clear();
	a.resize(n, vi(n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	if(!a[0][0]) a[0][0] = 1;
}

void solve() {
	init();
	if(!a[0][0] || !a[n-1][n-1]) {
		cout << "-1" << ln;
		return;
	}
	a[0][0] = 0;
	Try(0, 0, "");
	if(ans.empty()) {
		cout << "-1" << ln;
		return;
	}
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
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