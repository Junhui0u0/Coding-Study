#include <iostream>
#include <string>
using namespace std;

int n;
int arr[65][65];
string ret = "";

void func(int a, int b, int size) {
	if (size == 0) return;
	int check0 = 0;
	int check1 = 0;
	for (int i = a;i < a + size;i++) {
		for (int j = b;j < b + size;j++) {
			if (arr[i][j] == 0) check0++;
			else check1++;
		}
	}

	if (check0 == size * size)  ret += "0";
	else if (check1 == size * size) ret += "1";
	else {
		ret += "(";
		func(a, b, size / 2);
		func(a, b + size / 2, size / 2);
		func(a + size / 2, b, size / 2);
		func(a + size / 2, b + size / 2, size / 2);
		ret += ")";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < s.size();j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	func(0, 0, n);
	cout << ret << "\n";

	return 0;
}