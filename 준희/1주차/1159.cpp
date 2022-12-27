#include <iostream>
#include <string>
using namespace std;

int arr[26] = { 0 };
string ans = "";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		arr[s[0] - 'a']++;
	}

	for (int i = 0;i < 26;i++) {
		char c = 'a' + i;
		if (arr[i] >= 5) ans += c;
	}

	if (ans == "") cout << "PREDAJA\n";
	else cout << ans << "\n";

	return 0;
}
