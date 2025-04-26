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

class Date {
public:
	string d, m, y;
public:
	Date(const string& s) {
		this->d = s.substr(0, 2);
		this->m = s.substr(2, 2);
		this->y = s.substr(4, 4);
	}
	friend ostream& operator<<(ostream& os, const Date& D) {
		os << D.d << "/" << D.m << "/" << D.y;
		return os;
	}
};
bool cmp(Date a, Date b) {
	if(a.y != b.y) return a.y < b.y;
	else if(a.m != b.m) return a.m < b.m;
	return a.d < b.d;
}
vector<Date> D;
int n = 8, x[8], sp[2] = {0, 2};
int isSpecialDay() {
	if(x[4] != 2 || x[2] || !x[3] || (!x[0]&&!x[1])) return 0;
	// for(int i = 0; i < n; i++)
	// 	if(x[i] != x[n-i-1]) return 0;
	return 1;
}

void Result() {
	for(int i = 0; i < n; i++) {
		cout << x[i];
		if(i == 1 || i == 3) cout << "/";
	}
	cout << ln;
}

void Try(int i) {
	if(i == n) {
		if(isSpecialDay()) {
			string s = "";
			for(int i = 0; i < n; i++)
				s += to_string(x[i]);
			Date day(s);
			D.pb(day);
		}
		return;
	}
	for(int j = 0; j <= 1; j++) {
		x[i] = sp[j];
		Try(i+1);
	}
}

void solve() {
	Try(0);
	// sort(all(D), cmp);
	for(auto i:D)
		cout << i << ln;
}

int main() {
	fast_cin();
	solve();
	return 0;
}