#include <bits/stdc++.h>
using namespace std;

int n, k;
int visited[26] = { 0, };
int max_cnt = 0;
vector<string> str;

void check(int start, int size) {
	if (size+5 == k) {
		int cnt = 0;
		for (int i = 0; i < str.size(); i++) {
			bool flag = true;
			string s = str[i];
			for (int j = 0; j < s.size(); j++) {
				if (!visited[s[j] - 97]) {
					flag = false;
					break;
				}
			}
			if (flag) cnt++;
		}
		max_cnt = max(max_cnt, cnt);
		return;
	}

	for (int i = start; i < 26; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			check(i, size + 1);
			visited[i] = 0;
		}
	}
}


int main() {

	visited['a' - 97] = visited['n' - 97] = visited['t' - 97] = visited['i' - 97] = visited['c' - 97] = 1;
	
	cin >> n >> k;
	if (k < 5) {
		cout << 0;
		return 0; 
	}

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		str.push_back(s);
	}

	check(0, 0);

	cout << max_cnt;
}