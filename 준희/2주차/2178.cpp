#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
int arr[100][100];
int visited[100][100];
int dxy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
queue<pair<int, int>> q;

void bfs(int y, int x) {
	visited[y][x] = 1;
	q.push({ y,x });

	while (q.size()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int ny = cy + dxy[i][0];
			int nx = cx + dxy[i][1];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[cy][cx] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < m;j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	bfs(0, 0);
	cout << visited[n - 1][m - 1] << "\n";

	return 0;
}