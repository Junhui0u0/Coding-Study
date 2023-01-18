#include <iostream>
using namespace std;
const int max_n = 102;

int n, l;
int arr[max_n][max_n];
int rev_arr[max_n][max_n];
int ret = 0;

void solve(int a[max_n][max_n]) {
	for (int i = 0;i < n;i++) {
		int cnt = 1;
		int j;
		for (j = 0;j < n - 1;j++) {
			if (a[i][j] == a[i][j + 1]) cnt++;
			else if (a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1;
			else if (a[i][j] - 1 == a[i][j + 1] && cnt >= 0) cnt = -l + 1;
			else break;
		}
		if (j == n - 1 && cnt >= 0) ret++;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
			rev_arr[j][i] = arr[i][j];
		}
	}

	solve(arr);
	solve(rev_arr);
	cout << ret << "\n";

	return 0;
}