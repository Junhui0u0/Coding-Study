#include <iostream>
#include <algorithm>
using namespace std;
const int max_n = 52;

int n, m, max_width, max_width2 = 0;
int arr[max_n][max_n];
int visited[max_n][max_n];
int width[2504];
int dxy[4][2] = { {0,-1} ,{-1,0},{0,1},{1,0} };
int cnt = 0;

int dfs(int y, int x, int cnt) {
	if (visited[y][x]) return 0;
	visited[y][x] = cnt;
	int room_cnt = 1;

	for (int i = 0;i < 4;i++) {
		if (!(arr[y][x] & (1 << i))) {
			int ny = y + dxy[i][0];
			int nx = x + dxy[i][1];
			room_cnt += dfs(ny, nx, cnt);
		}
	}
	return room_cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (!visited[i][j]) {
				cnt++;
				width[cnt] = dfs(i, j, cnt);
				max_width = max(max_width, width[cnt]);
			}
		}
	}

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (i + 1 < m) {
				int a = visited[i][j];
				int b = visited[i + 1][j];
				if (a != b) max_width2 = max(max_width2, width[a] + width[b]);
			}
			if (j + 1 < n) {
				int a = visited[i][j];
				int b = visited[i][j + 1];
				if (a != b) max_width2 = max(max_width2, width[a] + width[b]);
			}
		}
	}

	cout << cnt << "\n" << max_width << "\n" << max_width2 << "\n";
	return 0;
}