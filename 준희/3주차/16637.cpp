#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int PLUS = 987654321;
const int MINUS = 987654322;
const int MUL = 987654323;
int n = 0;
int ret = -999999999;
string s, ss = "";
vector<int> v;


int cal(int a, int b, int c) {
	if (b == PLUS) return a + c;
	else if (b == MINUS) return a - c;
	else if (b == MUL) return a * c;
}

int all_cal(vector<int> a) {
	int sum = 0;
	for (int i = 0;i < a.size() - 1;i++) {
		if (a[i] == PLUS) sum += a[i + 1];
		else if (a[i] == MINUS) sum -= a[i + 1];
		else if (a[i] == MUL) sum *= a[i + 1];
		i++;
	}
	return sum;
}


void solve(int idx, vector<int> tmp) {
	vector<int> a = tmp; vector<int> b = tmp;

	for (int i = idx;i < v.size();i++) {
		if (i + 3 <= v.size() - 1) {
			a.push_back(v[i]);
			a.push_back(cal(v[i + 1], v[i + 2], v[i + 3]));
			solve(i + 4, a);
		}
		if (i + 1 <= v.size() - 1) {
			b.push_back(v[i]);
			b.push_back(v[i + 1]);
			solve(i + 2, b);
		}
		break;
	}

	if (idx == v.size()) {
		ret = max(ret, all_cal(tmp));
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> ss;

	s = "+" + ss;

	for (int i = 0;i < s.size();i++) {
		if (s[i] == '+') v.push_back(PLUS);
		else if (s[i] == '-') v.push_back(MINUS);
		else if (s[i] == '*') v.push_back(MUL);
		else v.push_back(atoi(&s[i]));
	}

	vector<int> tmp;

	solve(0, tmp);
	if (n == 1) {
		if (ss[0] == '+' || ss[0] == '-' || ss[0] == '*') cout << "0\n";
		else cout << ss[0] << "\n";
	}
	else cout << ret << "\n";

	return 0;
}