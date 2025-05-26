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

string pt = "+*/^";
int ispt(char c) {
	return pt.find(c) != string::npos;
}

int issh(char c) {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int Deg(char c) {
	switch(c) {
		case '^': return 3;
		case '*':
		case '/': return 2;
		case '+':
		case '-': return 1;
		default: return 0;
	}
}

void solve() {
	string s; cin >> s;
	stack<char> st;
	st.push('#');
	string ans = "";
	for(int i = 0; i < s.size(); i++) {
		if(issh(s[i])) {
			ans += s[i];
		}
		else if(s[i] == '(') {
			st.push(s[i]);
		}
		else if(s[i] == ')') {
			while(st.top() != '(') {
				ans += st.top();
				st.pop();
			}
			st.pop();
		}
		else if(ispt(s[i])) {
			while (Deg(s[i]) < Deg(st.top()) || (Deg(s[i]) == Deg(st.top()) && s[i] != '^')) {
				ans += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(st.top() != '#') {
		ans += st.top();
		st.pop();
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