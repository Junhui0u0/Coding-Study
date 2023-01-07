#include <bits/stdc++.h>
using namespace std;

map<int, int> num_list;
map<int, int> order;

bool cmp(pair<int, int> a, pair<int, int>b) {
	if (a.second == b.second) {
		return order[a.first] < order[b.first];
	}
	return a.second > b.second;
}
int main() {


	int n, c;
	cin >> n >> c;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		num_list[num]++;
		if (order[num] == 0) order[num] = i + 1;
	}

	vector<pair<int, int>> num_vec;
	for (auto it : num_list) {
		num_vec.push_back({ it.first, it.second });
	}
	
	sort(num_vec.begin(), num_vec.end(), cmp);
	
	for (int i = 0; i < num_vec.size(); i++) {
		for (int j = 0; j < num_vec[i].second; j++) {
			cout << num_vec[i].first << " ";
		}
	
	}
}