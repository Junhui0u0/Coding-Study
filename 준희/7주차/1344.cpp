#include <iostream>
#include <cstring>
using namespace std;

double xx, yy, ret = 0.0;
int x, y;
double dp[19][19][19];
bool isPrime[19];

void era() {	//�����佺�׳׽��� ü
	fill(isPrime, isPrime + 19, 1);		// 1. 1�� �ʱ�ȭ 
	isPrime[0] = 0; isPrime[1] = 0;		// 2. 0�� 1�� �Ҽ�x -> 0���� �ʱ�ȭ
	for (int i = 2;i <= 19;i++) {		// 3. 2���� �˰����������
		for (int j = i + i;j <= 19;j += i) {//4. �ʱ�ȭ ��, ������ �߿�! (2�ǹ������ + �����ŭ ����)
			isPrime[j] = 0;					//5. ������� �Ҽ�x -> 0���� �ʱ�ȭ 
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