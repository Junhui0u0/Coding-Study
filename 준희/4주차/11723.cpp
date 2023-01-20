#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int m, x;
int chk[21];
int all[21] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
int emp[21] = { 0, };
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m;
	while (m--) {
		cin >> s;
		if (s == "add") {
			cin >> x;
			chk[x] = 1;
		}
		else if (s == "remove") {
			cin >> x;
			chk[x] = 0;
		}
		else if (s == "check") {
			cin >> x;
			if (chk[x]) cout << "1\n";
			else cout << "0\n";
		}
		else if (s == "toggle") {
			cin >> x;
			if (chk[x]) chk[x] = 0;
			else chk[x] = 1;
		}
		else if (s == "all") {
			swap(chk, all);
		}
		else if (s == "empty") {
			swap(chk, emp);
		}
	}

	return 0;
}