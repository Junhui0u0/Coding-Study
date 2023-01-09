#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, total, time;
int arr[102][102];
int dxy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int visited[102][102];
vector<pair<int, int>> v;

void dfs(int y, int x) {
	visited[y][x] = 1;
	if (arr[y][x] == 1) {
		v.push_back({ y,x });
		return;
	}

	for (int i = 0;i < 4;i++) {
		int ny = y + dxy[i][0];
		int nx = x + dxy[i][1];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> arr[i][j];
		}
	}

	while (true) {
		total = 0;
		memset(visited, 0, sizeof(visited));
		v.clear();

		dfs(0, 0);
		for (auto a : v) {
			total++;
			arr[a.first][a.second] = 0;
		}

		bool flag = 0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (arr[i][j] == 1) flag = 1;
			}
		}
		time++;
		if (flag == 0) break;
	}

	cout << time << "\n" << total << "\n";

	return 0;
}