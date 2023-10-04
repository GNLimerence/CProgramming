#include <iostream>
using namespace std;
const int MAXN = 20;
int m, n;
int x[MAXN];
int cur_candies = 0;
void print_sol(){
	for (int i = 1; i <= n; i++)
	{
		cout << x[i] << ' ';
	}
	cout << endl;
}
void TRY(int k){
	// x1, x2, ..., x[k-1]
	// x[k]: 1...m-cur_candies - (n - k)
	// if k == n: m -cur_candies -(n - k)
	int start_val = k == n ? m - cur_candies : 1;
	for (int i = start_val; i <= m - cur_candies - (n - k); i++)
	{
		x[k] = i;
		cur_candies += i;
		if (k == n) print_sol();
		else TRY (k + 1);
		cur_candies -= i;	
	}
}
int main(){
	cin >> m >> n;
	TRY (1);
	return 0;
}