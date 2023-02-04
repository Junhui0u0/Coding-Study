#include <iostream>
using namespace std;
typedef long long ll;

ll n, m, l, r, mid, ret, tmp = 0;
ll arr[10001];

bool chk(ll mid) {
	ll cnt = m;
	for (ll i = 0;i < m;i++) cnt += mid / arr[i];
	return cnt >= n;
}

int main() {
	cin >> n >> m;
	for (ll i = 0;i < m;i++) {
		cin >> arr[i];
	}

	if (n <= m) {
		cout << n << "\n"; return 0;
	}

	l = 1; r = 60000000000;
	while (l <= r) {
		mid = (l + r) / 2;
		if (chk(mid)) {
			r = mid - 1;
			ret = mid;
		}
		else l = mid + 1;
	}

	tmp = m;
	for (ll i = 0;i < m;i++) tmp += (ret - 1) / arr[i];

	for (ll i = 0;i < m;i++) {
		if (ret%arr[i] == 0) tmp++;
		if (tmp == n) {
			cout << i + 1 << "\n";
			return 0;
		}
	}
	return 0;
}