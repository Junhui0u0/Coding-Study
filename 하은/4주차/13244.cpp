#include <bits/stdc++.h>
using namespace std;

int graph[1000][1000] = { 0, };
int visited[1000] = { 0, };
int t, n, m, a, b;
int cnt = 0;

void dfs(int x) {
	visited[x] = 1;
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && graph[x][i]) dfs(i);
	}
}

int main() {
	cin >> t;

	while (t--) {
		
		cnt = 0;
		memset(visited, 0, sizeof(visited));

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			graph[a][b] = graph[b][a] = 1;
		}
	

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
				cnt++;
			}
		}

		if (m == n - 1 && cnt == 1) cout << "tree" << '\n';
		else cout << "graph" << '\n';
	}

}