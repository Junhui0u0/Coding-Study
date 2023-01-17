#include <iostream>
#include <algorithm>
using namespace std;
const int max_n = 22;
const int INF = 987654321;

int n;
char arr[max_n][max_n];
int ret = INF;

int solve(int row) {
	int sum = 0;

	for (int i = 0;i < n;i++) {
		int tmp = 0;
		for (int j = 0;j < n;j++) {
			if (arr[j][i] == 'H' && (row&(1 << j))) tmp++;
			else if (arr[j][i] == 'T' && !(row&(1 << j))) tmp++;
		}
		tmp = min(n - tmp, tmp);
		sum += tmp;
	}

	return sum;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0;i < (1 << n);i++) {
		ret = min(ret, solve(i));
	}

	cout << ret << "\n";

	return 0;
}