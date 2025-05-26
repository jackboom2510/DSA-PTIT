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
	int ok = 0;
	string s;
	getline(cin, s);
	stack<char> st;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
			st.push(s[i]);
		if(s[i] == ')') {
			if(st.top() == '(') {				
				ok = 1;
				break;
			}
			while(st.size() && st.top() != '(')
				st.pop();
			st.pop();
		}
	}
	cout << (ok ? "Yes" : "No") << ln;	
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