//알파벳 개수: 26
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[26] = { 0 };
	string s;

	cin >> s;

	for (int i = 0;i < s.size();i++) {
		arr[s[i] - 'a'] ++;
	}

	for (int i = 0;i < 26;i++) cout << arr[i] << " ";

	return 0;
}
