#include <iostream>
#include <string>
#include <map>
using namespace std;
const long long max_n = 100001;
typedef long long ll;

int n, ret, st, en = 0;
int arr[max_n];
string s;
map<string, int> m;

int main() {

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	int tmp = 0;
	while (tmp < n) {
		for (int i = 0;i < n;i++) {
			st = i; en = st + tmp;
			if (en >= n) break;

			s = "";
			for (int j = st;j <= en;j++) {
				s += to_string(arr[j]);
			}

			if (m[s] == 0) {
				m[s] = 1;
				ret++;
			}
		}
		tmp++;
	}
	cout << ret << "\n";

	return 0;
}
