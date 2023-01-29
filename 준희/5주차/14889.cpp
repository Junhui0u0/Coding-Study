#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int arr[21][21];
bool chk[21];
int ret = 987654321;

void func(int cnt, int pos) {
	if (cnt == n / 2) {
		int a = 0; int b = 0;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (chk[i] == true && chk[j] == true) a += arr[i][j];
				else if (chk[i] == false && chk[j] == false) b += arr[i][j];
			}
		}
		ret = min(ret, abs(a - b));
		return;
	}

	for (int i = pos;i < n;i++) {
		chk[i] = true;
		func(cnt + 1, i + 1);
		chk[i] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
		}
	}

	func(0, 0);
	cout << ret << "\n";

	return 0;
}
