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
	string s; cin >> s;
	int n = s.size();
	stack<pair<char, int>> st;
	vi dp(n, 0);
	for(int i = 0; i < n; i++) {
		if(!st.empty() && s[i] == ')' && st.top().fi == '(') {
			dp[i] = dp[i-1];
			if(st.top().se > 0) {
				dp[i] += dp[st.top().se - 1];
			}
			dp[i] += 2;
			st.pop();
		}
		else {
			st.push(mp(s[i], i));
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	cin.ignore();
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}