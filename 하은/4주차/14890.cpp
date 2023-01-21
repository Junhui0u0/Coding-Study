#include <bits/stdc++.h>
using namespace std;

int n, l;
int ret = 0;
int graph1[100][100] = { 0, };
int graph2[100][100] = { 0, };

void solve(int a[100][100]) {
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		int j;
		for (j = 0; j < n - 1; j++) {
			if(a[i][j] == a[i][j + 1])cnt++; 
            else if(a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1; 
            else if(a[i][j] == a[i][j + 1] + 1 && cnt >= 0) cnt = -l + 1; 
            else break;
		}
		if (j == n - 1 && cnt >= 0) ret++;
	}
	return;
}

int main() {
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph1[i][j];
			graph2[j][i] = graph1[i][j];
		}
	}

	solve(graph1);
	solve(graph2);
	
	cout << ret;

}