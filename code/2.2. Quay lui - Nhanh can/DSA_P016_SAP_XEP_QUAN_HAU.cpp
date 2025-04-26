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
#define n 8
vector<vi> a;
// vector<vi> b, res;
int col[MAX], md[MAX], sd[MAX], pmax;
void init() {	
	pmax = INT_MIN;
	a.clear();
	a.resize(n, vi(n));
	// b.clear(), res.clear();
	// b.resize(n, vi(n));
	// res.resize(n, vi(n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
}

void Try(int i, int p) {
	if(i == n) {
		if(p > pmax) {
			pmax = p;
			// res = b;
		}
		return;
	}
	for(int j = 0; j < n; j++) {
		if(!col[j] && !md[n-j+i] && !sd[i+j-1]) {
			col[j] = md[n-j+i] = sd[i+j-1] = 1;
			// b[i][j] = 1;
			Try(i+1, p+a[i][j]);
			col[j] = md[n-j+i] = sd[i+j-1] = 0;	
			// b[i][j] = 0;
		}
	}
}

void solve(int t) {
	init();
	Try(0, 0);
	cout << "Test " << t << ": " << pmax << ln;
	// for(int i = 0; i < n; i++) {
	// 	for(int j = 0; j < n; j++) {
	// 		// cout << res[i][j] << " ";
	// 		if(res[i][j] == 1) {
	// 			cout << "Q ";
	// 			// cout << a[i][j] << " " << setw(2);
	// 		}
	// 		// else cout << res[i][j] << " " << setw(2);
	// 		else cout << ". ";
	// 	}
	// 	cout << ln;
	// }
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve(it);
	return 0;
}