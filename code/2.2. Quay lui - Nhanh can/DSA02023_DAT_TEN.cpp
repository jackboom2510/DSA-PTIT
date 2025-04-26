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
int n, k, x[MAX];
vector<string> v;
void Result() {
	cout << "[";
	for(int i = 1; i < k; i++)
		cout << v[x[i]] << " ";
	cout << v[x[k]] << "]" << ln;
}

void Try(int i) {
	for(int j = x[i-1]+1; j <= n-k+i; j++) {
		x[i] = j;
		if(i == k) Result();
		else Try(i+1);
	}
}
void solve() {
	cin >> n >> k;
	set<string> s;
	for(int i = 0; i < n; i++) {
		string x;
		cin >> x;
		s.insert(x);
	}
	for(auto i:s)
		v.pb(i);
	n = v.size();
	v.insert(v.begin(), 1, "");
	Try(1);
}

int main() {
	fast_cin();
	solve();
	return 0;
}