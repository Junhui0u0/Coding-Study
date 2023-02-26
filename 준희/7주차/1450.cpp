#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, c, arr[31], ret = 0;
vector<ll> v1, v2;

void solve(ll start, ll end, ll sum,vector<ll>& v) {	//주소값 넘겨주기(벡터)
	if (start >= end) {
		v.push_back(sum);
		return;
	}
	solve(start + 1, end, sum + arr[start], v);
	solve(start + 1, end, sum, v);
}

int main() {
	cin >> n >> c;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	solve(0, n / 2, 0, v1);
	solve(n / 2, n, 0, v2);
	sort(v2.begin(), v2.end());
	for (int i = 0;i < v1.size();i++) {
		ret += upper_bound(v2.begin(), v2.end(), c - v1[i]) - v2.begin();
	}
	cout << ret << "\n";
	return 0;
}
