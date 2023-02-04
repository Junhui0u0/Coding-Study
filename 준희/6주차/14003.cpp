#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int n, lis[1000004], len, num;
pair<int, int> ans[1000004];
stack<int> st;

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> num;
		auto lower_pos = lower_bound(lis, lis + len, num);
		int pos = (int)(lower_bound(lis, lis + len, num) - lis);
		if (*lower_pos == 0) len++;
		*lower_pos = num;
		ans[i].first = pos;
		ans[i].second = num;
	}
	cout << len << "\n";
	for (int i = n - 1;i >= 0;i--) {
		if (ans[i].first == len - 1) {
			st.push(ans[i].second);
			len--;
		}
	}
	while (st.size()) {
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}