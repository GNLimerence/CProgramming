#include <iostream>
using namespace std;
const int MAXN = 20;
int n;
int x[MAXN];
void print_sol(){
	for (int i = 1; i <= n; i++)
	{
		cout << x[i] << ' ';
	}
	cout << endl;
}
void TRY (int k){
	for (int i = 0; i <=1 ; i++)
	{
		x[k] = i;
		if (k==n) print_sol();
		else TRY(k + 1);
	}
}
/*
Gỉai thích hàm TRY: ví dụ khi n = 3; xuất phát tại k = 1
trong lần đầu tiên của vòng lặp x[1] = 0 gọi đệ quy với TRY(2), trong TRY(2)
gọi vòng lặp x[2] = 0 sau đó gọi đệ quy với TRY(3), trong TRY(3) gọi vòng lặp x[3] = 0, 
tại đây vì k == n nên sẽ in ra kết quả 000. Sau đó sẽ tiếp tục vòng lặp và gán x[k] == 1
sau đó k == n nên sẽ in ra kết quả 001. Lúc này hàm hàm TRY đã được hoàn thành nên TRY(3)
sẽ được đưa ra khỏi stack và lấy ra lời gọi đệ quy trước đó là TRY(2) và tiếp tục tại vị 
trí được gọi đệ quy trước đó là TRY(3) nên lúc này sẽ tiếp tục vòng lặp và gán x[2] == 1. Keep going
*/
int main()
{
	cin >> n;
	TRY(1);
	return 0;
}