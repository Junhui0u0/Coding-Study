#include <iostream>
#include <queue>
using namespace std;
const int MAX = 500000;

int n, k;
int ret = -1;
int visited[MAX + 2];
queue<int> q;

int cal(int time) {
	int sum = 0;
	for (int i = 1;i < time;i++) {
		sum += i;
	}
	return sum;
}

void bfs(int n) {
	visited[n] = 1;
	q.push(n);

	while (q.size()) {
		int now = q.front();
		q.pop();

		if (now == cal(visited[now]) + k) {
			ret = visited[now] - 1;
			return;
		}

		for (int next : {now - 1, now + 1, now * 2}) {
			if (0 <= next && next <= MAX) {
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}
	}
	ret = -1;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	bfs(n);
	/*
		for (int i = 0;i <= MAX - k;i++) {
			/*
			if (i == visited[k+ cal(i)]) {
				ret = i;
				break;
			}

			if (i == visited[k+ cal(i)]) {
				ret = i;
				break;
			}
			if (k + cal(i) > MAX) break;
		}
	*/
	cout << ret << "\n";

	return 0;
}