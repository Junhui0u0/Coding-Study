#include <iostream>
using namespace std;

int cost[4] = { 0 };
int time[101] = { 0 };
int sum = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cost[1] >> cost[2] >> cost[3];

	for (int i = 0;i < 3;i++) {
		int a, b = 0;
		cin >> a >> b;
		for (int i = a;i < b;i++) {
			time[i]++;
		}
	}

	for (int i = 1;i <= 100;i++) {
		if (time[i] == 0) continue;
		else if (time[i] == 1) sum += cost[1];
		else if (time[i] == 2) sum += cost[2] * 2;
		else if (time[i] == 3) sum += cost[3] * 3;
	}

	cout << sum << "\n";

	return 0;
}
