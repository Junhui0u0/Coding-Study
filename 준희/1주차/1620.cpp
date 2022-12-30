#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<string> v;
	map<string, int> map;
	for (int i = 1;i <= n;i++) {
		string s;
		cin >> s;
		v.push_back(s);
		map[s] = i;
	}

	for (int i = 0;i < m;i++) {
		string s;
		cin >> s;
		if (s[0] >= '1'&&s[0] <= '9') {
			int num = stoi(s);
			cout << v[num - 1] << "\n";
		}
		else {
			cout << map[s] << "\n";
		}
	}

	return 0;
}