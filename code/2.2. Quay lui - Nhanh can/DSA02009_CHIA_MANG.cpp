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

/* Ý tưởng:
12 3
2 1 4 5 3 3
- Tìm số phần tử của các tập con, tổng của từng tập con 2-6
- Tại mỗi bước bát đầu ghép tổ hợp (nếu ko tồn tại -> trả về -1)
*/
vector<int> a, b;
vector<vector<int>> ans;
int s, n, k;
void Try(int i) {
	
}

void init() {
	cin >> n >> k;
	a.resize(n);
	b.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	s = accumulate(all(a), 0)/(n/k);
}

void solve() {
	init();
	if(n%k) {
		return;
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