#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nodes[51];
int n, root, removeNum = 0;

int dfs(int r) {
	int ret = 0;
	int child = 0;
	for (int i = 0;i < nodes[r].size();i++) {
		if (nodes[r][i] == removeNum) continue;
		ret += dfs(nodes[r][i]);
		child++;
	}
	if (child == 0) return 1;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0;i < n;i++) {
		int num;
		cin >> num;
		if (num == -1) root = i;
		else nodes[num].push_back(i);
	}

	cin >> removeNum;

	if (removeNum == root) cout << "0\n";
	else cout << dfs(root) << "\n";

	return 0;
}