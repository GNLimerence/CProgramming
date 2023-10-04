#include <iostream>
using namespace std;

const int MAXN = 20;
int m, n;
int x[MAXN];
void print_sol(){
	for (int i = 1; i <= m; i++)
	{
		cout << x[i] << ' ';
	}
	cout << endl;
}
void TRY(int k){
	// x1, x2, ..., x[k-1]
	// x[k]: x[k-1] + 1...n - (m - k)
	for (int i = x[k - 1] + 1; i <= n - m + k; i++)
	{
		x[k] = i;
		if(k == m) print_sol();
		else TRY(k+1);
	}
}
int main (){
	cin >> m >> n;
	TRY(1);
	return 0;
}