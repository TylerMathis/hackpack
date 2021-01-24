#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
using namespace std;

struct FordFulkerson {
	vector<vector<int>> cap;  vector<bool> vis;  int n, s, t, oo = (int)(1E9);
	FordFulkerson(int size) { n = size + 2;  s = n - 2;  t = n - 1;  cap = vector<vector<int>>(n, vector<int>(n, 0)); }
	void add(int v1, int v2, int c) {  cap[v1][v2] = c;  }
	int ff() {
		vis = vector<bool>(n, false);  int f = 0;
		while (true) {
			fill(all(vis), false);  int res = dfs(s, oo);
			if (res == 0) { break; }  f += res;
		}
		return f;
	}
	int dfs(int pos, int minRes) {
		if (pos == t)  return minRes;
		if (vis[pos])  return 0;
		vis[pos] = true;  int f = 0;
		for (int i = 0; i < n; i++) {
			if (cap[pos][i] > 0)  f = dfs(i, min(cap[pos][i], minRes));
			if (f > 0) { cap[pos][i] -= f;  cap[i][pos] += f;  return f; }
		}
		return 0;
	}
};