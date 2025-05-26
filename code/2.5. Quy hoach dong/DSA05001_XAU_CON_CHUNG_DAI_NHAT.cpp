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

void solve() {
	string a, b;
	cin >> a >> b;
	int n = b.size(), m = a.size();
	vi prev(n+1, 0), curr(n+1, 0);
	for(int i = 1; i <= m; i++) {
		curr.assign(n+1, 0);
		for(int j = 1; j <= n; j++) {
			if(a[i-1] == b[j-1])
				curr[j] = prev[j-1]+1;
			else
				curr[j] = max(prev[j], curr[j-1]);
		}
		prev.swap(curr);
	}
	cout << prev[n] << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}