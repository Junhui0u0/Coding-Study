#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int n, num;
stack<int> st;
int arr[1000002], ret[1000002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	memset(ret, -1, sizeof(ret));
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		while (st.size() && arr[st.top()] < arr[i]) {
			ret[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 0;i < n;i++) cout << ret[i] << " ";

	return 0;
}