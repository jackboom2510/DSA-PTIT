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

string pt = "+-*/";
int isPT(char c) {
	for(int i = 0; i < 4; i++)
		if(pt[i] == c) return 1;
	return 0;
}

void solve() {
	string s, ans; cin >> s;
	stack<string> st;
	for(int i = s.size()-1; i >= 0; i--) {
		if(isPT(s[i])) {
			ans = "(" + st.top();
			st.pop();
			ans += s[i] + st.top() + ")";
			st.pop();
			st.push(ans);
		}
		else {
			st.push(string(1, s[i]));
		}
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