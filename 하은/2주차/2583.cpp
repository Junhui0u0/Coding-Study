#include <bits/stdc++.h>
using namespace std;

int m, n, k;
int ret = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int graph[100][100] = { 0, };
int visited[100][100] = { 0, };

void dfs(int y, int x) {
	visited[y][x] = 1;
	ret++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (!graph[ny][nx] && !visited[ny][nx]) dfs(ny, nx);
	}
}

int main() {

	cin >> m >> n >> k;
	vector<int> ret_list;

	for (int p = 0; p < k; p++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				graph[i][j] = 1;
			}
		}	
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!graph[i][j] && !visited[i][j]) {
				ret = 0;
				dfs(i, j);
				ret_list.push_back(ret);
			}
		}
	}

	cout << ret_list.size() << endl;
	sort(ret_list.begin(), ret_list.end());
	for (int i = 0; i < ret_list.size(); i++) {
		cout << ret_list[i] << " ";
	}
}
