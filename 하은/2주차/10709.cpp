#include <bits/stdc++.h>
using namespace std;

int graph[9][9];

int main() {
	int h, w;
	cin >> h >> w;

	memset(graph, -1, sizeof(graph));
	
	for (int i = 1; i <= h; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= w; j++) {
			if (s[j-1] == 'c') graph[i][j] = 0;
			else if (s[j - 1] == '.' && graph[i][j - 1] != -1) graph[i][j] = graph[i][j - 1] + 1;
		}
	}

	for (int i = 1; i <= h; i++) { // 가로 횟수만큼 반복
		for (int j = 1; j <= w; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

}