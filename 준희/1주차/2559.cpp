#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
using namespace std;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0;i < n;i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	priority_queue<int> sum;
	int tmp = accumulate(v.begin(), v.begin() + k, 0);
	sum.push(tmp);
	for (int i = 1;i <= v.size() - k;i++) {
		tmp = tmp - v[i - 1] + v[i + k - 1];
		sum.push(tmp);
	}

	cout << sum.top() << "\n";

	return 0;
}