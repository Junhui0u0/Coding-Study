#include <iostream>
using namespace std;

int n, k, num, dp[10004];

int main() {
	cin >> n >> k;
	dp[0] = 1;
	for (int i = 0;i < n;i++) {
		cin >> num;
		for (int j = num;j <= k;j++) {
			dp[j] += dp[j - num];
		}
	}
	cout << dp[k] << "\n";
	return 0;
}