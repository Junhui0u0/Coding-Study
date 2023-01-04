#include <bits/stdc++.h>
using namespace std;

int n;
int graph[100][100] = { 0, };
int visited[100][100] = { 0, };
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void dfs(int y, int x, int k) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (graph[ny][nx] > k && !visited[ny][nx]) dfs(ny, nx, k);
	}

}
int main() {

	vector<int> ret_list;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}


	for (int k = 1; k <= 100; k++) {
		int ret = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] > k && !visited[i][j]) {
					dfs(i, j, k);
					ret++;
				}
			}
		}
		ret_list.push_back(ret);
	}

	cout << *max_element(ret_list.begin(), ret_list.end());
}