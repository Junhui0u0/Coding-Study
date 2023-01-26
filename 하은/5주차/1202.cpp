#include <bits/stdc++.h>
using namespace std;

int n, k;
int result = 0;

int main() {

	vector<pair<int, int>> jewel;
	vector<int> bag;
	priority_queue<int> pq;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		jewel.push_back({ m, v });
	}

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bag.push_back(c);
	}

	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());

	int idx = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && jewel[idx].first <= bag[i]) {
			pq.push(jewel[idx].second);
			idx++;
		}

		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}

	cout << result << '\n';


}