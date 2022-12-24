#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		map<string, int> list;
		int n;
		cin >> n;
		while (n--) {
			string s1, s2;
			cin >> s1 >> s2;

			if (list.find(s2) == list.end()) {
				list.insert({ s2, 1 });
			}
			else {
				list[s2]++;
			}
		}

		int result = 1; // 각 원소들 중에서 공집합 추가 해 하나씩 고르기
		for (map<string, int>::iterator it = list.begin(); it != list.end(); it++) {
			result *= (it->second + 1);
		}
		cout << result - 1 << '\n'; // 공집합 제거

	
	}

}