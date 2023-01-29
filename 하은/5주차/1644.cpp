#include <bits/stdc++.h>
using namespace std;

bool arr[400001] = { 0, };


int main() {
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		if (arr[i]) continue;
		for (int j = 2 * i; j <= n; j += i) {
			arr[j] = 1;
		}
	}

	vector<int> prime;
	for (int i = 2; i <= n; i++) {
		if (!arr[i]) prime.push_back(i);
	}

	int sum = 0;
	int ans = 0;
	int s = 0, e = 0;

	while (1) {
		if (sum > n) {
			sum -= prime[s];
			s++;
		}
		else if (sum < n) {
			if (e >= prime.size()) break;
			sum += prime[e];
			e++;
		}
		else {
			ans++;
			if (e >= prime.size()) break;
			sum += prime[e];
			e++;
		}
	}

	cout << ans;

}