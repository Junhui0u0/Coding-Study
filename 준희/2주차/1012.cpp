#include <iostream>
#include <cstring>
using namespace std;

int t, n, m, k;
int arr[50][50];
int visited[50][50];
int dxy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int cnt = 0;

void dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0;i < 4;i++) {
		int ny = y + dxy[i][0];
		int nx = x + dxy[i][1];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == 0) continue;
		if (visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));

		cin >> m >> n >> k;
		for (int i = 0;i < k;i++) {
			int a, b;
			cin >> a >> b;
			arr[b][a] = 1;
		}

		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (arr[i][j] == 0) continue;
				if (visited[i][j]) continue;
				dfs(i, j);
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}