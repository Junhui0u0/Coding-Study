#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k;
int arr[101][101];
int visited[101][101];
int dxy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<int> v;

int dfs(int y, int x) {
	int ret = 1;
	visited[y][x] = 1;

	for (int i = 0;i < 4;i++) {
		int ny = y + dxy[i][0];
		int nx = x + dxy[i][1];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n || arr[ny][nx] == 1) continue;
		if (visited[ny][nx]) continue;
		ret += dfs(ny, nx);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> k;

	for (int i = 0;i < k;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		for (int y = b;y < d;y++) {
			for (int x = a;x < c;x++) {
				arr[y][x] = 1;
			}
		}
	}

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j] == 0 && visited[i][j] == 0) {
				v.push_back(dfs(i, j));
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int cnt : v) cout << cnt << " ";

	return 0;
}