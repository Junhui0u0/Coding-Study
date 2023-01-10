#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int arr[52][52];
int visited[52][52];
int t[52][52];
int dxy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int ret = 0;

int bfs(int y, int x) {
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y,x });
	t[y][x] = 0;

	while (q.size()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int ny = cy + dxy[i][0];
			int nx = cx + dxy[i][1];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == 0 || visited[ny][nx]) continue;
			q.push({ ny,nx });
			t[ny][nx] = t[cy][cx] + 1;
			visited[ny][nx] = 1;
		}
	}

	int maxV = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			maxV = max(maxV, t[i][j]);
		}
	}
	return maxV;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < s.size();j++) {
			if (s[j] == 'W') arr[i][j] = 0;  //¹Ù´Ù
			else arr[i][j] = 1;
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (arr[i][j] == 0) continue;

			memset(visited, 0, sizeof(visited));
			ret = max(ret, bfs(i, j));
		}
	}

	cout << ret << "\n";

	return 0;
}