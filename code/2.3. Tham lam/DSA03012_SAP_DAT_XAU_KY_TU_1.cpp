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

bool cmp(pair<char, int> a, pair<char, int> b) {
	return a.se > b.se;
}

void solve() {
	string s; cin >> s;
	vector<int> f(26, 0);
	for(int i = 0; i < s.size(); i++)
		f[s[i]-'a']++;
	int mf = *max_element(all(f));
	if(mf <= (s.size()+1)/2) cout << "1" << ln;
	else cout << "-1" << ln;
}

int main() {
	fast_cin();
	ll t; cin >> t;
	cin.ignore();
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}