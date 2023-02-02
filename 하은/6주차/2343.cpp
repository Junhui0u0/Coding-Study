#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> lec;
	int num;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		sum += num;
		lec.push_back(num);
	}

	int l = 0, r = sum;
	int mid;
	int ret = 0;
	while (l <= r) {
		mid = (l + r) / 2;

		bool flag = true;

		int tmp = mid;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (mid < lec[i]) {
				flag = false;
				break;
			}

			if (tmp - lec[i] < 0) {
				tmp = mid;
				cnt++;
			}
			tmp -= lec[i];
		}
		if (mid != tmp) cnt++;


		if (cnt > m || !flag) {
			l = mid + 1;
		}
		else {
			ret = mid;
			r = mid - 1;
		}
	
	}

	cout << ret << '\n';

}