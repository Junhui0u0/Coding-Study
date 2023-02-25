#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 987654321;

int num, dp[100001][5][5];
vector<int> input;

int cal(int cur, int next) {
	if (cur == next) return 1;
	else if (cur == 0 || next == 0) return 2;
	else {
		if (cur == 1 || next == 1) {
			if (cur == 2 || next == 2 || cur == 4 || next == 4) return 3;
			else if (cur == 3 || next == 3) return 4;
		}
		else if (cur == 2 || next == 2) {
			if (cur == 1 || next == 1 || cur == 3 || next == 3) return 3;
			else if (cur == 4 || next == 4) return 4;
		}
		else if (cur == 3 || next == 3) {
			if (cur == 2 || next == 2 || cur == 4 || next == 4) return 3;
			else if (cur == 1 || next == 1) return 4;
		}
		else if (cur == 4 || next == 4) {
			if (cur == 1 || next == 1 || cur == 3 || next == 3) return 3;
			else if (cur == 2 || next == 2) return 4;
		}
	}
}

int solve(int idx, int left, int right) {
	if (left == right && idx != 0) return INF;
	if (idx == input.size()) return 0;
	int &ret = dp[idx][left][right];
	if (ret > 0) return ret;
	ret = INF;
	ret = min(ret, solve(idx + 1, input[idx], right) + cal(left, input[idx]));
	ret = min(ret, solve(idx + 1, left, input[idx]) + cal(right, input[idx]));
	return ret;
}

int main() {
	while (true) {
		cin >> num;
		if (num == 0) break;
		input.push_back(num);
	}
	cout << solve(0, 0, 0) << "\n";
	return 0;
}
