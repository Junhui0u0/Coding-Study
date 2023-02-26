#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10001];
int visited[10001] = { 0, };

int main() {
	
	vector<pair<int, int>> v;
	
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		graph[n2].push_back(n1);
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;

		queue<int> q;
		q.push(i);

		visited[i] = 1;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int j = 0; j < graph[x].size(); j++) {
				int num = graph[x][j];
				if (!visited[num]) {
					q.push(num);
					visited[num] = 1;
					cnt++;
				}
			}
		}

		v.push_back({ cnt, i });
		memset(visited, 0, sizeof(visited));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == v[v.size() - 1].first) {
			cout << v[i].second << " ";
		}
	}

}