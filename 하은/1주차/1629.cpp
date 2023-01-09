#include <bits/stdc++.h>
using namespace std;
long long a, b, c;

long long cal(long long a, long long b) {
	if (b == 1) return a % c;
	else {
		long long result = cal(a, b / 2);
		result = (result * result) % c;
		if (b % 2 == 1) result = (result * a) % c;
		return result;
	}
}

int main() {
	cin >> a >> b >> c;
	cout << cal(a, b) % c << endl;
}