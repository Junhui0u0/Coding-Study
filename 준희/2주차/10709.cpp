#include <iostream>
#include <string>
using namespace std;

int ret[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int h, w;
	cin >> h >> w;

	for (int i = 0;i < h;i++) {
		string s;
		cin >> s;

		int c_check = 0;
		int cnt = 0;
		for (int j = 0;j < s.size();j++) {
			if (s[j] == '.') {
				if (c_check == 0 && cnt == 0) ret[i][j] = -1;
				else if (c_check > 0) {
					cnt++;
					ret[i][j] = cnt;
				}
			}
			else if (s[j] == 'c') {
				ret[i][j] = 0;
				c_check++;
				if (cnt > 0) cnt = 0;
			}
		}
	}

	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}