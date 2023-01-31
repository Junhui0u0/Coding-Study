#include <bits/stdc++.h>
using namespace std;

int arr[1001] = { 0, };
int cnt[1001] = { 0, };
int main() {
	int n;
	cin >> n;

	int ret = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		int maxV = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && maxV < cnt[j]) maxV = cnt[j];
		}
		cnt[i] = maxV + 1;
	}

	ret = *max_element(cnt, cnt + n);

	cout << ret;
}