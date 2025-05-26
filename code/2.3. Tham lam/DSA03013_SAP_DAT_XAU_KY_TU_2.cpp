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

int isSortable() {
	string s; int d;
	cin >> d >> s;
	unordered_map<char, int> m;
	for(char c:s)
		m[c]++;
	priority_queue<pair<int, char>> pq;
	for(auto it:m)
		pq.push(mp(it.se, it.fi));
	queue<pair<int, pair<int, char>>> wq;
	string res;
	int time = 0;
	while(!pq.empty() || !wq.empty()) {
		if(!wq.empty() && wq.front().fi <= time) {
			pq.push(wq.front().se);
			wq.pop();
		}
		if(!pq.empty()) {
			auto [ct, ch] = pq.top(); pq.pop();
			res += ch;
			if(ct > 1) {
				wq.push(mp(time+d, mp(ct-1, ch)));
			}
		}
		else {
			if(!wq.empty())
				return -1;
		}
		time++;
	}
	return 1;
}

void solve() {
	cout << isSortable() << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	// cin.ignore();
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}