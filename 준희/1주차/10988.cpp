#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	string rs = s;
	reverse(rs.begin(), rs.end());

	if (s == rs) cout << "1\n";
	else cout << "0\n";

	return 0;
}
