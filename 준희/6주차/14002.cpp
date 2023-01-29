#include <iostream>
using namespace std;

int n, idx = 0;
int arr[1001], cnt[1001], prev_list[1001];
int ret = 1;

void func(int idx) {
	if (idx == -1) return;
	func(prev_list[idx]);
	cout << arr[idx] << " ";
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	fill(cnt, cnt + 1001, 1);
	fill(prev_list, prev_list + 1001, -1);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < i;j++) {
			if (arr[i] > arr[j] && cnt[i] < cnt[j] + 1) {
				cnt[i] = cnt[j] + 1;
				prev_list[i] = j;
				if (ret < cnt[i]) {
					ret = cnt[i];
					idx = i;
				}
			}
		}
	}

	cout << ret << "\n";
	func(idx);
	cout << "\n";

	return 0;
}