#include <iostream>
using namespace std;

const int MAXN = 1e6 + 5;
int a[MAXN];
int mem[MAXN];
int n;
int pos;
int dp(int i) {
	if (i == 1) return a[i];
	if (mem[i] != -1) return mem[i];
	int res = max(a[i], a[i] + dp(i - 1));
	return mem[i] = res;
}
int solve() {
	int ans = a[1];
	for (int i = 1; i <=n; i++){
		if (ans < dp(i)){
			ans = dp(i);
			pos = i;
		}
	}
	return ans;
}
void trace (int i){
	if (i < 1) return;
	if (mem[i] == a[i] + mem[i-1]){
		trace(i-1);
	}
	cout << a[i] << " ";
}
int main() {
	memset(mem, -1, sizeof(mem));
	freopen("data.inp", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int ans = solve();
	cout << ans << endl;
	trace(pos);
	cout << endl;
}