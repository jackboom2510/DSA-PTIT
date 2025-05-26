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

ll mergeAndCount(vll &a, int l, int m, int r) {
	vll left(a.begin() + l, a.begin() + m + 1);
	vll right(a.begin() + m + 1, a.begin() + r + 1);
	int i = 0,  j = 0, k = l;
	ll cnt = 0;
	while(i < left.size() && j < right.size()) {
		if(left[i] <= right[j])
			a[k++] = left[i++];
		else {
			a[k++] = right[j++];
			cnt += (left.size()-i);
		}
	}
	while(i < left.size()) a[k++] = left[i++];
	while(j <  right.size()) a[k++] = right[j++];
	return cnt;
}

ll mergeSortAndCount(vll &a, int l, int r) {
	ll cnt = 0;
	if(l < r) {
		int m = (l+r)/2;
		cnt += mergeSortAndCount(a, l, m);
		cnt += mergeSortAndCount(a, m+1, r);
		cnt += mergeAndCount(a, l, m, r);
	}
	return cnt;
}

void solve() {
	int n; cin >> n;
	vll a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll cnt = mergeSortAndCount(a, 0, n-1);
	cout << cnt << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}