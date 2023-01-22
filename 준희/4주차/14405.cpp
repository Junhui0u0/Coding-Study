#include <iostream>
#include <string>
using namespace std;

string s;
string sa[3] = { "pi","ka","chu" };
int flag = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	for (int i = 0;i < s.size();i++) {
		for (string a : sa) {
			if (s.substr(i, a.size()) == a) {
				i += a.size() - 1;
				flag = 0;
				break;
			}
			else flag = 1;
		}
		if (flag) break;
	}

	if (flag) cout << "NO\n";
	else cout << "YES\n";

	return 0;
}