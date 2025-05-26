#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vii = vector<pii>;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ln "\n"

ll extendLength(string &s1, string &s2) {
	ll n = s1.size(), m = s2.size();
	if(n > m) {
		for(int i = 0; i < n-m; i++)
			s2 = "0" + s2;
	}
	else if(m > n) {
		for(int i = 0; i < m-n; i++)
			s1 = "0" + s1;
	}
	return n > m ? n : m;
}
string sum(string s1, string s2) {
	ll size = extendLength(s1, s2);
	string res = "";
	int carry = 0;
	for(int i = size-1; i >= 0; i--) {
		int fb = s1[i] - '0';
		int sb = s2[i] - '0';
		int sum = (fb^sb^carry)+'0';
		res = (char)sum + res;
		carry = (fb&sb) || (fb&carry) || (sb&carry);
	}
	if(carry) res = "1" + res;
	return res;
}

ll multiplySBit(string s1, string s2) {
	return (s1[0]-'0')*(s2[0]-'0');
}

ll multiply(string x, string y) {
	int n = extendLength(x, y);
	if(n == 0) return 0;
	if(n == 1) return multiplySBit(x, y);
	int fh = n/2;
	int sh = n-fh;
	string xl = x.substr(0, fh), xr = x.substr(fh, sh);
	string yl = y.substr(0, fh), yr = y.substr(fh, sh);
	ll p1 = multiply(xl, yl);
	ll p2 = multiply(xr, yr);
	ll p3 = multiply(sum(xl, xr), sum(yl, yr));
	return p1*(1LL<<(2*sh)) + p2 + (p3-p1-p2)*(1LL<<sh);
}

void solve() {
	string s1, s2; cin >> s1 >> s2;
	cout << multiply(s1, s2) << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}