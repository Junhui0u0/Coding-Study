#include <bits/stdc++.h>
using namespace std;

int graph[101][101] = { 0, };
int visited[101][101] = { 0, };
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;
int n, m, cnt, cnt2;

void dfs(int y, int x) {
    visited[y][x] = 1;
    if (graph[y][x] == 1) {
        v.push_back({ y,x });
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])continue;
        dfs(ny, nx);
    }
    return;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

    while (true) {
        cnt++;

        // 마지막에 녹을 예정인 치즈의 갯수 세기
        cnt2 = 0;
        memset(visited, 0, sizeof(visited));
        v.clear();
        dfs(0, 0);
        for (pair<int, int> b : v) {
            cnt2++;
            graph[b.first][b.second] = 0;
        }

        // 치즈가 다 녹았는지 확인
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] != 0) flag = 1;
            }
        }
        
        if (!flag) break;
    }
    cout << cnt << '\n' << cnt2 << '\n';

}