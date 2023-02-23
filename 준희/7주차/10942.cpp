#include <iostream>
#include <cstring>
using namespace std;

int n, m, a, b, tmp = 0;
int arr[2004], dp[2004][2004];

void palindrom() {
	for (int i = n;i >= 1;i--) {
		for (int j = n;j >= i;j--) {
			if (i == j) {
				dp[i][j] = 1;
				continue;
			}
			if (j - i == 1 && arr[i] == arr[j]) {
				dp[i][j] = 1;
				dp[j][i] = 1;
			}
			else if (j - i == 1 && arr[i] != arr[j]) {
				dp[i][j] = 0;
				dp[j][i] = 0;
			}
			else if (j - i > 1) {
				if (dp[i + 1][j - 1] == 1 && arr[i] == arr[j]) {
					dp[i][j] = 1;
					dp[j][i] = 1;
				}
				else {
					dp[i][j] = 0;
					dp[j][i] = 0;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}

	palindrom();
	cin >> m;
	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		cout << dp[a][b] << "\n";
	}
	return 0;
}