#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 200000;
typedef long long ll;

int n, k, num;
queue<int> q;
ll visited[MAX + 2];
int tmp[MAX + 2];
vector<int> ret;

void bfs(int n) {
	visited[n] = 1;
	q.push(n);

	while (q.size()) {
		int now = q.front();
		q.pop();

		for (int next : {now - 1, now + 1, now * 2}) {
			if (0 <= next && next <= MAX) {
				if (!visited[next]) {
					visited[next] = visited[now] + 1;
					q.push(next);
					tmp[next] = now;
					if (next == k) return;
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	if (n == k) {
		cout << 0 << "\n";
		cout << n << "\n";
	}
	else {
		bfs(n);
		cout << visited[k] - 1 << "\n";

		while (true) {
			if (k == n) {
				ret.push_back(k);
				break;
			}
			ret.push_back(k);
			k = tmp[k];
		}
		reverse(ret.begin(), ret.end());
		for (int a : ret) cout << a << " ";
		cout << "\n";
	}

	return 0;
}