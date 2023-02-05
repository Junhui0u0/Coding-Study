#include <iostream>
#include <algorithm>
using namespace std;

int n;
double arr[10001];
double l, r, mid, ret = 0.0;

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	for (int i = 0;i < n;i++) {
		double tmp = 1.0;
		tmp *= arr[i];
		ret = max(ret, tmp);
		for (int j = i + 1;j < n;j++) {
			tmp *= arr[j];
			ret = max(ret, tmp);
		}
	}
	cout << fixed;
	cout.precision(3);
	cout << ret << "\n";
	return 0;
}