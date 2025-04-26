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

void split_sort(int a[], int n) {
	sort(a, a+n);
	vector<int> v;
	int last = n-1, first = 0;
	while(first >= 0 && last >= 0 && first < n && last < n && first <= last) {
		v.pb(a[last--]);
		v.pb(a[first++]);
	}
	for(int i = 0; i < n; i++) {
		a[i] = v[i];
	}
}

void solve() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	split_sort(a, n);
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
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