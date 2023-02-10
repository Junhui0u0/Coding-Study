#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, c, mm, pp, dp[10004];
double m, p;

int main() {
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0.00) break;

		fill(dp, dp + 10004, 0);
		mm = round(m * 100);	//m*100 + 0.001 (부동소수점)
		for (int i = 0;i < n;i++) {
			cin >> c >> p;
			pp = round(p * 100);
			for (int j = pp;j <= mm;j++) {
				dp[j] = max(dp[j], dp[j - pp] + c);
			}
		}
		cout << dp[mm] << "\n";
	}
	return 0;
}