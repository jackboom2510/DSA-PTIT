#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vll = vector<ll>;
using pii = pair<ll, ll>;
using vii = vector<pii>;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ln "\n"

vector<ll> res;
void Try(ll a, ll b, ll k, ll carry) {
    if (!a && !b && !carry) return;
    ll A = a % 10;
    ll B = b % 10;
    ll sum = A + B + carry;
	res.pb(sum%k);
    carry = sum / k;
    return Try(a / 10, b / 10, k, carry);
}


void solve() {
	ll k, a, b; cin >> k >> a >> b;
	res.clear();
	Try(a, b, k, 0);
	for(auto i = res.rbegin(); i != res.rend(); i++)
		cout << *i;
	cout <<ln;
}

int main() {
	fast_cin();
	int t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}