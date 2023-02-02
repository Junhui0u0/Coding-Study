#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, num, l, r, mid, flag = 0;
vector<int> v;
int ret = 0;

int main() {
	cin >> a >> b;
	for (int i = 0;i < a;i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	ret = v.size();
	for (int i = 0;i < b;i++) {
		cin >> num;
		l = 0; r = v.size() - 1;
		flag = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (num < v[mid]) r = mid - 1;
			else if (num == v[mid]) {
				flag = 1;
				break;
			}
			else l = mid + 1;
		}

		if (flag) ret--;
		else ret++;
	}
	cout << ret << "\n";
	return 0;
}