#include <bits/stdc++.h>
using namespace std;

int r, c;
int ret;
char graph[20][20];
int visited[26] = { 0, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int y, int x, int cnt) {
	ret = max(ret, cnt);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		
		int next = (int)(graph[ny][nx] - 'A');
		if (visited[next] == 0) {
			visited[next] = 1;
			dfs(ny, nx, cnt + 1);
			visited[next] = 0;
		}

	}



}
int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			graph[i][j] = s[j];
		}
	}

	visited[graph[0][0] - 'A'] = 1;
	dfs(0, 0, 1);

	cout << ret;
}