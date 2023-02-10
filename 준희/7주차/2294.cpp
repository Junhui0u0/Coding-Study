#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;

int n, k, num, arr[10004];

int main() {
	cin >> n >> k;
	fill(arr, arr + 10004, INF);
	arr[0] = 0;			//important
	for (int i = 0;i < n;i++) {
		cin >> num;
		for (int j = num;j <= k;j++) {
			arr[j] = min(arr[j], arr[j - num] + 1);
		}
	}
	if (arr[k] == INF) cout << -1 << "\n";
	else cout << arr[k] << "\n";
	return 0;
}