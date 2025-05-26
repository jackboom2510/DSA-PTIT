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

void insertSet(set<char>& sc, string s) {
	for(auto ch:s)
		sc.insert(ch);
}

void solve() {
	int n; cin >> n;
	vector<string> vs(n);
	set<char> sc;
	sc.clear();
	for(int i = 0; i < n; i++) {
		cin >> vs[i];
		insertSet(sc, vs[i]);
	}
	for(auto it:sc) cout << it << " ";
	cout << ln;

}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}