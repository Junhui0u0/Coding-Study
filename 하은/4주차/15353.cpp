#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	vector<int> result;

	while (b.size() != a.size()) {
		if (b.size() < a.size())b.insert(0, "0");
		else if (a.size() < b.size()) a.insert(0, "0");
	}

	bool up = false;
	for (int i = b.size() - 1; i >= 0; i--) {
		int n = (a[i] - '0') + (b[i] - '0');
		if (up) n++;
		
		if (n >= 10) { 
			up = true;
			n %= 10;
		}else {
			up = false;
		}
		result.push_back(n);
	}

	if (up) result.push_back(1);
	reverse(result.begin(), result.end());
	
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
}