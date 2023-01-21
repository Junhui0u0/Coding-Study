#include <bits/stdc++.h>
using namespace std;

int arr[21];

int main() {
	int m;
	cin >> m;

	string s;
	int x;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (s == "add") {
			cin >> x;
			arr[x] = 1;
		}
		else if (s == "remove") {
			cin >> x;
			arr[x] = 0;
		}
		else if (s == "check") {
			cin >> x;
			cout << arr[x] << '\n';
		}
		else if (s == "toggle") {
			cin >> x;
			if (arr[x]) arr[x] = 0;
			else arr[x] = 1;
		}
		else if (s == "all") {
			fill(arr, arr + 21, 1);
		}
		else if (s == "empty") {
			fill(arr, arr + 21, 0);
		}

	}

}