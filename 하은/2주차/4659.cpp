#include <bits/stdc++.h>
using namespace std;

int main() {
	
	while (true) {
		string s;
		cin >> s;
		if (s == "end") break;
		
		vector<bool> vowel;
		bool first_flag = false;
		bool second_flag = true;
		bool third_flag = true;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') vowel.push_back(true);
			else vowel.push_back(false);
		}

		for (int i = 0; i < s.size(); i++) {
			// 모음 하나라도 존재
			if (vowel[i]) first_flag = true;
		}

		if (s.size() >= 3) {
			for (int i = 0; i < s.size() - 2; i++) {
				// 모음 세 개 연속, 자음 세 개 연속 불가
				if (vowel[i] == false && vowel[i + 1] == false && vowel[i + 2] == false) second_flag = false;
				if (vowel[i] == true && vowel[i + 1] == true && vowel[i + 2] == true) second_flag = false;
			}
		}
		
		if (s.size() >= 2) {
			for (int i = 0; i < s.size() - 1; i++) {
				// 모음 세 개 연속, 자음 세 개 연속 불가
				if (s[i] == 'e' || s[i] == 'o') continue;
				if (s[i] == s[i + 1]) third_flag = false;
			}
		}

		if (first_flag && second_flag && third_flag) cout << "<" + s + "> is acceptable." << endl;
		else cout << "<" + s + "> is not acceptable." << endl;

	}
}