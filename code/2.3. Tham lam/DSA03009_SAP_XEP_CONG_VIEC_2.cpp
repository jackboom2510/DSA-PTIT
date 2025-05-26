#include <bits/stdc++.h> 
using namespace std;

using ti = tuple<int, int, int>;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vii = vector<pii>;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) x.begin(), x.end()
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ln "\n"
#define gt(tuple, index) get<index>(tuple)

class Job {
public:
	int id, d, p;
public:
	Job(int i, int j, int k) : id(i), d(j), p(k) {}
};

bool cmp(Job a, Job b) {
	return a.p > b.p;
}

void solve() {
	int n; cin >> n;
	vector<Job> cv;
	int t1, t2, t3, maxdl = 0;
	for(int i = 0; i < n; i++) {
		cin >> t1 >> t2 >> t3;
		maxdl = max(maxdl, t2);
		cv.pb(Job(t1, t2, t3));
	}
	// for(int i = 0; i < n; i++)
	// 	cout << cv[i].id << " " << cv[i].d << " " << cv[i].p << ln;
	// cout << ln;
	sort(all(cv), cmp);
	int cnt = 0, tp = 0;
	vector<int> slot(maxdl+1, -1);
	for(int i = 0; i < n; i++) {
		for(int j = cv[i].d; j >= 1; j--) {
			if(slot[j] == -1) {
				slot[j] = cv[i].id;
				cnt++;
				tp += cv[i].p;
				break;
			}
		}
	}
	// for(auto x:slot) cout << x << " ";
	// cout << ln;
	cout << cnt << " " << tp << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}