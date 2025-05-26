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

string pt = "+-";
int isPT(char c) {
	return pt.find(c) != string::npos;
}
void flip(char& c) {
	if(c == '+') c = '-';
	else c = '+';
}
void solve() {
	string s; cin >> s;
	stack<string> st;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		if(s[i] != ')')
			st.push(string(1, s[i]));
		else {
			string bt = "";
			while(!st.empty() && st.top() != "(") {
				bt = st.top() + bt;
				st.pop();
			}
			st.pop();
			// cout << "(" << st.top() << ") (";
			if(!st.empty() && st.top() == "-") {
				for(int i = 0; i < bt.size(); i++) {
					// cout << bt[i];
					if(isPT(bt[i])) {
						flip(bt[i]);
					}
				}
			}
			// cout << ") ";
			st.push(bt);
		}
	}
	string ans = "";
	while(!st.empty()) {
		ans = st.top() + ans;
		st.pop();
	}
	cout << ans << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it = 1; it <= t; it++)
		solve();
	return 0;
}