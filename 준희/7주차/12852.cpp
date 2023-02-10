#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, dp[1000004];
int min_ret = 987654321;
vector<int> ret_v;
vector<int> v;

void solve(int cur_value, int cnt) {
	if (cur_value < 1) return;
	int &ret = dp[cur_value];
	if (ret < cnt + 1 && ret>0) return;
	ret = cnt;

	if (cur_value == 1) {
		min_ret = min(min_ret, ret - 1);
		ret_v = v;
		return;
	}
	if (cur_value % 3 == 0) {
		v.push_back(cur_value / 3);
		solve(cur_value / 3, ret + 1);
		v.pop_back();
	}
	if (cur_value % 2 == 0) {
		v.push_back(cur_value / 2);
		solve(cur_value / 2, ret + 1);
		v.pop_back();
	}
	v.push_back(cur_value - 1);
	solve(cur_value - 1, ret + 1);
	v.pop_back();
}

int main() {
	cin >> n;
	if (n == 1) {
		cout << 0 << "\n" << 1 << "\n";
		return 0;
	}
	v.push_back(n);
	solve(n, 1);
	cout << min_ret << "\n";
	for (int a : ret_v) cout << a << " ";
	return 0;
}

/*
1. setting dp value -> with dp (main)
2. trace graph -> (go function)

int dp[1000004], n;
const int INF = 987654321;
void go(int here){
	if(here == 0) return;
	cout<<here<<" ";
	if(here % 3 == 0 && dp[here] == (dp[here / 3] + 1)) go(here / 3);
	else if(here % 2 == 0 && dp[here] == (dp[here / 2] + 1))go(here / 2);
	else if((here - 1 >= 0) && (dp[here] == (dp[here - 1] + 1))) go(here - 1);
	return;
}
int main() {
	cin>>n;
	fill(dp, dp + 1000004, INF);
	dp[1] = 0;
	for(int i = 1; i <= n; i++){
		if(!(i % 3)) dp[i] = min(dp[i / 3] + 1, dp[i]);
		if(!(i % 2)) dp[i] = min(dp[i / 2] + 1, dp[i]);
		dp[i] = min(dp[i - 1] + 1, dp[i]);
	}
	cout<<dp[n]<<"\n";
	go(n);
	return 0;
}
*/
