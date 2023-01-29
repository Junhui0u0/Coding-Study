#include <iostream>
#include <algorithm>
using namespace std;

int n, m, mid, r;
int arr[300001];
int ret = 987654321;
int l = 1;

bool chk(int a) {
	int num = 0;
	for (int i = 0;i < m;i++) {
		num += arr[i] / mid;
		if (arr[i] % mid) num++;
	}
	return n >= num;
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		cin >> arr[i];
		r = max(r, arr[i]);
	}

	while (l <= r) {
		mid = (l + r) / 2;
		if (chk(mid)) {
			ret = min(ret, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ret << "\n";

	return 0;
}