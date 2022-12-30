#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string s, first, last = "";
	cin >> s;

	int cnt = 0;
	for (int i = 0;i < s.size();i++) {
		if (s[i] == '*') break;
		cnt++;
	}
	first = s.substr(0, cnt);
	last = s.substr(cnt + 1);

	for (int i = 0;i < n;i++) {
		string name;
		cin >> name;

		if (first.size() + last.size() > name.size()) cout << "NE\n";
		else if ((name.substr(0, cnt) == first) && (name.substr(name.size() - last.size()) == last)) cout << "DA\n";
		else cout << "NE\n";
	}

	return 0;
}