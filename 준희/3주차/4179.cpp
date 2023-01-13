#include <iostream>
#include <queue>
#include <string>
using namespace std;
const int INF = 987654321;

int n, m, ret = 0;
char arr[1002][1002];
int dxy[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int person_check[1002][1002];
int fire_check[1002][1002];
queue<pair<int, int>> q;
queue<pair<int, int>> f;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int jy, jx = 0;
	fill(&fire_check[0][0], &fire_check[0][0] + 1002 * 1002, INF);
	fill(&person_check[0][0], &person_check[0][0] + 1002 * 1002, 0);
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < s.size();j++) {
			arr[i][j] = s[j];
			if (arr[i][j] == 'J') { jy = i; jx = j; }
			else if (arr[i][j] == 'F') {
				f.push({ i,j });
				fire_check[i][j] = 1;
			}
		}
	}

	while (f.size()) {
		int cy = f.front().first;
		int cx = f.front().second;
		f.pop();

		for (int i = 0;i < 4;i++) {
			int ny = cy + dxy[i][0];
			int nx = cx + dxy[i][1];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (fire_check[ny][nx] != INF || arr[ny][nx] == '#') continue;
			fire_check[ny][nx] = fire_check[cy][cx] + 1;
			f.push({ ny,nx });
		}
	}

	person_check[jy][jx] = 1;
	q.push({ jy,jx });
	while (q.size()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		if (cy == 0 || cx == 0 || cy == n - 1 || cx == m - 1) {
			ret = person_check[cy][cx];
			break;
		}

		for (int i = 0;i < 4;i++) {
			int ny = cy + dxy[i][0];
			int nx = cx + dxy[i][1];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (person_check[ny][nx] || arr[ny][nx] == '#') continue;
			if (person_check[cy][cx] + 1 >= fire_check[ny][nx]) continue;
			person_check[ny][nx] = person_check[cy][cx] + 1;
			q.push({ ny,nx });
		}
	}

	if (ret == 0) cout << "IMPOSSIBLE \n";
	else cout << ret << "\n";

	return 0;
}