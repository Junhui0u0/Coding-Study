#include <bits/stdc++.h>
using namespace std;

int depth[200001] = { 0, };
int prev_arr[200001] = { 0, };
vector<int> road;
int n, k;

void bfs() {
	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == k) break;

		if (x + 1 <= 200000 && depth[x + 1] == 0) {
			q.push(x + 1);
			depth[x + 1] = depth[x] + 1;
			prev_arr[x + 1] = x;
		}
		if (x - 1 >= 0 && depth[x - 1] == 0) {
			q.push(x - 1);
			depth[x - 1] = depth[x] + 1;
			prev_arr[x - 1] = x;
		}
		if (2 * x <= 200000 && depth[2 * x] == 0) {
			q.push(2 * x);
			depth[2 * x] = depth[x] + 1;
			prev_arr[2 * x] = x;
		}
	}
}

int main() {
	cin >> n >> k;
	bfs();
	cout << depth[k] << endl;
	
	for (int i = k; i != n; i = prev_arr[i]) {
		road.push_back(i);
	}
	road.push_back(n);
	reverse(road.begin(), road.end());
	for (int i = 0; i < road.size(); i++) {
		cout << road[i] << " ";
	}

}