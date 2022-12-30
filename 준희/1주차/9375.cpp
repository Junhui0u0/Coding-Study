#include <iostream>
#include <string>
#include <map>
#include <vector>
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
		map<string, int> m;
		for (int i = 0;i < n;i++) {
			string name, type;
			cin >> name >> type;
			m[type]++;
		}

		int mul = 1;
		for (auto map : m) {
			mul *= map.second + 1;
		}
		mul--;
		cout << mul << "\n";
	}

	return 0;
}