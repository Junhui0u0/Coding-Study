#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll s, c, l, r, mid, ret, sum = 0;
ll arr[1000001];

bool chk(ll mid) {
	ll cnt = 0;
	for (int i = 0;i < s;i++) {
		cnt += arr[i] / mid;
	}
	return cnt >= c;
}

int main() {
	cin >> s >> c;
	l = 1; r = 1e9;
	for (int i = 0;i < s;i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	while (l <= r) {
		mid = (l + r) / 2;
		if (chk(mid)) {
			l = mid + 1;
			ret = mid;
		}
		else r = mid - 1;
	}
	cout << sum - ret * c << "\n";
	return 0;
}