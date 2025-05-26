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

void solve() {
	int a, b; cin >> a >> b;
	stack<int> A, B;
	int ma = 0, mb = 0, Ma = 0, Mb = 0, t1 = a, t2 = b, x;
	while(t1 != 0) {
		A.push(t1%10);
		t1 /= 10;
	}
	while(t2 != 0) {
		B.push(t2%10);
		t2 /= 10;
	}
	while(!A.empty()) {
		x = A.top();
		if(x == 6) {
			ma = ma*10 + 5;
			Ma = Ma*10+x;
		}
		else if(x == 5) {
			ma = ma*10+x;
			Ma = Ma*10 + 6;
		}
		else {
			ma = ma*10+x;
			Ma = Ma*10+x;
		}
		A.pop();
	}
	while(!B.empty()) {
		x = B.top();
		if(x == 6) {
			mb = mb*10+5;
			Mb = Mb*10+x;
		}
		else if(x == 5) {
			mb = mb*10+x;
			Mb = Mb*10 + 6;
		}
		else {
			mb = mb*10+x;
			Mb = Mb*10+x;
		}
		B.pop();
	}
	// cout << ma << " " << mb << " " << Ma << " " << Mb << ln;
	cout << ma+mb << " " << Ma+Mb << ln;
}

int main() {
	fast_cin();
	ll t = 1;
	// cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}