#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

int n, d, p;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
ll ret = 0;

int main() {

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> p >> d;
		v.push_back({ d,p });
	}

	sort(v.begin(), v.end());

	for (int i = 0;i < v.size();i++) {
		pq.push(v[i].second);
		if (pq.size() > v[i].first) pq.pop();
	}

	while (pq.size()) {
		ret += pq.top();
		pq.pop();
	}
	cout << ret << "\n";

	return 0;
}