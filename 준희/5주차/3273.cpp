#include <iostream>
#include <map>
#include <string>
using namespace std;

int n, x, ret = 0;
int arr[100001];
map<string, int> m;
string s;

int main() {

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		m[to_string(arr[i])]++;
	}
	cin >> x;

	for (int i = 0;i < n;i++) {
		if (m[to_string(x - arr[i])] != 0) ret++;
	}

	cout << ret / 2 << "\n";

	return 0;
}
