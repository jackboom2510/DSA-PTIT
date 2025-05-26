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

char flip(char c) {
	if(c == '-')
		return '+';
	if(c == '+')
		return '-';
	return c;
}
string xoaDauNgoac(string s) {
	int n = s.size();
	stack<string> st;
	for(int i = 0; i < n; i++) {
		if(s[i] != ')')
			st.push(string(1, s[i]));
		else {
			string tmp = "";
			while(!st.empty() && st.top() != "(") {
				tmp = st.top() + tmp;
				st.pop();
			}
			st.pop();
			if(!st.empty() && st.top() == "-") {
				for(auto& c:tmp) {
					c = flip(c);
				}
				// cout << "(" << tmp << ") ";
			}
			st.push(tmp);
		}
	}
	string ans = "";
	while(!st.empty()) {
		ans = st.top() + ans;
		st.pop();
	}
	return ans;
}

void solve() {
	string s1, s2; cin >> s1 >> s2;
	// string ns1 = xoaDauNgoac(s1), ns2 = xoaDauNgoac(s2);
	// cout << ns1 << ln << ns2 << ln;
	cout << (xoaDauNgoac(s1) == xoaDauNgoac(s2) ? "YES" : "NO") << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it = 1; it <= t; it++)
		solve();
	return 0;
}