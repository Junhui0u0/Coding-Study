#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int graph[51][51];
int visited[51][51];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int ret = 0;

void dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (graph[ny][nx] && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		cin >> m >> n >> k;

		memset(visited, 0, sizeof(visited));
		memset(graph, 0, sizeof(graph));
		ret = 0;

		for (int i = 0; i < k; i++) {
			int n1, n2;
			cin >> n1 >> n2;

			graph[n2][n1] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j] && !visited[i][j]) {
					dfs(i, j);
					ret++;
				}
			}
		}

		cout << ret << '\n';
	}

}