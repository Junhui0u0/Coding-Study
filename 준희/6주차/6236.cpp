#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, m, l, r, mid, sum, ret = 0;
ll arr[100001];

bool chk(ll mid) {
	int tmpSum = mid; int cnt = 1;

	for (int i = 0;i < n;i++) {
		tmpSum -= arr[i];
		if (tmpSum < 0) {
			if (arr[i] > mid) return false;
			cnt++;
			tmpSum = mid;
			tmpSum -= arr[i];
		}
	}
	return m >= cnt;
}

int main() {
	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	l = 0; r = sum;
	while (l <= r) {
		mid = (l + r) / 2;
		if (chk(mid)) {
			r = mid - 1;
			ret = mid;
		}
		else l = mid + 1;
	}
	cout << ret << "\n";

	return 0;
}