#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int n;
int ret = 0;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int p, d;
		cin >> p >> d;
		v.push_back({ d, p });
	}
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        pq.push(v[i].second);
        if (pq.size() > v[i].first) {
            pq.pop();
        }
    }
    while (pq.size()) {
        ret += pq.top(); 
        pq.pop();
    }
    cout << ret;

}