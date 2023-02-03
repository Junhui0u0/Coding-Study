#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> b;

int main() {

	int t;
	cin >> t;
	while (t--) {

		int a_size, b_size;
		cin >> a_size >> b_size;

		int num;
		for (int i = 0; i < a_size; i++) {
			cin >> num;
			a.push_back(num);
		}
		for (int i = 0; i < b_size; i++) {
			cin >> num;
			b.push_back(num);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int ret = 0;
		int idx = 0;
		for (int i = 0; i < a_size; i++) {
			idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			ret += idx;
		}
		
		cout << ret << '\n';
		a.clear();
		b.clear();
	
	}
}