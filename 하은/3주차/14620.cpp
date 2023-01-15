#include <bits/stdc++.h>
using namespace std;

int n;
int graph[10][10] = { 0, }; 
int visited[10][10] = { 0, };
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int depth = 0;
int ret = INT_MAX;

bool check(int y, int x) {
	if (visited[y][x]) return false;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) {
			return  false;
		}
	}
	return true;
}

int setflower(int y, int x) {
	visited[y][x] = 1;
	int s = graph[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 1;
		s += graph[ny][nx];
	}
	return s;
}

void eraseflower(int y, int x) {
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 0;
	}
}

void flower(int cnt, int hap) {
	if (cnt == 3){
		ret = min(ret, hap);
		return;
	}
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (check(i, j)) {
				flower(cnt+1, hap + setflower(i, j));
				eraseflower(i, j);
				
			}
		}
	}
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	flower(0, 0);

	cout << ret;
}