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

int n, m;
char a[1000][1000];
int obs = 0;
char obsch = '#';
char nobsch = '.';

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] == obsch) {
			a[nx][ny] = nobsch;
			dfs(nx, ny);
		}
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == obsch) {
				a[i][j] = nobsch;
				obs++;
				dfs(i, j);
			}
		}
	}
	cout << obs;
}

int main() {
	fast_cin();
	solve();
	return 0;
}