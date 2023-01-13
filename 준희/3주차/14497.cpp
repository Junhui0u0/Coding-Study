#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, a, b, c, d;
char arr[304][304];
int visited[304][304];
int dxy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int ret = 0;

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;

	while (q.size()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int ny = cy + dxy[i][0];
			int nx = cx + dxy[i][1];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
			if (arr[ny][nx] == '1' || arr[ny][nx] == '#') {
				arr[ny][nx] = '0';
				visited[ny][nx] = visited[cy][cx] + 1;
			}
			else if (arr[ny][nx] == '0') {
				q.push({ ny,nx });
				visited[ny][nx] = visited[cy][cx] + 1;
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	cin >> a >> b >> c >> d;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> arr[i][j];
		}
	}

	while (true) {
		memset(visited, 0, sizeof(visited));
		ret++;
		bfs(a - 1, b - 1);
		if (visited[c - 1][d - 1]) break;
	}
	cout << ret << "\n";

	return 0;
}