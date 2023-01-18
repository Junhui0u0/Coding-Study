#include <bits/stdc++.h>
using namespace std;

vector<int> split(string input, string deli) {
	vector<int> ret;
	long long idx = 0;
	string token = "";
	while (idx = (input.find(deli)) != string::npos) {
		token = input.substr(0, idx);
		ret.push_back(stoi(token));
		input.erase(0, idx + deli.size());
	}
	ret.push_back(stoi(input));
	return ret;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int cnt;
		cin >> cnt;

		string arr;
		cin >> arr;
		arr.erase(0, 1);
		arr.erase(arr.size() - 1, 1);

		bool error_flag = false;
		bool reverse_flag = false;

		int x = 0;
		deque<int> result;
		for (char c : arr) {
			if (c == '[' || c == ']') continue;
			if (c >= '0' && c <= '9') x = x * 10 + c - '0';
			else {
				if (x > 0) result.push_back(x);
				x = 0;
			}
		}
		if (x > 0) result.push_back(x);

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'R') {
				reverse_flag = !reverse_flag;
			}
			else if (s[i] == 'D') {
				if (result.empty()) {
					error_flag = true;
					cout << "error" << endl;
					break;
				}
				if (reverse_flag) result.pop_back();
				else result.pop_front();
			}
		}

		if (!error_flag) {
			if (reverse_flag) reverse(result.begin(), result.end());
			cout << "[";
			if (result.size() != 0) {
				for (int i = 0; i < result.size() - 1; i++) {
					cout << result[i] << ",";
				}
				cout << result[result.size() - 1];
			}
			cout << "]" << '\n';
		}
	}

}