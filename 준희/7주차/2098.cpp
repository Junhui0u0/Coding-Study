#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 987654321;

int n;
int w[16][16];
int dp[16][1 << 16];

int tsp(int here, int visited) {
	if (visited == (1 << n) - 1) {
		return w[here][0] ? w[here][0] : INF;
	}
	int &ret = dp[here][visited];
	if (ret != -1) return ret;
	ret = INF;
	for (int next = 0;next < n;next++) {
		if (visited&(1 << next)) continue;
		if (w[here][next] == 0) continue;
		ret = min(ret, tsp(next, visited | (1 << next)) + w[here][next]);
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> w[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << tsp(0, 1) << "\n";
	return 0;
}
