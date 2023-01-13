#include <iostream>
#include <queue>
using namespace std;
const int MAX = 500000;

int n, k, chk;
int visited[2][MAX + 4];
int t = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	if (n == k) {
		cout << "0\n";
		return 0;
	}
	queue<int> q;
	visited[0][n] = 1;
	q.push(n);
	while (q.size()) {
		k += t;
		if (k > MAX) break;
		if (visited[t % 2][k]) {
			chk = 1;
			break;
		}
		int q_size = q.size();
		for (int i = 0;i < q_size;i++) {
			int now = q.front();
			q.pop();
			for (int next : {now - 1, now + 1, now * 2}) {
				if (next<0 || next>MAX || visited[t % 2][next]) continue;
				visited[t % 2][next] = visited[(t + 1) % 2][now] + 1;
				if (next == k) {
					chk = 1;
					break;
				}
				q.push(next);
			}
			if (chk) break;
		}
		if (chk) break;
		t++;
	}

	if (chk) cout << t << "\n";
	else cout << "-1\n";

	return 0;
}
