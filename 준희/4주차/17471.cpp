#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int INF = 987654321;

int n, sum, start, start2, cnt, cnt2, tmp = 0;
int info[12];
vector<int> v[12];
int ret = INF;
int visited[12], visited2[12];
int chk[12], chk2[12];

void dfs(int start) {
	visited[start] = 1;
	cnt--;
	tmp -= info[start];

	for (int i = 0;i < v[start].size();i++) {
		int next = v[start][i];
		if (visited[next] || chk[next] == 0) continue;
		dfs(next);
	}
	return;
}

void dfs2(int start) {
	visited2[start] = 1;
	cnt2--;

	for (int i = 0;i < v[start].size();i++) {
		int next = v[start][i];
		if (visited2[next] || chk2[next] == 0) continue;
		dfs2(next);
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> info[i];
		sum += info[i];
	}
	for (int i = 1;i <= n;i++) {
		int a;
		cin >> a;
		for (int j = 1;j <= a;j++) {
			int b;
			cin >> b;
			v[i].push_back(b);
		}
	}

	for (int i = 1;i < (1 << n) - 1;i++) {
		cnt = 0; cnt2 = 0;
		tmp = sum;
		memset(visited, 0, sizeof(visited));
		memset(chk, 0, sizeof(chk));
		memset(visited2, 0, sizeof(visited2));
		memset(chk2, 0, sizeof(chk2));

		for (int j = 0;j < n;j++) {
			if (i&(1 << j)) {
				chk[j + 1] = 1;
				start = j + 1;
				cnt++;
			}
			else {
				chk2[j + 1] = 1;
				start2 = j + 1;
				cnt2++;
			}
		}

		dfs(start);
		dfs2(start2);
		if (!cnt && !cnt2) {
			ret = min(ret, abs(tmp - (sum - tmp)));
		}
	}

	if (ret == INF) cout << "-1\n";
	else cout << ret << "\n";

	return 0;
}