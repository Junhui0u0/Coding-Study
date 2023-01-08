#include <bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int two = 0, five = 0;
		for (int i = 2; i <= n; i *= 2) two += n / i;
		for (int i = 5; i <= n; i *= 5) five += n / i;

		cout << min(two, five) << '\n';
	}
}