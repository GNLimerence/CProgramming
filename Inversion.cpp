/*
Given a sequence of integers a1, a2, ..., an. A pair (i, j) is call an inversion if i < j and ai > aj. Compute the number Q of inversions
Input
Line 1: contains a positive integer n (1 <= n <= 10^6)
Line 2: contains a1, a2, ..., an(0 <= ai<= 10^6)
Output
Write the value Q modulo 10^9+7
*/
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int mergeAndCount(int a[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int count = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            count += mid - i + 1;
            count %= MOD;
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= right) {
        temp[k++] = a[j++];
    }

    for (int p = left; p <= right; p++) {
        a[p] = temp[p];
    }

    return count;
}

int solve(int a[], int temp[], int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        count += solve(a, temp, left, mid);
        count %= MOD;
        count += solve(a, temp, mid + 1, right);
        count %= MOD;
        count += mergeAndCount(a, temp, left, mid, right);
        count %= MOD;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int temp[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }


    cout << solve(a, temp, 0, n - 1) % MOD << endl;

    return 0;
}
