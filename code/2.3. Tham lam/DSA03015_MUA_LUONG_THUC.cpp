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

int muaLuongThuc() {
	int n, s, m; cin >> n >> s >> m;
	int time = 1, inv = 0;
	while(time <= s) {
		if(time%7 != 0) inv += n;
		time++;
		inv -= m;
		if(inv < 0) return -1;
	}
	int count = m*s/n;
	if(m*s%n != 0) count++;
	return count;
}

void solve() {
	cout << muaLuongThuc() << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}