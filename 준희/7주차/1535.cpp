#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a1[21], a2[21], ret = 0;

int solve(int status, int fitness, int joy) {
	if (fitness >= 100)  return joy - a2[status];
	if (status == n) return joy;

	int ret = 0;
	for (int i = status;i < n;i++) {
		ret = max(ret, solve(i + 1, fitness + a1[i + 1], joy + a2[i + 1]));
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a1[i];	//Ã¼·Â
	}
	for (int i = 0;i < n;i++) {
		cin >> a2[i];	//±â»Ý
	}
	for (int i = 0;i < n;i++) {
		ret = max(ret, solve(i, a1[i], a2[i]));
	}
	cout << ret << "\n";
	return 0;
}