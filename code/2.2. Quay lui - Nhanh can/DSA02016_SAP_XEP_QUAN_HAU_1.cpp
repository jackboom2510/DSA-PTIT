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
// a[i][j] <-> diag[n-j+i]
// diag.size = 2n-1, col.size = n
int a[MAX][MAX], col[MAX], mdiag[MAX], sdiag[MAX], n, c;
void Result() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			cout << a[i][j];
		cout << ln;
	}
	cout << ln;
}
void Try(int rpos) {
	if(rpos == n+1) {
		c++;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(!col[i] && !mdiag[n-i+rpos] && !sdiag[rpos+i-1]) {
			a[rpos][i] = col[i] = mdiag[n-i+rpos] = sdiag[rpos+i-1] = 1;
			Try(rpos+1);
			a[rpos][i] = col[i] = mdiag[n-i+rpos] = sdiag[rpos+i-1] = 0;
		}
	}
}
void solve() {
	c = 0;
	cin >> n;
	Try(1);
	cout << c << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}