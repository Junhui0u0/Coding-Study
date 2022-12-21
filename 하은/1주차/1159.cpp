#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[26] = { 0, };
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		arr[s[0] - 97]++;
	}

	bool flag = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) {
			cout << (char)(i + 97);
			flag = true;
		}
	}

	if (!flag) cout << "PREDAJA";
}