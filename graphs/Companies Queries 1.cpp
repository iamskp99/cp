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

int fun(int node, int level) {
	return up[node][level];
}

string to_binary(int x) {
	string w = "";
	string r;
	int e;
	while (x > 0) {
		e = x % 2;
		r = tostr(e);
		w = w + r;
		x = x / 2;
	}
	return w;
}

void solve() {
	int i, x, k, j, a, b;
	cin >> n >> q;
	i = 2;
	while (i <= n) {
		cin >> a;
		tree[i].pb(a);
		tree[a].pb(i);
		i = i + 1;
	}
	binary_lifting(1, -1);
	i = 0;
	while (i < 32) {
		up[0][i] = -1;
		i = i + 1;
	}

	i = 0;
	string s;
	int ans;
	// cout << up[2][0] << nline;
	while (i < q) {
		cin >> x >> k;
		s = to_binary(k);
		j = 0;
		// cout << s << " " << k << " " << nline;
		while (j < s.length()) {
			if (s[j] == '1') {
				x = fun(x, j);
				ans = x;
			}
			if (x == -1) {
				ans = -1;
				break;
			}
			j = j + 1;
		}
		cout << ans << nline;
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