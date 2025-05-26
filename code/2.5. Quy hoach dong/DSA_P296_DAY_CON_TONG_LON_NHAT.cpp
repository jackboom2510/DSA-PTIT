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

string btos(int bit, int n) {
	bitset<16> b(bit);
	return b.to_string().substr(16-n, n);
}

vi a, b;
void solve() {
	int l, r; cin >> l >> r;
	l--, r--;
	int n = r-l+1;
	b.resize(n);
	b.assign(a.begin() + l, a.begin() + r + 1);
	if(n == 1) {
		cout << (b[0] > 0 ? b[0] : 0);
		return;
	}
	vi dp(1 << n, 0);
	for(int mask = 0; mask < (1 << n); mask++) {
		for(int i = 0; i < n; i++) {
			if(!cbit(mask, i)) {
				int newMask = sbit(mask, i);
				dp[newMask] = max(dp[newMask], dp[mask]+a[i]);
			}
		}
	}
	cout << dp[(1<<n)-1] << ln;
}

void solve2() {
	int l, r; cin >> l >> r;
	l--; r--;
	int n = r-l+1;
	ll maxSum = 0, current  = 0;
	for(int i = l; i <= r; i++) {
		current = max(0LL, current+a[i]);
		maxSum = max(maxSum, current);
	}
	cout << maxSum << ln;
}

int main() {
	fast_cin();
	int n, t; cin >> n;
	cin >> t;
	a.resize(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int it=1;it<=t;it++)
		solve2();
	return 0;
}