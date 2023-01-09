#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> v[10002];
int visited[10002];
int maxV = 0;
int dp[10002];

int dfs(int x) {
	int cnt = 1;
	visited[x] = 1;

	for (int i = 0;i < v[x].size();i++) {
		int nx = v[x][i];
		if (visited[nx]) continue;
		cnt += dfs(nx);
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1;i <= n;i++) {
		memset(visited, 0, sizeof(visited));
		dp[i] = dfs(i);
		maxV = max(maxV, dp[i]);
	}

	for (int i = 1;i <= n;i++) {
		if (maxV == dp[i]) cout << i << " ";
	}

	return 0;
}