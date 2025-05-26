#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define debug(x) cerr << #x << " = " << x << endl
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
	stack<char> st;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '(')
			st.push(s[i]);
		else if(!st.empty()){
			ans += 2;
			st.pop();
		}
	}
	cout << ans << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t; cin.ignore();
	for(int it = 1; it <= t; it++)
		solve();
	return 0;
}