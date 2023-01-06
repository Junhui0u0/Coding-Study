#include <iostream>
#include <string>
using namespace std;

int num[102];
string time[102];
int a = 0;
int b = 0;
int ret_a[2];
int ret_b[2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> num[i] >> time[i];
	}
	time[n] = "48:00";

	for (int i = 0;i < n;i++) {
		if (num[i] == 1) a++;
		else if (num[i] == 2) b++;

		int prev_h = stoi(time[i].substr(0, 2));
		int prev_m = stoi(time[i].substr(3, 2));
		int last_h = stoi(time[i + 1].substr(0, 2));
		int last_m = stoi(time[i + 1].substr(3, 2));


		if (a > b) {
			ret_a[0] += last_h - prev_h;
			ret_a[1] += last_m - prev_m;
			if (ret_a[1] < 0) {
				ret_a[0]--;
				ret_a[1] += 60;
			}
		}
		else if (a < b) {
			ret_b[0] += last_h - prev_h;
			ret_b[1] += last_m - prev_m;
			if (ret_b[1] < 0) {
				ret_b[0]--;
				ret_b[1] += 60;
			}
		}
	}


	string sa = "";
	for (int i = 0;i < 2;i++) {
		string tmp = to_string(ret_a[i]);
		if (tmp.size() == 1) { sa += "0"; sa += tmp; }
		else sa += tmp;
		if (i == 0) sa += ":";
	}

	string sb = "";
	for (int i = 0;i < 2;i++) {
		string tmp = to_string(ret_b[i]);
		if (tmp.size() == 1) { sb += "0"; sb += tmp; }
		else sb += tmp;
		if (i == 0) sb += ":";
	}

	cout << sa << "\n";
	cout << sb << "\n";

	return 0;
}