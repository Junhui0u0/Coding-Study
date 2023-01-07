#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string s;
		getline(cin, s);
		if (s == ".") break;

		stack<char> st;
		for (int i = 0;i < s.size();i++) {
			if (s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']') {
				if (st.size() == 0) {
					st.push(s[i]);
					continue;
				}

				char top = st.top();
				if (top == '(' && s[i] == ')') st.pop();
				else if (top == '[' && s[i] == ']') st.pop();
				else st.push(s[i]);
			}
		}

		if (st.size() == 0) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}