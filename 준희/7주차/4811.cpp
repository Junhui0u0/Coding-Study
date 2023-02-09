#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

int n;
int tmp[2][2] = { {1,0},{0,1} };
ll dp[34][34];

ll solve(int a_cnt, int b_cnt) {
	if (a_cnt < b_cnt) return 0;
	if (a_cnt > n || b_cnt > n) return 0;
	if (a_cnt + b_cnt == 2 * n) {
		return 1;
	}

	ll &ret = dp[a_cnt][b_cnt];
	if (ret) return ret;
	for (int i = 0;i < 2;i++) {
		ret += solve(a_cnt + tmp[i][0], b_cnt + tmp[i][1]);
	}
	return ret;
}

int main() {
	while (true) {
		cin >> n;
		if (n == 0) break;
		memset(dp, 0, sizeof(dp));
		cout << solve(1, 0) << "\n";
	}
	return 0;
}
