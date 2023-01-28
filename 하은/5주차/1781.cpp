#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> score;
	int ret = 0;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		score.push_back({ n1, n2 });
	}

	sort(score.begin(), score.end());

	int idx = 0;
	for (int i = 0; i < score.size(); i++) {
		pq.push(score[i].second);
		if (pq.size() > score[i].first) {
			pq.pop();
		}
	}

	while (pq.size()) {
		ret += pq.top();
		pq.pop();
	}
	cout << ret;
}