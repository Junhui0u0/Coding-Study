#include <iostream>
using namespace std;

int x, ret = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x;

	for (int i = 0;i <= 6;i++) {
		if (x&(1 << i)) {
			ret++;
		}
	}
	cout << ret << "\n";

	return 0;
}