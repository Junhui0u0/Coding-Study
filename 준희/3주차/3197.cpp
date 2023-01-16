#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int max_n = 1502;

int r, c;
char arr[max_n][max_n];
int visited[max_n][max_n], visited_swan[max_n][max_n];
queue<pair<int, int>> water_q, water_temp_q, swan_q, swan_temp_q;
int dxy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int swan_y, swan_x;
int ret = 0;

void q_clear(queue<pair<int, int>> &q) {
	queue<pair<int, int>> empty;
	swap(q, empty);
}

void water_melting() {
	while (water_q.size()) {
		int cy = water_q.front().first;
		int cx = water_q.front().second;
		water_q.pop();

		for (int i = 0;i < 4;i++) {
			int ny = cy + dxy[i][0];
			int nx = cx + dxy[i][1];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;

			if (arr[ny][nx] == 'X') {
				visited[ny][nx] = 1;
				water_temp_q.push({ ny,nx });
				arr[ny][nx] = '.';
			}
		}
	}
}

bool move_swan() {
	while (swan_q.size()) {
		int cy = swan_q.front().first;
		int cx = swan_q.front().second;
		swan_q.pop();

		for (int i = 0;i < 4;i++) {
			int ny = cy + dxy[i][0];
			int nx = cx + dxy[i][1];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited_swan[ny][nx]) continue;
			visited_swan[ny][nx] = 1;
			if (arr[ny][nx] == '.') swan_q.push({ ny,nx });
			else if (arr[ny][nx] == 'X') swan_temp_q.push({ ny,nx });
			else if (arr[ny][nx] == 'L') return true;
		}
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'L') { swan_y = i; swan_x = j; }
			if (arr[i][j] == '.' || arr[i][j] == 'L') { visited[i][j] = 1; water_q.push({ i,j }); }
		}
	}

	swan_q.push({ swan_y,swan_x });
	visited_swan[swan_y][swan_x] = 1;
	while (true) {
		if (move_swan()) break;
		water_melting();
		water_q = water_temp_q;
		swan_q = swan_temp_q;
		q_clear(water_temp_q);
		q_clear(swan_temp_q);
		ret++;
	}

	cout << ret << "\n";

	return 0;
}