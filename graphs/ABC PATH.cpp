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

using namespace std;
int h, w;
int dp[50][50][100];
vector<string> arr;

int rec(int r, int c, int value) {
	// cout << arr[r][c] << nline;
	if ((r < 0) || (r >= h) || (c < 0) || (c >= w)) {
		return 0;
	}

	if (dp[r][c][value] != -1) {
		return dp[r][c][value];
	}
	int x = int(arr[r][c]);
	if (value != x) {
		dp[r][c][value] = 0;
		return dp[r][c][value];
	}
	else {
		int ans = 1;
		ans = max(ans, 1 + rec(r - 1, c, value + 1));
		ans = max(ans, 1 + rec(r + 1, c, value + 1));
		ans = max(ans, 1 + rec(r, c - 1, value + 1));
		ans = max(ans, 1 + rec(r, c + 1, value + 1));
		ans = max(ans, 1 + rec(r - 1, c - 1, value + 1));
		ans = max(ans, 1 + rec(r - 1, c + 1, value + 1));
		ans = max(ans, 1 + rec(r + 1, c + 1, value + 1));
		ans = max(ans, 1 + rec(r + 1, c - 1, value + 1));
		dp[r][c][value] = ans;
		return dp[r][c][value];
	}
}

void solve(int e) {
	int i = 0;
	while (i < h) {
		string s;
		cin >> s;
		arr.pb(s);
		i = i + 1;
	}
	int j;
	int ans = 0;
	// cout << "KKK\n";
	i = 0;
	while (i < h) {
		j = 0;
		while (j < w) {
			ans = max(ans, rec(i, j, 65));
			j = j + 1;
		}
		i = i + 1;
	}
	cout << "Case " << e << ": " << ans << nline;
}

int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, e;
	// cin >> t;
	t = 1;
	e = 1;
	while (t == 1) {
		int i, j, k;
		i = 0;
		while (i < 50) {
			j = 0;
			while (j < 50) {
				k = 0;
				while (k < 100) {
					dp[i][j][k] = -1;
					k = k + 1;
				}
				j = j + 1;
			}
			i = i + 1;
		}
		arr.clear();
		cin >> h >> w;
		if ((h > 0) or (w > 0)) {
			solve(e);
		}
		else {
			t = 0;
		}
		e = e + 1;
	}
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}