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
	vpii pairs;
	set<string> res;
	stack<int> st;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') {
			st.push(i);
		}
		else if(s[i] == ')') {
			pairs.pb(mp(st.top(), i));
			st.pop();
		}
	}
	int total = 1 << pairs.size();
	for(int mask = 1; mask < total; mask++) {
		set<int> rp; // remove_pos;
		for(int i = 0; i < pairs.size(); i++) {
			if(cbit(mask, i)) {
				rp.insert(pairs[i].fi);
				rp.insert(pairs[i].se);
			}
		}
		string tmp = "";
		for(int i = 0; i < s.size(); i++) {
			if(!rp.count(i)) {
				tmp += s[i];
			}
		}
		res.insert(tmp);
	}
	for(auto it:res) cout << it << ln;
}

int main() {
	fast_cin();
	ll t = 1;
	// cin >> t;
	for(int it = 1; it <= t; it++)
		solve();
	return 0;
}