#include <bits/stdc++.h>
using namespace std;

int arr[101] = { 0 };
int main() {
	int a, b, c;
	cin >> a >> b >> c;

	vector<pair<int, int>> list;
	for (int i = 0; i < 3; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		list.push_back({ n1, n2 });
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j < 3; j++) {
			if (list[j].first <= i && list[j].second >= i + 1) arr[i]++;
		}
	}

	int result = 0;
	for (int i = 1; i <= 100; i++) {
		if (arr[i] == 1) result += arr[i] * a;
		else if(arr[i] == 2) result += arr[i] * b;
		else if (arr[i] == 3) result += arr[i] * c;
	}

	cout << result << '\n';
}