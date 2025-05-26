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
	int n; cin >> n;
	stack<int> st;
	int val;
	string cmd;
	for(int i = 0; i < n; i++) {
		cin >> cmd;
		if(cmd == "PUSH") {
			cin >> val;
			st.push(val);
		}
		else if(cmd == "PRINT") {
			if(st.size()) {
				// stack<int> q;
				cout << st.top() << ln;
				// while(st.size()) {
				// 	q.push(st.top());
				// 	st.pop();
				// }
				// cout << q.top() << ln;
				// while(q.size()) {
				// 	st.push(q.top());
				// 	q.pop();
				// }
			}
			else {
				cout << "NONE" << ln;
			}
		}
		else if(cmd == "POP") {
			if(st.size())
				st.pop();
		}
	}
}

int main() {
	fast_cin();
	ll t = 1;
	// cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}