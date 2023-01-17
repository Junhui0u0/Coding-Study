#include <bits/stdc++.h>
using namespace std;

int depth[100001] = { 0, };
int cnt[100001] = { 0, };
int n, k;

void bfs() {
	queue<int> q;
	q.push(n);
	cnt[n] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == k) break;

		if (x + 1 <= 100000 && depth[x + 1] == 0) {
			q.push(x + 1);
			depth[x + 1] = depth[x] + 1;
			cnt[x + 1] += cnt[x];
		}
		else if (x + 1 <= 100000 && depth[x + 1] == depth[x] + 1) {
			cnt[x + 1] += cnt[x];
		}

		if (x - 1 >= 0 && depth[x - 1] == 0) {
			q.push(x - 1);
			depth[x - 1] = depth[x] + 1;
			cnt[x - 1] += cnt[x];
		}
		else if (x - 1 >= 0 && depth[x - 1] == depth[x] + 1) {
			cnt[x - 1] += cnt[x];
		}

		if (2 * x <= 100000 && depth[2 * x] == 0) {
			q.push(2 * x);
			depth[2 * x] = depth[x] + 1;
			cnt[2 * x] += cnt[x];
		}
		else if (2 * x <= 100000 && depth[2 * x] == depth[x] + 1) {
			cnt[2 * x] += cnt[x];
		}
	}
}

int main() {
	cin >> n >> k;
	bfs();
	cout << depth[k] << endl;
	cout << cnt[k] << endl;
}