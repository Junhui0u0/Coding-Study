#include <iostream>
#include <algorithm>
using namespace std;
const int max_n = 22;

int r, c;
char arr[max_n][max_n];
int dxy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int alph[28];
int ret = 0;

void dfs(int y, int x, int cnt) {
	alph[arr[y][x] - 'A'] = 1;

	for (int i = 0;i < 4;i++) {
		int ny = y + dxy[i][0];
		int nx = x + dxy[i][1];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if (alph[arr[ny][nx] - 'A']) continue;
		alph[arr[ny][nx] - 'A'] = 1;
		ret = max(ret, cnt);
		dfs(ny, nx, cnt + 1);
		alph[arr[ny][nx] - 'A'] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 0, 1);

	cout << ret + 1 << "\n";
	return 0;
}