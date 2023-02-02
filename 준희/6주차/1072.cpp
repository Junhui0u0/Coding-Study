#include <iostream>
using namespace std;
typedef long long ll;

ll x, y, l, r, mid = 0;
ll ret = -1;

int main() {
	cin >> x >> y;

	if (x == y) {
		cout << "-1\n";
		return 0;
	}

	ll z = y * 100 / x;
	l = 0; r = 1e9;
	while (l <= r) {
		mid = (l + r) / 2;
		if ((y + mid) * 100 / (x + mid) > z) {
			ret = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ret << "\n";
	return 0;
}