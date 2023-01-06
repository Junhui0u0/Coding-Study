#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;

bool cmp(string s1, string s2) {
	if (s1.size() == s2.size()) return s1 < s2;
	return s1.size() < s2.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		for (int i = 0;i < s.size();i++) {
			if (s[i] >= '1'&&s[i] <= '9') {
				int cnt = 1;
				for (int j = i + 1;j < s.size();j++) {
					if (s[j] >= 'a'&&s[j] <= 'z') break;
					else cnt++;
				}
				v.push_back(s.substr(i, cnt));
				i += cnt - 1;
			}
			else if (s[i] == '0') {
				if (i == s.size() - 1) v.push_back("0");
				else if (s[i + 1] >= 'a'&&s[i + 1] <= 'z') v.push_back("0");
			}
		}
	}

	sort(v.begin(), v.end(), cmp);
	for (string ret : v) cout << ret << "\n";

	return 0;
}