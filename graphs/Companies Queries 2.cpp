#include <bits/stdc++.h>
#define ll long long
#define pb(x) push_back(x)
#define tostr(x) to_string(x)
#define vi vector<int>
#define mii map<int,int>
#define umap unordered_map
#define ff first
#define ss second
#define INF 1e18
#define sastaINF 1e9
#define nline "\n"
#define PI 3.141592653589793238462
#define fastIO  ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;

/*
Stl Usage
Iterator
vector<int>::iterator it = v.begin();

For binary search
bool res = binary_search(start of iterators,ending of iterator,number to be searched);
*/

//Binary Lifting in action baby
using namespace std;

int n, q;
vector<int> tree[200010];
int up[200010][32];
int level[200010];

void dfs(int node, int lev, int parent) {
	level[node] = lev;
	for (auto x : tree[node]) {
		if (x != parent) {
			dfs(x, lev + 1, node);
		}
	}
}

void binary_lifting(int node, int parent) {
	int i;
	up[node][0] = parent;
	for (i = 1; i < 32; i++) {
		if (up[node][i - 1] != -1) {
			up[node][i] = up[up[node][i - 1]][i - 1];
		}
		else {
			up[node][i] = -1;
		}
	}
	for (auto child : tree[node]) {
		if (child != parent) {
			binary_lifting(child, node);
		}
	}
}

int rec(int node1, int node2) {
	if (level[node1] > level[node2]) {
		swap(node1, node2);
	}
	int i;
	for (i = 31; i > -1; i--) {
		if (level[node2] - pow(2, i) >= level[node1]) {
			node2 = up[node2][i];
		}
	}
	if (node1 == node2) {
		return node1;
	}
	for (i = 31; i > -1; i--) {
		if (up[node1][i] != up[node2][i]) {
			node1 = up[node1][i];
			node2 = up[node2][i];
		}
	}
	return up[node1][0];
}

void solve() {
	int i, j, a, b;
	cin >> n >> q;
	i = 2;
	while (i <= n) {
		cin >> a;
		tree[i].pb(a);
		tree[a].pb(i);
		i = i + 1;
	}
	binary_lifting(1, -1);
	dfs(1, 0, -1);
	i = 0;
	while (i < 32) {
		up[0][i] = -1;
		i = i + 1;
	}

	i = 0;
	int ans;
	while (i < q) {
		cin >> a >> b;
		if (a == b) {
			cout << a << nline;
		}
		else {
			ans = rec(a, b);
			cout << ans << nline;
		}
		i = i + 1;
	}
}

int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	// cin >> t;
	t = 1;
	while (t--) {
		solve();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}