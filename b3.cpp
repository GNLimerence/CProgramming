#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int minimizeDifference(const vector<int>& values, int index, int sum1, int sum2) {
    if (index == values.size()) {
        return abs(sum1 - sum2);
    }
    int diff1 = minimizeDifference(values, index + 1, sum1 + values[index], sum2);
    int diff2 = minimizeDifference(values, index + 1, sum1, sum2 + values[index]);
    return min(diff1, diff2);
}
int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    int result = minimizeDifference(values, 0, 0, 0);
    cout << result << endl;
    return 0;
}
