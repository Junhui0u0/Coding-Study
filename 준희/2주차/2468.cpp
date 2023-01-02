#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int ret = 1;
int arr[101][101];
int visited[101][101];
int dxy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

void dfs(int y, int x, int d) {
	visited[y][x] = 1;

	for (int i = 0;i < 4;i++) {
		int ny = y + dxy[i][0];
		int nx = x + dxy[i][1];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx] == 0 && arr[ny][nx] > d) dfs(ny, nx, d);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}

	for (int d = 1;d < 101;d++) {
		int cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int j = 0;j < n;j++) {
			for (int k = 0;k < n;k++) {
				if (arr[j][k] > d && visited[j][k] == 0) {
					dfs(j, k, d);
					cnt++;
				}
			}
		}
		ret = max(ret, cnt);
	}

	cout << ret << "\n";

	return 0;
}