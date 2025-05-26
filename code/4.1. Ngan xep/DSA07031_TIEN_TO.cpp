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
		if(c == pt[i]) return 1;
	return 0;
}

void calc(vector<string> tokens, int n) {
	stack<ll> st;
	string token;
	char tt;
	ll n1, n2;
	for(int i = n-1; i >= 0; i--) {
		token = tokens[i];
		if(token.size() == 1 && isPT(token[0])) {
			tt = token[0];
			n1 = st.top(); st.pop();
			n2 = st.top(); st.pop();
			if(tt == '+')
				st.push(n1+n2);
			else if(tt == '-')
				st.push(n1-n2);
			else if(tt == '*')
				st.push(n1*n2);
			else
				st.push(n1/n2);
		}
		else
			st.push(stoll(token));
	}
	cout << st.top() << ln;
}

void solve() {
	int n; cin >> n;
	cin.ignore();
	string s;
	getline(cin, s);
	stringstream ss(s);
	string token;
	vector<string> tokens;
	while(ss >> token)
		tokens.pb(token);
	calc(tokens, n);
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