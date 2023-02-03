#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n, m, l, r, mid = 0;
int arr1[1000001], arr2[1000001];
vector<int> ret;

void binarySearch(int idx) {
	int flag = 0;
	l = 0; r = n - 1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (arr2[idx] < arr1[mid]) r = mid - 1;
		else if (arr2[idx] == arr1[mid]) {
			flag = 1;
			break;
		}
		else l = mid + 1;
	}
	if (flag) ret.push_back(1);
	else ret.push_back(0);
}

int main() {
	cin >> t;
	while (t--) {
		ret.clear();
		cin >> n;
		for (int i = 0;i < n;i++) {
			cin >> arr1[i];
		}
		cin >> m;
		for (int i = 0;i < m;i++) {
			cin >> arr2[i];
		}
		sort(arr1, arr1 + n);
		for (int i = 0;i < m;i++) {
			binarySearch(i);
		}
		for (int a : ret) cout << a << "\n";
	}
	return 0;
}