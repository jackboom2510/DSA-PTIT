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

// 100 80 60 70 60 75 85
// 1   1  1  2  1  4  6

void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	a[0] = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<int> dp(n+1, 1);
	for(int i = 1; i <= n; i++) {
		int maxi = 1;
		for(int j = 1; j <= i; j++) {
			if(a[j] < a[i]) {
				dp[i] += 1;
			}
		}
	}
	for(int i = 1; i <= n; i++) cout << dp[i] << " ";

}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}