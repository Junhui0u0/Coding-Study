#include <iostream>
typedef long long ll;
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		if (n < 5) cout << 0 << "\n";
		else {
			ll ret = 0;
			ll fix = 5;

			while (fix <= n) {
				ret += n / fix;
				fix *= 5;
			}
			cout << ret << "\n";
		}
	}

	return 0;
}