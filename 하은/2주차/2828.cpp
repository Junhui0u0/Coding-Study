#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	int begin = 1, end = 1 + m - 1;
	
	int j;
	cin >> j;

	int ret = 0;
	while (j--) {
		int temp;
		cin >> temp;

		if (temp >= begin && temp <= end) continue;
		if (temp < begin) {
			ret += begin - temp;
			begin = temp;
			end = begin + m - 1;
		}
		else if (temp > end) {
			ret += temp - end;
			end = temp;
			begin = temp - m + 1;
		}
	}
	
	cout << ret << endl;

}