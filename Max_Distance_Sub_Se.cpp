/*Given N elements (2≤ N ≤100,000) on a straight line at positions x1,…, xN(0≤ xi ≤1,000,000,000).
The distance of a subset of N elements is defined to be the minimum distance between two elements.
Find the subset of N given elements containing exactly C elements such that the distance is maximal.

Input
The first line contains a positive integer T (1 <= T <= 20) which is the number of test cases. 
Subsequent lines are T test cases with the following format:
Line 1: Two space-separated integers: N and C
Lines 2: contains  x1, x2, . . . , xN

Output
For each test case output one integer: the distance of the subset found.*/
#include <iostream>
#include <vector>
#include <algorithm>
const int MAXN = 100000;
using namespace std;
int n, t, c;
int a[MAXN];

bool check(int dis){
	int dem = 1;
	int x=1, y=2;
	while(x < n){
		while(y<=n && a[y]-a[x]<dis) y++;
		if(y<=n){
			dem++;
		}
		if(dem>=c){
			return true;
		}
		x=y;
		y++;
	}
	return false;

}
int solve(){
	int l=0;
	int r=a[n]-a[1];
	while(l<=r){
		int m = (l+r)/2; //mid
		if(check(m)){
			l=m+1;
		}else{
			r=m-1;
		}
	}
	return r;
}
int main() {
 
    cin >> t;

    while (t--) {
     
        cin >> n >> c;

        
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        sort(a+1,a+n+1);

        

        cout << solve() << endl;
    }

    return 0;
}



