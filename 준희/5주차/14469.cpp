#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b, ret = 0;
vector<pair<int, int>> v;

int main() {

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	for (int i = 0;i < v.size();i++) {
		if (v[i].first >= ret) ret = v[i].first + v[i].second;
		else ret += v[i].second;
	}
	cout << ret << "\n";

	return 0;
}