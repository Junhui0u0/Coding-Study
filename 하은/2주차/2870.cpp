#include <bits/stdc++.h>
using namespace std;

bool cmp(string str1, string str2) {
	if (str1.size() == str2.size()) return str1 < str2;
	else return str1.size() < str2.size();
}


int main() {
	int n;
	cin >> n;

	vector<string> s_list;

	while (n--) {

		string s;
		cin >> s;

		string num = "";
		for (int i = 0; i < s.size(); i++) {
			if (isdigit(s[i])) num += s[i];
			else if (num.size() != 0) { 
				while (num.size() > 1 && num[0] == '0') {
					num.erase(0, 1);
				}
				s_list.push_back(num);
				num = "";
			}
		}
		if (num.size() != 0) {
			while (num.size() > 1 && num[0] == '0') {
				num.erase(0, 1);
			}
			s_list.push_back(num);
			num = "";
		}
	}

	sort(s_list.begin(), s_list.end(), cmp);


	for (int i = 0; i < s_list.size(); i++) {
		cout << s_list[i] << endl;
	}
}