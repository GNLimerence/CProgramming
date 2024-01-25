#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Treasure {
    int x, y, gold;
    Treasure(int _x, int _y, int _gold) : x(_x), y(_y), gold(_gold) {}
};
bool compareTreasures(const Treasure &a, const Treasure &b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}
int main() {
    int n;
    cin >> n;
    vector<Treasure> treasures;
    for (int i = 0; i < n; i++) {
        int x, y, gold;
        cin >> x >> y >> gold;
        treasures.emplace_back(x, y, gold);
    }
    sort(treasures.begin(), treasures.end(), compareTreasures);
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        dp[i] = treasures[i].gold; 
        for (int j = 0; j < i; j++) {
            if (treasures[j].x <= treasures[i].x && treasures[j].y <= treasures[i].y) {
                dp[i] = max(dp[i], dp[j] + treasures[i].gold);
            }
        }
    }
    int maxGold = *max_element(dp.begin(), dp.end());
    cout << maxGold << endl;
    return 0;
}
