#include <iostream>
#include <string>
using namespace std;

bool check1(string s) {
	for (int i = 0;i < s.size();i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') return true;
	}
	return false;
}

bool check2(string s) {
	int vowel = 0;
	int consonant = 0;
	for (int i = 0;i < s.size();i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			if (consonant > 0) {
				vowel = 1;
				consonant = 0;
			}
			else vowel++;
		}
		else {
			if (vowel > 0) {
				consonant = 1;
				vowel = 0;
			}
			else consonant++;
		}
		if (vowel == 3 || consonant == 3) return false;
	}
	return true;
}

bool check3(string s) {
	for (int i = 0;i < s.size() - 1;i++) {
		if (s[i] == s[i + 1] && s[i] != 'e'&&s[i] != 'o') return false;
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string s;
		cin >> s;
		if (s == "end") break;
		else {
			string temp = "";
			temp += "<"; temp += s; temp += ">";
			if (check1(s) && check2(s) && check3(s)) cout << temp << " is acceptable.\n";
			else cout << temp << " is not acceptable.\n";
		}
	}

	return 0;
}