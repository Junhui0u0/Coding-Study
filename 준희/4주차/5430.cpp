#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int t, n, x;
string s1, s2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> s1 >> n >> s2;

		deque<int> d;
		x = 0;
		for (char c : s2) {
			if (c == '[' || c == ']') continue;
			if (c >= '0'&&c <= '9') x = x * 10 + c - '0';
			else {
				if (x > 0) d.push_back(x);
				x = 0;
			}
		}
		if (x > 0) d.push_back(x);

		bool er = false, rev = false;
		for (char c : s1) {
			if (c == 'R') rev = !rev;
			else {
				if (d.empty()) {
					er = true;
					break;
				}
				if (rev) d.pop_back();
				else d.pop_front();
			}
		}
		if (er) cout << "error\n";
		else {
			cout << "[";
			if (rev) reverse(d.begin(), d.end());
			for (int i = 0;i < d.size();i++) {
				cout << d[i];
				if (i < d.size() - 1) cout << ",";
			}
			cout << "]\n";
		}
	}
	return 0;
}