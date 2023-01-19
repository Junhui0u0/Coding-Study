#include <bits/stdc++.h>
using namespace std;
int n;
int sum_true = 0;
int sum_false = 0;
int result = INT_MAX;
int people[11] = { 0, };
bool comp[11] = { 0, };
bool comp2[11] = { 0, };
bool visited[11] = { 0, };
vector<int> adj_list[11];

void dfs(int x, bool flag) {
    visited[x] = 1;
    if (flag) sum_true += people[x-1];
    else sum_false += people[x-1];

    for (int i = 0; i < adj_list[x].size(); i++) {
        if (visited[adj_list[x][i]] == 0 && comp[adj_list[x][i]] == flag) {
            dfs(adj_list[x][i], flag);
        }
    }
    
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }

    int cntq;
    int num;
    for (int i = 1; i <= n; i++) {
        cin >> cntq;
        for (int j = 0; j < cntq; j++) {
            cin >> num;
            adj_list[i].push_back(num);
        }
    }

    int cnt = 0;

    for (int i = 1; i < (1 << n) - 1; i++) {
        sum_true = 0, sum_false = 0;
        cnt = 0;
        fill(comp, comp + 11, 0);
        fill(visited, visited + 11, 0);
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) comp[j + 1] = 1;
        }

        for (int j = 1; j <= n; j++) {
            
            if (!visited[j]) {
                dfs(j, comp[j]);
                cnt++;
            }
           
        }

        if (cnt == 2) {
            result = min(result, abs(sum_true - sum_false));
        }
    }

    cout << (result == INT_MAX ? -1 : result) << "\n";
}