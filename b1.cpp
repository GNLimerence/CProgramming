#include <iostream>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int count = 0;
    for (int k = n - 1; k >= 0; k--) {
        int i = 0, j = k - 1;

        while (i < j) {
            if (a[i] + a[j] == a[k]) {
                count = (count + 1) % MOD;
                i++;
                j--;
            } else if (a[i] + a[j] < a[k]) {
                i++;
            } else {
                j--;
            }
        }
    }

    cout << count << endl;

    return 0;
}