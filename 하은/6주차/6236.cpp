#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

bool check(int x) {

	int backup = x;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (x - v[i] >= 0) {
			x -= v[i];
		}
		else {
			x = backup;
			cnt++;
			if (v[i] > x) return false;
			x -= v[i];
		}
	}
	return cnt <= m;

}
int main() {

	cin >> n >> m;


	int num;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		sum += num;
		v.push_back(num);
	}

	int l = 0, r = sum;
	int ret;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;  // k원 (전체인출액)

		if (check(mid)) {
			ret = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ret;

}