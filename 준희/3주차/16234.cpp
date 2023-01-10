#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n, l, r, ret, sum = 0;
int arr[52][52];
int visited[52][52];
int dxy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<pair<int, int>> v;

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dxy[i][0];
		int nx = x + dxy[i][1];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
		if (abs(arr[ny][nx] - arr[y][x]) >= l && abs(arr[ny][nx] - arr[y][x]) <= r) {
			visited[ny][nx] = 1;
			v.push_back({ ny,nx });
			sum += arr[ny][nx];
			dfs(ny, nx);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l >> r;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}

	while (true) {
		bool flag = 0;
		fill(&visited[0][0], &visited[0][0] + 52 * 52, 0);
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (!visited[i][j]) {
					v.clear();
					visited[i][j] = 1;
					v.push_back({ i,j });
					sum = arr[i][j];
					dfs(i, j);
					if (v.size() == 1) continue;
					for (pair<int, int> a : v) {
						arr[a.first][a.second] = sum / v.size();
						flag = 1;
					}
				}
			}
		}
		if (!flag) break;
		ret++;
	}

	cout << ret << "\n";

	return 0;
}