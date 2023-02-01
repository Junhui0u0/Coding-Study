#include <bits/stdc++.h>
using namespace std;

int arr[1001] = { 0, };
int cnt[1001] = { 0, };
int pre[1001];

void go(int idx) {
	if (idx == -1) return;
	go(pre[idx]);
	printf("%d ", arr[idx]);
	return;
}

int main() {
	
	memset(pre, -1, sizeof(pre));

	int n;
	cin >> n;
	
	int ret = 0;
	int idx = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		int maxV = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && maxV < cnt[j]) {
				maxV = cnt[j];
				pre[i] = j;
			}
		}

		cnt[i] = maxV + 1;
		if (ret < cnt[i]) {
			ret = cnt[i];
			idx = i;
		}
	}

	cout << ret << endl;
	go(idx);
	
	
}