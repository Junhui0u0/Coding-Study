#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int num = 0;
	for (int i = 666; i < INT_MAX; i++) {
		if (n == 0) break;
		if (to_string(i).find("666") != string::npos) {
			n--;
			num = i;
		}
	}

	cout << num;

}