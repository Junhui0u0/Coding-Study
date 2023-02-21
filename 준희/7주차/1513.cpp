#include <iostream>
#include <cstring>
using namespace std;

int arr[51][51], dp[51][51][51][51], a, b, n, m, c;

int solve(int y, int x, int cnt, int prev) {
	if (y > n || x > m) return 0;
	if (y == n && x == m) {
		if (cnt == 0 && arr[y][x] == 0) return 1;
		else if (cnt == 1 && arr[y][x] > prev) return 1;
	}
	int &ret = dp[y][x][cnt][prev];
	if (ret != -1) return ret;
	ret = 0;
	if (arr[y][x] == 0) {
		ret = (solve(y + 1, x, cnt, prev) + solve(y, x + 1, cnt, prev)) % 1000007;
	}
	else if (arr[y][x] > prev) {
		ret = (solve(y + 1, x, cnt - 1, arr[y][x]) + solve(y, x + 1, cnt - 1, arr[y][x])) % 1000007;
	}
	return ret;
}

int main() {
	cin >> n >> m >> c;

	memset(arr, 0, sizeof(arr));
	memset(dp, -1, sizeof(dp));
	for (int i = 1;i <= c;i++) {
		cin >> a >> b;
		arr[a][b] = i;
	}
	for (int i = 0;i <= c;i++) {
		cout << solve(1, 1, i, 0) << " ";
	}
	return 0;
}