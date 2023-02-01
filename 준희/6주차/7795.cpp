#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int t, n, m, ret = 0;
ll a[20001], b[20001];
ll l, r, mid;


int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0;i < n;i++) {
			cin >> a[i];
		}
		for (int i = 0;i < m;i++) {
			cin >> b[i];
		}

		sort(a, a + n);
		sort(b, b + m);
		ret = 0;
		for (int i = 0;i < n;i++) {
			l = 0; r = m - 1;
			while (l <= r) {
				mid = (l + r) / 2;
				if (a[i] <= b[mid]) r = mid - 1;
				else l = mid + 1;
			}
			mid = (l + r) / 2;
			if (mid >= 0 && l > 0) ret += mid + 1;
		}
		cout << ret << "\n";
	}
	return 0;
}