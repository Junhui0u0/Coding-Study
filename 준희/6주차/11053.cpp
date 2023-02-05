#include <iostream>
using namespace std;

int n, idx, ret = 1;
int arr[1001], length[1001], prev_idx[1001];

void func(int idx) {
	if (idx == -1) return;
	func(prev_idx[idx]);
	cout << arr[idx] << " ";
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	fill(prev_idx, prev_idx + 1001, -1);
	for (int i = 0;i < n;i++) {
		length[i] = 1;
		for (int j = 0;j < i;j++) {
			if (arr[i] > arr[j] && (length[i] < length[j] + 1)) {
				length[i] = length[j] + 1;
				prev_idx[i] = j;
				if (ret < length[i]) {
					ret = length[i];
					idx = i;
				}
			}
		}
	}

	cout << ret << "\n";
	//func(idx);

	return 0;
}