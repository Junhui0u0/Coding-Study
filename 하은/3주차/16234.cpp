#include <bits/stdc++.h>
using namespace std;

int graph[50][50];
int visited[50][50];
vector<pair<int, int>> depth;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1 , 0, -1 };
int union_n = 0;
int n, l, r;
int cnt = 0;

void cal(int y, int x) {
	for (int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] != 0) continue;
		if (abs(graph[ny][nx] - graph[y][x]) >= l && abs(graph[ny][nx] - graph[y][x]) <= r) {
			visited[ny][nx] = 1;
			depth.push_back({ ny, nx });
			union_n += graph[ny][nx];
			cal(ny, nx);
		}
	}

}
int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	while (true) {
		bool flag = 0;
		fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
					depth.clear();
					visited[i][j] = 1;
					depth.push_back({ i,j });
					union_n = graph[i][j];
					cal(i, j);
					if (depth.size() == 1) continue;
                    for(pair<int,int> b : depth){ 
						graph[b.first][b.second] = union_n / depth.size();
						flag = 1;
                    }
                } 
            }
        }
        if(!flag) break;  
        cnt++;
    } 
	cout << cnt << endl;
}