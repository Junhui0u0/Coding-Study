#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string s1, s2, ret;
stack<char> st;

int main() {

	cin >> s1 >> s2;

	for (char c : s1) {
		st.push(c);
		if (st.size() >= s2.size() && (st.top() == s2[s2.size() - 1])) {

			string tmp = "";
			for (char a : s2) {
				tmp += st.top();
				st.pop();
			}
			reverse(tmp.begin(), tmp.end());

			if (tmp != s2) {
				for (char a : tmp) st.push(a);
			}
		}
	}

	if (st.size()) {
		while (st.size()) {
			ret += st.top();
			st.pop();
		}
		reverse(ret.begin(), ret.end());
		cout << ret << "\n";
	}
	else cout << "FRULA\n";

	return 0;
}