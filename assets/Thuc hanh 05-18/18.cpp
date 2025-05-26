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

bool check(Node* root) {
	if(!root) return true;
	if(!root->left && !root->right) return true;
	if(root->left && root->right)
		return check(root->left) && check(root->right);
	return false;
}

void solve() {
	int n; cin >> n;
	map<int, Node*> nodes;
	Node* root = nullptr;
	for(int i = 0; i < n; i++) {
		int u, v; char c;
		cin >> u >> v >> c;
		if(nodes.find(u) == nodes.end()) {
			nodes[u] = new Node(u);
			if(!root) root = nodes[u];
		}
		Node* parent = nodes[u];
		Node* child = new Node(v);
		nodes[v] = child;
		if(c == 'L') parent->left = child;
		else if(c == 'R') parent->right = child;
	}
	if(check(root)) cout << 1 << ln;
	else cout << 0 << ln;
}

int main() {
	fast_cin();
	ll t;
	cin >> t;
	for(int it=1;it<=t;it++)
		solve();
	return 0;
}