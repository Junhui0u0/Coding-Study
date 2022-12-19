#include <bits/stdc++.h>
using namespace std;

int main() {
	int eng_arr[26] = { 0, };
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		eng_arr[s[i] - 97]++;
	}

	for (int i = 0; i < 26; i++) {
		cout << eng_arr[i] << " ";
	}

}