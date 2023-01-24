#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> cow;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		cow.push_back({ n1, n2 });
	}
	
	sort(cow.begin(), cow.end());
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (cow[i].first >= cnt) {
			cnt = cow[i].first + cow[i].second;
		}
		else {
			cnt = cnt + cow[i].second;
		}
	}

	cout << cnt;
	
}