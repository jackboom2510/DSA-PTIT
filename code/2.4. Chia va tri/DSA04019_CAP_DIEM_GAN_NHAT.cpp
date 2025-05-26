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
#define MAXSZ 100005

class Point {
public:
	int x, y;
public:
	Point() : x(0), y(0) {}
	Point(int x_, int y_) : x(x_), y(y_) {}
	friend ostream& operator<<(ostream &os, const Point &p) {
		os << p.x << " " << p.y;
		return os;
	}
	Point(const Point& other) {
		x = other.x;
		y = other.y;
	}
	friend istream& operator>>(istream &is, Point &p) {
		is >> p.x >> p.y;
		return is;
	}
};

vector<Point> ps(MAXSZ), tmp(MAXSZ);

double caculateDis(Point a, Point b) {
	int dx = (a.x-b.x)*(a.x-b.x);
	int dy = (a.y-b.y)*(a.y-b.y);
	return sqrt(dx+dy);
}

bool cmp1(Point a, Point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp2(Point a, Point b) {
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}

double closestPair(int l, int r) {
	if(r - l <= 1) {
		double d = 1e18;
		for(int i = l; i <= r; i++) {
			for(int j = i+1; j <= r; j++) {
				d = min(d, caculateDis(ps[i], ps[j]));
			}
		}
		sort(all(ps), cmp2);
		return d;
	}
	int m = (l+r)/2;
	double midx = ps[m].x;
	double d1 = closestPair(l, m);
	double d2 = closestPair(m+1, r);
	double d = min(d1, d2);
	merge(ps.begin()+l, ps.begin()+m+1, ps.begin()+m+1, ps.begin()+r+1, tmp.begin()+l, cmp2);
	copy(tmp.begin()+l, tmp.begin()+r+1, ps.begin()+l);

	vector<Point> strip;
	for(int i = l; i <= r; i++) {
		if(abs(ps[i].x-midx) < d)
			strip.pb(ps[i]);
	}
	for(int i = 0; i < strip.size(); i++) {
		for(int j = i+1; j < strip.size() && strip[j].y -strip[i].y < d; j++)
			d = min(d, caculateDis(strip[i], strip[j]));
	}
	return d;
}

void solve() {
	int n; cin >> n;
	ps.resize(n);
	for(int i = 0; i < n; i++) cin >> ps[i];
	sort(all(ps), cmp1);
	double ans = closestPair(0, n-1);
	cout << fixed << setprecision(6) << ans << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}