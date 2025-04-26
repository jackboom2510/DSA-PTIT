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

void print_(int a[], int n, int counter) {
	cout << counter << " - ";
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << ln;
}

void solve() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 0; i < n-1; i++) {
		int k = i;
		for(int j = i+1; j < n; j++) {
			if(a[j] < a[k]) {
				k = j;
			}
		}
		if(k != i)
			ans++;
		swap(a[k], a[i]);
		// print_(a, n, ans);
	}
	cout << ans << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}