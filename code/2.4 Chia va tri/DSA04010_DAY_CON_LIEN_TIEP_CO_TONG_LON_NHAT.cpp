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

class Sequence {
public:
	int s, l, r;
	Sequence(int sum, int start, int end) : s(sum), l(start), r(end) {}
	bool operator<(Sequence& other) {
		return s < other.s;
	}
	bool operator>=(Sequence& other) {
		return !(*this < other);
	}
};
Sequence maxCrossingSum(vector<int> a, int left, int mid, int right) {
	int s = 0, ls = INT_MIN, rs = INT_MIN, lm = mid, rm = mid+1;
	for(int i = mid; i >= left; i--) {
		s += a[i];
		if(ls < s) {
			ls = s;
			lm = i;
		}
	}
	s = 0;
	for(int i = mid+1; i <= right; i++) {
		s += a[i];
		if(rs < s) {
			rs = s;
			rm = i;
		}
	}
	return Sequence(ls+rs, lm, rm);
}

Sequence maxSubSum(vector<int> a, int left, int right) {
	if(left == right)
		return {a[left], left, right};
	int mid = (left+right)/2;
	Sequence ls = maxSubSum(a, left, mid);
	Sequence rs = maxSubSum(a, mid+1, right);
	Sequence cs = maxCrossingSum(a, left, mid, right);
	if(ls >= rs && ls >= cs) return ls;
	else if(rs >= ls && rs >= cs) return rs;
	return cs; 
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	Sequence ans = maxSubSum(a, 0, n-1);
	cout << "[a[" << ans.l << "] = " << a[ans.l] << " -> a[" << ans.r << "] = " << a[ans.r] << "] = " << ans.s; 
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}