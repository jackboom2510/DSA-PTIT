#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define all(x) x.begin(), x.end()
#define cbit(mask, i) (mask & (1 << i))
#define sbit(mask, i) (mask | (1 << i))
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ln "\n"

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val) : data(val), left(NULL), right(NULL) {}
};

void leverOrder(Node* root) {
	if(!root) return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* cur = q.front(); q.pop();
		cout << cur->data << " ";
		if(cur->left) q.push(cur->left);
		if(cur->right) q.push(cur->right);
	}
	cout << ln;
}

void solve() {
	int n; cin >> n;
	map<int, Node*> nodes;
	Node* root = nullptr;
	for(int i = 0; i < n; i++) {
		int u, v; char x;
		cin >> u >> v >> x;
		if(nodes.find(u) == nodes.end()) {
			nodes[u] = new Node(u);
			if(!root) root = nodes[u];
		}
		Node* parent = nodes[u];
		Node* child = new Node(v);
		nodes[v] = child;
		if(x == 'L') parent->left = child;
		else if(x == 'R') parent->right = child;
	}
	leverOrder(root);
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}