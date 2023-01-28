#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int graph[51][51] = { 0, };
int toadd[51][51] = { 0, };
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void spread(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c || graph[ny][nx] == -1) continue;
		toadd[ny][nx] += graph[y][x] / 5;
		cnt++;
	}
	toadd[y][x] += (-1) * cnt * (graph[y][x] / 5);
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> graph[i][j];
		}
	}
	 

	while (t--) {
		
		// 확산
		fill(&toadd[0][0], &toadd[0][0] + 51 * 51, 0);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if(graph[i][j] != 0 && graph[i][j] != -1) spread(i, j);
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				graph[i][j] += toadd[i][j];
			}
		}
		


		//공기청정기
		fill(&toadd[0][0], &toadd[0][0] + 51 * 51, -10);
		int idx = 0;
		for (int i = 0; i < r; i++) {
			if (graph[i][0] == -1) {
				idx = i;
				break;
			}
		}

		// 가로 오른쪽 확산
		for (int i = 2; i < c; i++) {
			toadd[idx][i] = graph[idx][i - 1];
			toadd[idx + 1][i] = graph[idx + 1][i - 1];
		}
		graph[idx][1] = graph[idx + 1][1] = 0;

		
		// 세로 위 확산
		for (int i = idx - 1; i >= 0; i--) {
			toadd[i][c - 1] = graph[i + 1][c - 1];
		}
		for (int i = r - 2; i > idx + 1; i--) {
			toadd[i][0] = graph[i + 1][0];
		}

		// 가로 왼쪽 확산
		for (int i = c-2; i >= 0; i--) {
			toadd[0][i] = graph[0][i + 1];
			toadd[r-1][i] = graph[r-1][i + 1];
		}
		
		// 세로 아래 확산
		for (int i = 1; i < idx; i++) {
			toadd[i][0] = graph[i - 1][0];
		}
		for (int i = idx + 2; i < r; i++) {
			toadd[i][c - 1] = graph[i - 1][c - 1];
		}
		
		// 바뀐 곳은 대체
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if(toadd[i][j] != -10) graph[i][j] = toadd[i][j];
			}
		}
	}

	// 합 계산
	long long sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (graph[i][j] != -1) sum += graph[i][j];
		}
	}
	cout << sum;
	
}