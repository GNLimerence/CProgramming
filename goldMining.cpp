#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, L1, L2;
    cin >> n >> L1 >> L2;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    priority_queue<pair<long long, int> > pq; // pair<totalAmount, index>
    long long result = 0;

    for (int i = 0; i < n; ++i) {
        // Pop warehouses outside the valid distance range
        while (!pq.empty() && pq.top().second < i - L2) {
            pq.pop();
        }

        long long currentAmount = (pq.empty() ? 0 : pq.top().first) + a[i];
        result = max(result, currentAmount);

        // Push the current warehouse to the priority queue using make_pair
        pq.push(make_pair(currentAmount, i - L1 + 1));
    }

    cout << result << endl;

    return 0;
}
