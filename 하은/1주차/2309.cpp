#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr;
	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	int sum = 0;
	do {
		sum = accumulate(arr.begin(), arr.begin() + 7, 0);
		if (sum == 100) break;
	} while (next_permutation(arr.begin(), arr.end()));

	

	for (int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}
}
