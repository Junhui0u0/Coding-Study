#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	bool flag = true;
	while (n--) {
		stack<char> s;
		string str;
		cin >> str;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') s.push(str[i]);
			else if (str[i] == ')' && s.empty()) {
				flag = false;
				break;
			}
			else if (str[i] == ')' && s.top() == '(') s.pop();
		}

		if (!s.empty()) flag = false;
		if (flag) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		flag = true;
	}
}