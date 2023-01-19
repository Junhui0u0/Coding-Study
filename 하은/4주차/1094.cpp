#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> stick;
	stick.push_back(64);

	int small = 64;
	int sum = 64;

	while (sum > n) {
		sort(stick.begin(), stick.end());
		small = stick[0];
		
		if (sum <= n) break;
		else {
			stick[0] = small / 2;
			sum = accumulate(stick.begin(), stick.end(), 0);
			if (sum < n) stick.push_back(stick[0]);
		}

		sum = accumulate(stick.begin(), stick.end(), 0);
	}

	cout << stick.size();
}

/*

비트마스킹 풀이

#include <bits/stdc++.h>
using namespace std;
int n, ret = 1;
int main(){
	cin >> n;
	while(n != 1){
		if(n & 1) ret++;
		n /= 2;
	}
	cout << ret << '\n';
	return 0;
}

*/