#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int arr[100001] = { 0, };
	vector<int> sum;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}



	//초기값 셋팅
	int int_sum = 0;
	for (int i = 0; i < k; i++) {
		int_sum += arr[i];
	}
	sum.push_back(int_sum);

	for (int i = 0; i < n - k; i++) {
		sum.push_back(sum[i] + arr[i+k] - arr[i]);
	}

	cout << *max_element(sum.begin(), sum.end());


/*	시간초과 코드
	vector<int> arr;
	vector<int> sum;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	for (int i = 0; i <= n - k; i++) {
		sum.push_back(accumulate(arr.begin() + i, arr.begin() + i + k, 0));
	}

	cout << *max_element(sum.begin(), sum.end());*/
}