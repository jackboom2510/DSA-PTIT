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

/* Ý tưởng:
- Tại mỗi bước, ta chọn 2 vị trí trong xâu S và hoán đổi nếu nó có thể giúp tạo ra số lớn hơn.
- Quay lui trên tất cả các khả năng.
- Giới hạn số lần hoán đổi là K.
*/

string maxNum;
void Try(string n, int k, int idx) {
	if(k == 0) return;
	char maxDigit = *max_element(n.begin()+idx, n.end());
	if(maxDigit != n[idx]) k--;
	for(int i = n.size() - 1; i > idx-1; i--) {
		if(n[i] == maxDigit) {
			swap(n[i], n[idx]);
			if(n > maxNum) maxNum = n;
			Try(n, k, idx+1);
			swap(n[i], n[idx]);
		}
	}
}
void solve() {
	int k;
	string n;
	cin >> k >> n;
	maxNum = n;
	Try(n, k, 0);
	cout << maxNum << ln;
}
int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}