#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int N, K1, K2;
    cin >> N >> K1 >> K2;

    // dp[i][j] represents the number of working plans of length i ending with j consecutive working days
    vector<vector<int> > dp(N + 1, vector<int>(N + 1, 0));

    // Base case
    dp[0][0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = K1; j <= min(i, K2); ++j) {
            // Transition based on the two constraints
            for (int k = K1; k <= min(i - j, K2); ++k) {
                dp[i][j] = (dp[i][j] + dp[i - j - k][k]) % MOD;
            }
        }
    }

    // Sum up the final results for all possible lengths of working periods
    int result = 0;
    for (int j = K1; j <= K2; ++j) {
        result = (result + dp[N][j]) % MOD;
    }

    cout << result << endl;

    return 0;
}
