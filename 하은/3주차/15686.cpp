#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[50][50];
int result = 0;
vector<vector<int>> chickenList;
vector<pair<int, int>> home, chicken;

void combi(int start, vector<int> v) {
    if (v.size() == m) {
        // 인덱스 값을 저장
        chickenList.push_back(v);
        return;
    }
    for (int i = start + 1; i < chicken.size(); i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];

            if (graph[i][j] == 1) home.push_back({ i, j });
            if (graph[i][j] == 2) chicken.push_back({ i, j });
		}
	}

    // 치킨 집 m개 고르기
    vector<int> v;
    combi(-1, v);

    for (vector<int> cList : chickenList) {
        int ret = 0; // 현재 차례의 치킨 거리
        for (pair<int, int> home_one : home) {
            int _min = INT_MAX;
            for (int ch : cList) {
                int dist = abs(home_one.first - chicken[ch].first) + abs(home_one.second - chicken[ch].second);
                _min = min(_min, dist);
            }
            ret += _min;
        }
        result = min(result, ret);
    }
    cout << result;
}