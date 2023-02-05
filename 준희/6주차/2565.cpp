#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a, b, ret = 0;
vector<pair<int, int>> v;
int len[101];

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	for (int i = 0;i < n;i++) {
		len[i] = 1;
		for (int j = 0;j < i;j++) {
			if (v[i].second > v[j].second) {
				len[i] = max(len[i], len[j] + 1);
				ret = max(ret, len[i]);
			}
		}
	}
	cout << n - ret << "\n";
	return 0;
}