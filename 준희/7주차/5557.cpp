#include <iostream>
using namespace std;
typedef long long ll;

ll n,dp[101][21],arr[101];

ll solve(int idx, int sum) {
	if (sum < 0 || sum>20) return 0;
	ll &ret = dp[idx][sum];
	if (ret) return ret;
	if (idx == n - 1) {
		if (sum == arr[n]) return 1;
		return 0;
	}
	ret += solve(idx + 1, sum + arr[idx + 1]);
	ret += solve(idx + 1, sum - arr[idx + 1]);
	return ret;
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}
	cout << solve(1, arr[1]);
	return 0;
}
