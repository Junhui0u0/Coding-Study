#include <bits/stdc++.h>
using namespace std;

int n;
int result = INT_MIN;
char arr[20];

int cal(int a, int b, char op) {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
}

void dfs(int idx, int sum) {

	if (idx > n - 1) {
		result = max(result, sum);
		return;
	}

	char op;
	if (idx == 0) op = '+';
	else op = arr[idx - 1];
	
	// °ýÈ£·Î ¹­´Â °æ¿ì
	if (idx + 2 < n) {
		int br = cal(arr[idx] - '0', arr[idx + 2] - '0', arr[idx + 1]);
		dfs(idx + 4, cal(sum, br, op));
	}

	// °ýÈ£·Î ¾È¹­´Â °æ¿ì
	dfs(idx + 2, cal(sum, arr[idx]-'0', op));
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) { 
		cin >> arr[i];
	}	

	dfs(0, 0);

	cout << result << endl;
	
}