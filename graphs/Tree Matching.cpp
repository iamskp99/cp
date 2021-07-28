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

unordered_map<int, vector<int>> graph;
int dp[200001][2];


int rec(int node, int flag, int parent) {
	if (dp[node][flag] != -1) {
		return dp[node][flag];
	}
	int cnt;
	int ans = 0;
	for (auto x : graph[node]) {
		if (x != parent) {
			ans = ans + rec(x, 0, node);
		}
	}
	cnt = ans;
	if (flag == 0) {
		for (auto x : graph[node]) {
			if (x != parent) {
				ans = max(ans, cnt + 1 + rec(x, 1, node) - rec(x, 0, node));
			}
		}
	}
	dp[node][flag] = ans;
	return ans;
}

void solve() {
	int n, a, b, i, j;
	cin >> n;
	i = 0;
	while (i < n - 1) {
		cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
		i = i + 1;
	}
	i = 0;
	while (i < 200001) {
		j = 0;
		while (j < 2) {
			dp[i][j] = -1;
			j = j + 1;
		}
		i = i + 1;
	}
	cout << rec(1, 0, 0) << nline;
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
		graph.clear();
		solve();
	}
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}