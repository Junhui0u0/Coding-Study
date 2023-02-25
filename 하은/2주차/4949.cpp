#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	while (s != ".") {
		stack<char> str;
		bool flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[') str.push(s[i]);
			else if (s[i] == ')') {
				if (str.empty() || str.top() != '(') {
					flag = false;
					break;
				}
				else str.pop();
			}
			else if (s[i] == ']') {
				if (str.empty() || str.top() != '[') {
					flag = false;
					break;
				}
				else str.pop();
			}
		}

		if (!str.empty()) flag = false;
		
		if (flag) cout << "yes" << '\n';
		else cout << "no" << '\n';
		flag = true;
		getline(cin, s);
	}

}