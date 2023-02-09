#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m, visited[50][50], dp[50][50];
string s;
char arr[50][50];
int dxy[4][2] = { {-1,0} ,{0,1},{1,0},{0,-1} };

bool chk(int y, int x) {
	return 0 <= y && y <= n - 1 && 0 <= x && x <= m - 1;
}

int func(int y, int x) {
	if (!chk(y, x) || arr[y][x] == 'H') return 0;
	if (visited[y][x]) {
		cout << -1 << "\n";
		exit(0);
	}
	int &ret = dp[y][x];
	if (ret) return ret;

	visited[y][x] = 1;
	int val = (int)arr[y][x] - '0';
	for (int i = 0;i < 4;i++) {
		int ny = y + dxy[i][0] * val;
		int nx = x + dxy[i][1] * val;
		ret = max(ret, func(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> s;
		for (int j = 0;j < s.size();j++) {
			arr[i][j] = s[j];
		}
	}
	cout << func(0, 0) << "\n";
	return 0;
}
