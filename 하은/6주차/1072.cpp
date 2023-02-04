#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	double x, y;
	cin >> x >> y;
	ll z = y * 100 / x ;

	ll l = 1, r = 1000000000;
	ll mid;
	ll ret = -1;
	while (l <= r) {
		mid = (l + r) / 2;

		ll tmp = (y + mid) * 100 / (x + mid);
		if (tmp > z) {
			ret = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	
	}
	
	cout << ret;
}