#include <iostream>
#include <string>
using namespace std;

string s1, s2, ret;

int main() {

	cin >> s1 >> s2;

	for (char c : s1) {
		ret += c;
		if (ret.size() >= s2.size() && ret.substr(ret.size() - s2.size(), s2.size()) == s2) {
			ret.erase(ret.size() - s2.size(), s2.size());
		}
	}

	if (ret.size()) cout << ret << "\n";
	else cout << "FRULA\n";

	return 0;
}