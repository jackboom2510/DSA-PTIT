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

ll F[92];
void init(int n) {
	F[1] = F[2] = 1;
	for(int i = 3; i <= n; i++)
		F[i] = F[i-2] + F[i-1];
}

char Try(ll n, ll k) {
	if(n == 1) return 'A';
	if(n == 2) return 'B';
	if(k <= F[n-2]) return Try(n-2, k);
	else return Try(n-1, k-F[n-2]);
}

void solve() {
	ll n, k; cin >> n >> k;
	init(n);
	// while(1) {
	// 	if(n == 1) {
	// 		cout << "A" << ln;
	// 		break;
	// 	}
	// 	if(n == 2) {
	// 		cout << "B" << ln;
	// 		break;
	// 	}
	// 	if(k <= F[n-2]) n-=2;
	// 	else {
	// 		n--;
	// 		k-=F[n-2];
	// 	}
	// }
	cout << Try(n, k) << ln;
}

int main() {
	fast_cin();
	ll t; cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}