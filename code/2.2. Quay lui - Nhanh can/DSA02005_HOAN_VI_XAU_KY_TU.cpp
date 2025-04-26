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
string s;
int x[MAX], used[MAX], n;
void Result() {
	for(int i = 0; i < n; i++)
		cout << s[x[i]];
	cout << " ";
}

void Try(int i) {
	for(int j = 0; j < n; j++) {
		if(!used[j]) {
			used[j] = 1;
			x[i] = j;
			if(i == n-1) Result();
			else Try(i+1);
			used[j] = 0;
		}
	}
}

void solve() {
	cin >> s;
	n = s.length();
	Try(0);
	cout << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}