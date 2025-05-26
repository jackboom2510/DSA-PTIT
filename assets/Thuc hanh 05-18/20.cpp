#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAXN = 1000005;
vector<int> adj[MAXN];
bool visited[MAXN];
int dist[MAXN];

int bfs(int start, int n) {
	memset(visited, false, sizeof(bool)*(n+1));
	memset(dist, 0, sizeof(int)*(n+1));
	queue<int> q;
	q.push(start);
	visited[start] = true;
	int maxDist = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v:adj[u]) {
			if(!visited[v]) {
				visited[v] = true;
				dist[v] = dist[u]+1;
				maxDist = max(maxDist, dist[v]);
				q.push(v);
			}
		}
	}
	return maxDist;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
		for(int i = 1; i <= n; i++)
			adj[i].clear();
		for(int i = 0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout << bfs(1, n) << endl;
    }
}