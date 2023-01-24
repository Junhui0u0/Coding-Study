#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> room;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		room.push_back({ e, s });
	}

	sort(room.begin(), room.end());
	int time = 0;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (time <= room[i].second) {
			cnt++;
			time = room[i].first;
		}
	}

	cout << cnt;
}