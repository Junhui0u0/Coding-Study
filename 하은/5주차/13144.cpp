#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[100001] = { 0, };
ll visited[100001] = { 0, };

int main() {
	ll n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ll cnt = 0;
	ll l = 0;
	ll r = 0;
	while (r < n) {
		if (!visited[arr[r]]) {
			visited[arr[r]]++;
			r++;
		}
		else {
			cnt += (r - l);
			visited[arr[l]]--;
			l++;
		}
	}

	cnt += (r - l) * (r - l + 1) / 2;
	cout << cnt << '\n';



}
