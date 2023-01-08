#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, ret;
int arr[10][10];
int visited[10][10];
vector<pair<int, int>> wall;
vector<pair<int, int>> virus;
int dxy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

void dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0;i < 4;i++) {
		int ny = y + dxy[i][0];
		int nx = x + dxy[i][1];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == 1 || visited[ny][nx] == 1) continue;
		dfs(ny, nx);
	}
}

void solve() {
	memset(visited, 0, sizeof(visited));
	for (int i = 0;i < virus.size();i++) {
		dfs(virus[i].first, virus[i].second);
	}

	int cnt = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (arr[i][j] == 0 && visited[i][j] == 0) cnt++;
		}
	}
	ret = max(ret, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 0) wall.push_back({ i,j });
			else if (arr[i][j] == 2) virus.push_back({ i,j });
		}
	}

	for (int i = 0;i < wall.size();i++) {
		for (int j = i + 1;j < wall.size();j++) {
			for (int k = j + 1;k < wall.size();k++) {
				arr[wall[i].first][wall[i].second] = 1;
				arr[wall[j].first][wall[j].second] = 1;
				arr[wall[k].first][wall[k].second] = 1;
				solve();
				arr[wall[i].first][wall[i].second] = 0;
				arr[wall[j].first][wall[j].second] = 0;
				arr[wall[k].first][wall[k].second] = 0;
			}
		}
	}

	cout << ret << "\n";

	return 0;
}