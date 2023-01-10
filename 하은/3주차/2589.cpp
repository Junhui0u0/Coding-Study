#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[50][50];
int depth[50][50] = { 0, };
pair<int, int> start = { 0,0 }, end = { 0,0 };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int max_n = 0;


void bfs(int y, int x) {
	memset(depth, 0, sizeof(depth));
	queue<pair<int, int>> q;
	q.push({ y, x });

	int last_y = 0, last_x = 0, last_depth = 0;
	while (!q.empty()) {
		pair<int, int> front = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = front.second + dx[i];
			int ny = front.first + dy[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (graph[ny][nx] == 1 && !depth[ny][nx] && (ny != y && nx != x)) {
				depth[ny][nx] = depth[front.first][front.second] + 1;
				q.push({ ny, nx });
				max_n = max(depth[ny][nx], max_n);
			}

			
		}
	}
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			if (s[j] == 'W') graph[i][j] = 0;
			else graph[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 1) bfs(i, j);
		}
	}

	cout << max_n;
}