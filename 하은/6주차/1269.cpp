#include <bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;
	
	map<int, int> m;

	int num;
	for (int i = 0; i < a; i++) {
		cin >> num;
		m[num]++;
	}

	int cnt = 0;
	for (int i = 0; i <b; i++) {
		cin >> num;
		if (m[num]) cnt++;
	}
	cout << a + b - cnt * 2;
}