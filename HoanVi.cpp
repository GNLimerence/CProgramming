#include <iostream>
using namespace std;
const int MAXN = 15;
int n, x[MAXN];
bool marked[MAXN];
bool is_cand (int i, int k){
	if(k < 3) return true;
	if(x[k-2]>x[k-1]) return true;
	return x[k-1] > i;
}
void print_sol(){
	for (int i = 1; i <= n; i++)
	{
		cout << x[i] << ' ';
	}
	cout << endl;
}
void TRY(int k){
	// x1, x2, ...., x[k - 1]
	// x[k] != x[i], i=1...k-1
	for (int i = 1; i <= n ; i++)
	{
		if (!marked[i] && is_cand(i,k))
		{
			x[k] = i;
			marked[i] = true;
			if (k == n)
			{
				print_sol();
			}else{
				TRY(k + 1);
			}
			marked[i] = false;
		}
	}
}
int main (){
	cin >> n;
	TRY(1);
	return 0;
}