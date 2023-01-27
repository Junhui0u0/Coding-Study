#include <bits/stdc++.h>
using namespace std;

int graph[21][21] = { 0, };
int visited[21] = { 0, };
int ret = INT_MAX;
int n;

void find(int idx, int size) {
	if (size == n / 2) {
		vector<int> a;
		vector<int> b;
		int a_size = 0;
		int b_size = 0;

		for (int i = 1; i <= n; i++) {
			if (visited[i]) a.push_back(i);
			else b.push_back(i);
		}

		for (int i = 0; i < a.size()-1; i++) {
			for (int j = i+1; j < a.size(); j++) {
				a_size += graph[a[i]][a[j]] + graph[a[j]][a[i]];
			}
		}

		for (int i = 0; i < b.size()-1; i++) {
			for (int j = i+1; j < b.size(); j++) {
				b_size += graph[b[i]][b[j]] + graph[b[j]][b[i]];
			}
		}

		ret = min(ret, abs(a_size - b_size));
		return;
	}

	for (int i = idx; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			find(i, size + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];

		}
	}

	find(1, 0);

	cout << ret;

}