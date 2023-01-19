#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int max_n = 27;

int n, k;
int alph[max_n];
int ret = 0;
vector<string> sv;
vector<int> v;

void solve(int start, int cnt) {
	if (cnt == k - 5) {
		int sum = 0;
		for (string s : sv) {
			int chk = 1;
			for (char c : s) {
				if (!alph[c - 'a']) {
					chk = 0;
					break;
				}
			}
			if (chk) sum++;
		}
		ret = max(ret, sum);
		return;
	}

	for (int i = start;i < 27;i++) {
		if (alph[i]) continue;
		if (i == 0 || i == 13 || i == 19 || i == 8 || i == 2) continue;
		alph[i] = 1;
		v.push_back(i);
		solve(i + 1, cnt + 1);
		v.pop_back();
		alph[i] = 0;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		sv.push_back(s);
	}

	if (k < 5) {
		cout << 0 << "\n";
		return 0;
	}

	alph['a' - 'a'] = 1;
	alph['n' - 'a'] = 1;
	alph['t' - 'a'] = 1;
	alph['i' - 'a'] = 1;
	alph['c' - 'a'] = 1;

	solve(0, 0);
	cout << ret << "\n";

	return 0;
}