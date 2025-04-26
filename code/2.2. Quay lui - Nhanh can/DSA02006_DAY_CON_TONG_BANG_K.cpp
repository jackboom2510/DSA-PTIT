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
#define MAX 100
int n, k;
vector<int> subset, a;
vector<vector<int>> res;
void Try(int pos, int sum) {
	if(sum == k) {
		res.pb(subset);	
		return;
	}
	for(int i = pos; i < n; i++) {
		if(sum+a[i] <= k) {
			subset.pb(a[i]);
			Try(i+1, sum+a[i]);
			subset.pop_back();
		}
	}
}
void solve() {
	subset.clear();
	res.clear();
	cin >> n >> k;
	a.resize(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(all(a));
	Try(0, 0);
	if(res.empty()) cout << "-1" << ln;
	else {
		for(auto it:res) {
			cout << "[";
			for(int i = 0; i < it.size(); i++) {
				cout << it[i];
				if(i < it.size()-1) cout << " ";
			}
			cout << "] ";
		}
		cout << ln;
	}
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}