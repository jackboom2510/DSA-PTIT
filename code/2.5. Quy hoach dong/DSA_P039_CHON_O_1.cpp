#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;
using vvll = vector<vll>;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) x.begin(), x.end()
#define cbit(mask, i) (mask & (1 << i))
#define sbit(mask, i) (mask | (1 << i))
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define sz size()
#define ln "\n"

string btos(int bit, int n) {
	bitset<16> b(bit);
	return b.to_string().substr(16-n, n);
}

void solve() {
	int n; cin >> n;
	vvll a(n+1, vll(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) cin >> a[i][j];
	}
	vvll dp(n, vll(1<<n, -1));
	dp[0][0] = 0;
	for(int row = 0; row < n; row++) {
		for(int mask = 0; mask < (1 << n); mask++) {
			if(dp[row][mask] == -1) continue;
			for(int col = 0; col < n; col++) {
				if(!cbit(mask, col)) {
					int newMask = sbit(mask, col);
					dp[row+1][newMask] = max(dp[row+1][newMask], dp[row][mask]+a[row][col]);
				}
			}
		}
	}
	for(int i = 0; i <= n; i++) {
    	cout<< "Row " << i+1 << ":" << ln;
		for(int j = 0; j < (1 << n); j++) {
			cout << "[" << btos(j, n) << "]=" << dp[i][j] << " ";
		}
    	cout << ln;
	}
}

void solve2() {
	int n; cin >> n;
	vvll a(n, vll(n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) cin >> a[i][j];
	vll dp(1 << n, 0);
	for(int mask = 0; mask < (1 << n); mask++) {
		int row = __builtin_popcount(mask);
		if(row >= n) continue;
		for(int col = 0; col < n; col++) {
			if(!cbit(mask, col)) {
				int newMask = sbit(mask, col);
				dp[newMask] = max(dp[newMask], dp[mask]+a[row][col]);
			}
		}
	}
	// for(int i = 0; i < (1 << n); i++)
	// 	cout << btos(i, n) << " " << dp[i] << ln;
	cout << dp[(1<<n)-1] << ln;
	// cout << ln;
}


int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve2();
	return 0;
}