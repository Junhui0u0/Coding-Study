#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, j, l, r, temp, ret = 0;
	cin >> n >> m;
	cin >> j;

	l = 1;
	for (int i = 0;i < j;i++) {
		r = l + m - 1;
		cin >> temp;
		if (temp >= l && temp <= r) continue;
		else {
			if (temp < l) {
				ret += l - temp;
				l = temp;
			}
			else {
				l += (temp - r);
				ret += temp - r;
			}
		}
	}
	cout << ret << "\n";
	return 0;
}