#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		stack<char> st;
		string s;
		cin >> s;

		for (int i = 0;i < s.size();i++) {
			if (st.size() == 0) {
				st.push(s[i]);
				continue;
			}

			char top = st.top();
			if (top == '('&&s[i] == ')') st.pop();
			else st.push(s[i]);
		}

		if (st.size() == 0) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}