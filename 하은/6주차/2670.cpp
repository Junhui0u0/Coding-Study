#include <bits/stdc++.h>
using namespace std;

double dp[10001];
double arr[10001];
int main() {
	
	int n;
	cin >> n;

	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	double mx = 0.0;
	mx = dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] * arr[i], arr[i]);
		mx = max(mx, dp[i]);
	}

	printf("%.3f", mx);
}