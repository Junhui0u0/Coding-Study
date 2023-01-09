#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;

	while (cin >> n) {
		int cnt = 1; int ret = 1;
		while (true) {
			if (ret % n == 0) {
				cout << cnt << endl;
				break;
			}
			else {
				ret = (ret * 10) % n + 1 % n;
				cnt++;
			}
		}
	}
}