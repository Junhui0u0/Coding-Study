#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, ret = 0;
int arr[3] = { 0, };
int info[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 1, 9},
	{3, 9, 1},
	{1, 3, 9},
	{1, 9, 3}
};
int visited[62][62][62];

struct A {
	int a, b, c;
};

queue<A> q;

int solve(int a, int b, int c) {
	visited[a][b][c] = 1;
	q.push({ a,b,c });

	while (q.size()) {
		int ca = q.front().a;
		int cb = q.front().b;
		int cc = q.front().c;
		q.pop();

		if (visited[0][0][0]) break;

		for (int i = 0;i < 6;i++) {
			int na = max(0, ca - info[i][0]);
			int nb = max(0, cb - info[i][1]);
			int nc = max(0, cc - info[i][2]);

			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[ca][cb][cc] + 1;
			q.push({ na, nb, nc });
		}

	}
	return visited[0][0][0] - 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	cout << solve(arr[0], arr[1], arr[2]) << "\n";

	return 0;
}