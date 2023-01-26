#include <iostream>
using namespace std;
const long long max_n = 100001;
typedef long long ll;

ll n, ret, s, e = 0;
ll arr[max_n], cnt[max_n];

int main() {

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	while (e < n) {
		if (!cnt[arr[e]]) {
			cnt[arr[e]]++;
			e++;
		}
		else {
			ret += (e - s);
			cnt[arr[s]]--;
			s++;
		}
	}
	ret += (e - s)*(e - s + 1) / 2;
	cout << ret << "\n";

	return 0;
}
