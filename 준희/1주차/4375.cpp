#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	while (cin >> n) {
		int val = 1;
		int cnt = 1;
		while (true) {
			if (val%n == 0) {
				cout << cnt << "\n";
				break;
			}
			else {
				val = (val * 10) + 1;
				val %= n;
				cnt++;
			}
		}
	}

	return 0;
}