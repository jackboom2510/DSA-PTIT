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
#define MAX 4

int a[4], n, ok = 1;
void init() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		a[i] = 0;
	}
}

void show() {
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << ln;
}

int isPalindrome() {
	for(int i = 0; i < n/2; i++) {
		if(a[i] != a[n-1-i]) return 0;
	}
	return 1;
}

void nextString() {
	int i = n-1;
	while(i >= 0 && a[i] == 1) {
		a[i] = 0;
		i--;
	}
	if(i >= 0) a[i] = 1; 	
	else ok = 0;
}

void solve() {
	init();
	while(ok) {
		if(isPalindrome()) show();
		nextString();
	}
}

int main() {
	fast_cin();
	solve();
	return 0;
}