#include <iostream>
#include <cstring>
using namespace std;

double xx, yy, ret = 0.0;
int x, y;
double dp[19][19][19];
bool isPrime[19];

void era() {	//에라토스테네스의 체
	fill(isPrime, isPrime + 19, 1);		// 1. 1로 초기화 
	isPrime[0] = 0; isPrime[1] = 0;		// 2. 0과 1은 소수x -> 0으로 초기화
	for (int i = 2;i <= 19;i++) {		// 3. 2부터 알고싶은수까지
		for (int j = i + i;j <= 19;j += i) {//4. 초기화 값, 증가수 중요! (2의배수부터 + 배수만큼 증가)
			isPrime[j] = 0;					//5. 배수들은 소수x -> 0으로 초기화 
		}
	}
}

double solve(int cnt, int a, int b) {
	if (cnt == 18) return isPrime[a] || isPrime[b] ? 1.0 : 0.0;
	double &ret = dp[cnt][a][b];
	if (ret > -0.5) return ret;
	ret = 0.0;
	ret += solve(cnt + 1, a + 1, b + 1)*xx*yy;
	ret += solve(cnt + 1, a + 1, b)*xx*(1 - yy);
	ret += solve(cnt + 1, a, b + 1)*(1 - xx)*yy;
	ret += solve(cnt + 1, a, b)*(1 - xx)*(1 - yy);
	return ret;
}

int main() {
	cin >> x >> y;
	xx = x / 100.0;
	yy = y / 100.0;
	era();
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 0) << "\n";
	return 0;
}