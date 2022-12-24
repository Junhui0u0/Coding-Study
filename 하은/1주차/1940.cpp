#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	int cnt = 0;
	// 1 2 3 4 5 0 
	sort(arr.begin(), arr.end());


	for (int i = 0; i < n; i++) {
		for (int j = n-1; j>i; j--) {
			if (arr[j] == 0) continue;

			if (arr[i] + arr[j] < m) break;
			else if (arr[i] + arr[j] > m) {
				arr[j] = 0;
				continue;
			}
			else if (arr[i] + arr[j] == m) {
				cnt++;
				arr[j] = 0;
				break;
			}
		}
	}

	cout << cnt << endl;
}