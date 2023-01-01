#include <iostream>
using namespace std;

int arr[15001];
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	if (m > 200000) cout << "0\n";
	else {
		for (int i = 0;i < n;i++) {
			for (int j = i + 1;j < n;j++) {
				if (arr[i] + arr[j] == m) cnt++;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}