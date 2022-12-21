#include <bits/stdc++.h>
using namespace std;

int main() {

	string str1;
	cin >> str1;

	string str2 = str1;
	reverse(str1.begin(), str1.end());

	if (str1 == str2) cout << 1 << endl;
	else cout << 0 << endl;
}