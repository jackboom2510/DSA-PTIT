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

void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++) {
		cout << "[" << a[0];
		for(int j = 1; j < n-i; j++) {
			cout << " " << a[j];
			b[j-1] = a[j-1]+a[j];
		}
		cout << "]" << ln;
		for(int j = 0; j < n-i; j++)
			a[j] = b[j];
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