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

string pt = "+-*/";
int isPT(char c) {
	return pt.find(c) != string::npos;
}



void solve();

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it = 1; it <= t; it++)
		solve();
	return 0;
}

void solve() {
	string s; cin >> s;
	stack<string> st;
	string ans;
	for(int i = 0; i < s.size(); ++i) {
		if(!isPT(s[i]))
			st.push(string(1, s[i]));
		else {
			ans = st.top(); st.pop();
			ans = s[i] + st.top() + ans; st.pop();
			st.push(ans);
		}
	}
	cout << st.top() << ln;
}