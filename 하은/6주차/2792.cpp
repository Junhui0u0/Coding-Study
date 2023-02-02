#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

	ll n, m;
	cin >> n >> m;

	vector<int> jewel;
	ll num;
	for (int i = 0; i < m; i++) {
		cin >> num;
		jewel.push_back(num);
	}
	sort(jewel.begin(), jewel.end());

	ll l = 1, r = jewel[m - 1];
	ll mid;
	ll ret;
	while (l <= r) {
		mid = (l + r) / 2;

		ll cnt = 0;
		for (int i = 0; i < jewel.size(); i++) {
			cnt += jewel[i] / mid;
			if (jewel[i] % mid != 0) cnt++;
		}

		if (cnt <= n) {
			r = mid - 1;
			ret = mid;
		}
		else if (cnt > n) {
			l = mid + 1;
		}

	}

	cout << ret;

}