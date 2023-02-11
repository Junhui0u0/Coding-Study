#include <iostream>
#include <algorithm>
using namespace std;

int n, k, w, v, dp[100004];

int main() {
	cin >> n >> k;
	fill(dp, dp + 100004, 0);
	for (int i = 0;i < n;i++) {
		cin >> w >> v;
		for (int j = k;j >= w;j--) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}
	cout << dp[k] << "\n";
	return 0;
}