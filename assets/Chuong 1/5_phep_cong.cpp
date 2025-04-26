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

void solve() {
	string math;
	getline(cin, math);
	stringstream ss(math);
	string x;
	int sohang[2], index = 0;
	while(ss >> x) {
		if(x != "+" && x != "=") {
			sohang[index++] = stoi(x);
		}
	}
	if(sohang[0] + sohang[1] == sohang[2]) cout << "YES" << ln;
	else cout << "NO" << ln;
}

int main() {
	fast_cin();
	solve();
	return 0;
}