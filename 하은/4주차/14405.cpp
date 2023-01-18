#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	bool flag = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'p' && s[i] != 'k' && s[i] != 'c') {
			flag = false;
			break;
		}
		else if (s[i] == 'p') {
			if (s[i + 1] != 'i') {
				flag = false;
				break;
			}
			else i++;
		}
		else if (s[i] == 'k') {
			if (s[i + 1] != 'a') {
				flag = false;
				break;
			}
			else i++;
		}
		else if (s[i] == 'c') {
			if (s[i + 1] != 'h' || s[i+2] != 'u') {
				flag = false;
				break;
			}
			else i+=2;
		}
	}

	if (flag) cout << "YES";
	else cout << "NO";
}