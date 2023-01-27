#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;

int n, k, ret = 0;
int arr[101], chk[101];
vector<int> v;

int main() {

	cin >> n >> k;
	for (int i = 0;i < k;i++) {
		cin >> arr[i];
	}

	for (int i = 0;i < k;i++) {
		if (!chk[arr[i]]) {
			if (v.size() == n) {
				int last_idx = 0; int pos = 0;
				for (int a : v) {
					int here_pick = INF;
					for (int j = i + 1;j < k;j++) {
						if (a == arr[j]) {
							here_pick = j;
							break;
						}
					}
					if (last_idx < here_pick) {
						last_idx = here_pick;
						pos = a;
					}
				}
				chk[pos] = 0;
				ret++;
				v.erase(find(v.begin(), v.end(), pos));
			}
			v.push_back(arr[i]);
			chk[arr[i]] = 1;
		}
	}

	cout << ret << "\n";

	return 0;
}
