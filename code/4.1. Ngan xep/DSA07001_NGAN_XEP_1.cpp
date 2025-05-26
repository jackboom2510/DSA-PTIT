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
	stack<int> st;
	int val;
	string input;
	while(cin >> input) {
		if(input == "push") {
			cin >> val;
			st.push(val);
		}
		else if(input == "show") {
			if(st.size()) {
				stack<int> q;
				while(st.size()) {
					q.push(st.top());
					st.pop();
				}
				while(q.size()) {
					cout << q.top() << " ";
					st.push(q.top());
					q.pop();
				}
				cout << ln;
			}
			else {
				cout << "empty" << ln;
			}
		}
		else if(input == "pop") {
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