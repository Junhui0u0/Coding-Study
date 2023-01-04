#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int> m, m_first;
vector<pair<int, int>> v;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first) {
		return m_first[p1.second] < m_first[p2.second];
	}
	return p1.first > p2.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c;
	cin >> n >> c;

	for (int i = 0;i < n;i++) {
		int num;
		cin >> num;
		if (m_first[num] == 0) m_first[num] = i + 1;
		m[num]++;
	}

	for (auto map : m) {
		v.push_back({ map.second,map.first });
	}

	sort(v.begin(), v.end(), cmp);

	for (auto i : v) {
		for (int j = 0;j < i.first;j++) {
			cout << i.second << " ";
		}
	}

	return 0;
}