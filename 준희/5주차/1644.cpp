#include <iostream>
#include <vector>
using namespace std;

int n, ret = 0;
vector<int> v;	//소수집합
int chk[4000001];

void cnt(int idx, int sum) {
	if (sum == n) {
		ret++;
		return;
	}
	else if (sum > n) return;

	for (int i = idx;i < v.size();i++) {
		cnt(i + 1, sum + v[i]);
		break;
	}
	return;
}

int main() {

	cin >> n;
	for (int i = 2;i <= n;i++) {
		if (chk[i]) continue;
		for (int j = 2 * i;j <= n;j += i) {
			chk[j] = 1;
		}
	}

	for (int i = 2;i <= n;i++) {
		if (!chk[i]) v.push_back(i);
	}

	for (int i = 0;i < v.size();i++) {
		cnt(i, 0);
	}
	cout << ret << "\n";

	return 0;
}

/*
두 포인터
	while (true) {
		if (sum >= n) sum -= arr[low++];
		else if (high == last) break;
		else sum += arr[high++];

		if (sum == n) ret++;
	}
*/