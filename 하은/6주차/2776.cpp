#include <bits/stdc++.h>
using namespace std;



int find(int x, vector<int> &v1) {
	int l = 0, r = v1.size() - 1;
	int mid = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (x < v1[mid]) r = mid - 1;
		else if (x > v1[mid]) l = mid + 1;
		else if (x == v1[mid]) return 1;
	}
	return 0;
}

int main() {
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int ret1 = a;
	int ret2 = b;

	vector<int> v1;
	vector<int> v2;

	int num;
	for (int i = 0; i < a; i++) {
		cin >> num;
		v1.push_back(num);
	}
	for (int i = 0; i < b; i++) {
		cin >> num;
		v2.push_back(num);
	}

	for (int i = 0; i < a; i++) {
		if (find(v2.begin(), v2.end(), v1[i]) != v2.end()) {
			ret1--;
			ret2--;
		}
	}

	cout << ret1 + ret2;
}
	int t;
	cin >> t;

	while (t--) {


		vector<int> v1;
		vector<int> v2;

		int n, m;
		cin >> n;
		
		int num;
		for (int i = 0; i < n; i++) {
			cin >> num;
			v1.push_back(num);
		}
		sort(v1.begin(), v1.end());

		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> num;
			v2.push_back(num);
		}

		for (int i = 0; i < m; i++) {
			cout << find(v2[i], v1) << '\n';
		}
	}

}