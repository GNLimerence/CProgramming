#include <iostream>
#include <vector>
using namespace std;

int count2 = 0;

void countSolutions(int n, int M, vector<int>& a, vector<int>& x, int current, int sum) {
    if (current == n) {
        if (sum == M) {
            count2++;
        }
        return;
    }

    for (int i = 1; i <= M; i++) {
        if (sum + a[current] * i <= M) {
            x[current] = i;
            countSolutions(n, M, a, x, current + 1, sum + a[current] * i);
            x[current] = 0;  // Reset the value after recursion
        }
    }
}

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    vector<int> x(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    countSolutions(n, M, a, x, 0, 0);
    cout << count2 << endl;

    return 0;
}
