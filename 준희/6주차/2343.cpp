#include <iostream>
#include <algorithm>
using namespace std;

int n, m, r, mid, sum, ret = 0;
int arr[100001];
int l = -1;

bool chk(int mid) {
	int cnt = 0, tmp = 0;
	for (int i = 0;i < n;i++) {
		//if (arr[i] > mid) return false;  -> low defined (arr[i] smallest)
		tmp += arr[i];
		if (tmp > mid) {
			tmp = arr[i];
			cnt++;
		}
	}
	if (tmp > 0) cnt++;
	return m >= cnt;
}

int main() {
	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		sum += arr[i];
		l = max(l, arr[i]);		//low defined
	}

	r = sum;
	while (l <= r) {
		mid = (l + r) / 2;
		if (chk(mid)) {
			r = mid - 1;
			ret = mid;
		}
		else l = mid + 1;
	}
	cout << l << "\n";

	return 0;
}