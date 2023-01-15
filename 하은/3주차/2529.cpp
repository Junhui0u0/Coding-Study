#include<bits/stdc++.h>
using namespace std;

int arr[10] = { 0, };
int visited[10] = { 0, };
char carr[10];
int k;
vector<string> ret;

void go(int n) {
	if (n == k + 1) {
		bool flag = true;
		for (int i = 0; i < k; i++) {
			if (carr[i] == '<' && arr[i] > arr[i + 1]) flag = false;
			if (carr[i] == '>' && arr[i] < arr[i + 1]) flag = false;
		}


		if (flag) {
			string s;
			for (int i = 0; i < k+1; i++) {
				s += to_string(arr[i]);
			}
			ret.push_back(s);
		}

		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			arr[n] = i;
			go(n + 1);
			visited[i] = 0;
		}
	}
}

int main() {

	cin >> k;

	for (int i = 0; i < k; i++) cin >> carr[i];

	go(0);

	cout << *max_element(ret.begin(), ret.end()) << '\n' << *min_element(ret.begin(), ret.end());
}