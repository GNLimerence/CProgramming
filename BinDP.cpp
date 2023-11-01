/*Đếm số xâu nhị phân độ dài n sao cho:
- không chứa hai số 0 liên tiêp nhau
- các đoạn số 1 liền nhau có độ dài >= k1 và <= k2

Bài toán con:
dp(i) = Đếm số xâu nhị phân độ dài i thoả mãn yêu cầu

dp(i,0): Đếm số xâu nhị phân độ dài i kết thúc bởi 0 và thỏa mãn yêu cầu

dp(i,1): Đếm số xâu nhị phân độ dài i kết thúc bởi 1 và thoả mãn yêu cầu
*/

#include <iostream>
using namespace std;
const int N = 1e4 + 5;
const int MOD = 1e9 + 7;
int n, k1, k2;
int mem[N][2];

int dp(int i, int work){
	if(i == 0) return mem[i][work] = 1;
	if (mem[i][work]) return mem[i][work];
	int res = 0;
	if(work == 0){
		res = dp(i - 1, 1) % MOD;
	}else{
		for(int j = i - k2; j <= i - k1; j++){
			if(j >= 0) res = (res + dp(j,0)) % MOD;
		}
	}
	return mem[i][work] = res;
}

int main(){
	memset(mem, 0, sizeof(mem));
	return 0;
}