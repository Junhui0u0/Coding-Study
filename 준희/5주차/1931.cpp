#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

int n, a, b;
vector<pair<int, int>> v;
stack<int> st;

int main() {

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	st.push(v[0].second);
	for (int i = 1;i < v.size();i++) {
		if (v[i].first >= st.top()) {
			st.push(v[i].second);
		}
		else if (v[i].second <= st.top()) {
			st.pop();
			st.push(v[i].second);
		}
	}

	cout << st.size() << "\n";

	return 0;
}


/*
using namespace std;
int from, to, n, idx = 0, ret = 1;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++){
		cin >> from >> to;
		v.push_back({to, from});
	}
	sort(v.begin(), v.end());
	from = v[0].second;
	to = v[0].first;
	for(int i = 1; i < n; i++){
		if(v[i].second < to) continue;
		from = v[i].second; to = v[i].first;ret++;
	}
	cout << ret << '\n';
	return 0;
}
*/