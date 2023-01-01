#include <iostream>
#include <stack>
#include <string>
using namespace std;

int cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		stack<char> st;
		string s;
		cin >> s;
		for (int j = 0;j < s.size();j++) {
			if (st.size() > 0 && st.top() == s[j]) st.pop();
			else st.push(s[j]);
		}
		if (st.size() == 0) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}