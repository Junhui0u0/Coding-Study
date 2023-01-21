#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int arr[5][5];
int ret = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < m;j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	for (int x = 0;x < (1 << (n*m));x++) {
		int sum = 0;
		for (int i = 0;i < n;i++) {
			int cur = 0;
			for (int j = 0;j < m;j++) {
				int k = i * m + j;
				if ((x&(1 << k)) == 0) {
					cur = cur * 10 + arr[i][j];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		for (int j = 0;j < m;j++) {
			int cur = 0;
			for (int i = 0;i < n;i++) {
				int k = i * m + j;
				if ((x&(1 << k)) != 0) {
					cur = cur * 10 + arr[i][j];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		ret = max(ret, sum);
	}

	cout << ret << "\n";

	return 0;
}