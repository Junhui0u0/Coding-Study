#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[101][101] = { 0, };
int depth[101][101] = { 0, };
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int res = 0;

void bfs(int y, int x) {
    depth[y][x] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));


    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int sy = front.first + dy[i];
            int sx = front.second + dx[i];

            if (sy < 0 || sy >= n || sx < 0 || sx >= m) continue;

            if (graph[sy][sx] != 0 && depth[sy][sx] == 0) {
                depth[sy][sx] = depth[front.first][front.second] + 1;
                q.push(make_pair(sy, sx));
            }
        }
    }


}

int main() {
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            graph[i][j] = s[j] - '0';
        }
    }

    bfs(0, 0);

    cout << depth[n - 1][m - 1] << endl;
}