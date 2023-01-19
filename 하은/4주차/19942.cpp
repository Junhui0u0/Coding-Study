#include <bits/stdc++.h>
using namespace std;

struct food {
	int p;
	int f;
	int s;
	int v;
	int c;
}food_list[16];
map<int, vector<vector<int>>> ret_v;

int stan_p, stan_f, stan_s, stan_v, stan_c;
int n;
int result_price = INT_MAX;

int main() {

	cin >> n;
	cin >> stan_p >> stan_f >> stan_s >> stan_v;
	for (int i = 0; i < n; i++) {
		cin >> food_list[i].p >> food_list[i].f >> food_list[i].s >> food_list[i].v >> food_list[i].c;
	}

	for (int i = 1; i < (1 << n); i++) {
		int p = 0, f = 0, s = 0, v = 0, c = 0;
		vector<int> list;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				list.push_back(j + 1);
				p += food_list[j].p;
				f += food_list[j].f;
				s += food_list[j].s;
				v += food_list[j].v;
				c += food_list[j].c;
			}
		}
		if (p >= stan_p && f >= stan_f && s >= stan_s && v >= stan_v) {
			if (result_price >= c) {
				result_price = c;
				ret_v[result_price].push_back(list);
			}
		}
	}
	if (result_price == INT_MAX) cout << -1 << '\n';
	else {
		sort(ret_v[result_price].begin(), ret_v[result_price].end());
		cout << result_price << "\n";
		for (int a : ret_v[result_price][0]) {
			cout << a << " ";
		}
	}
}