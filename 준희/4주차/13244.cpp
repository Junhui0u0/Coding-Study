#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, t, s1, s2;
vector<int> v[1002];
int visited[1002];

void dfs(int a) {
	visited[a] = 1;
	for (int b : v[a]) {
		if (!visited[b]) {
			dfs(b);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n >> m;

		int flag = 0;
		memset(visited, 0, sizeof(visited));

		for (int i = 0;i < m;i++) {
			int a, b = 0;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int i = 1;i <= n;i++) {
			if (!visited[i]) {
				dfs(i);
				flag++;
			}
		}

		if (m == n - 1 && flag == 1) cout << "tree\n";
		else cout << "graph\n";
	}

	return 0;
}