#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int N = 1e3 + 1;

int a[N][N];
int n, m;
int ans;
long long h[N];
stack<long long> S;
vector<long long> V;
long long L[N], R[N];

// Hàm tính toán diện tích hình chữ nhật lớn nhất trong một histogram
long long compute()
{
    h[0] = -1;
    h[m + 1] = -1;
    V.clear();

    // Tính các đỉnh phải của mỗi cột trong histogram
    for (int i = 1; i <= m + 1; i++)
    {
        while (!V.empty() && h[i] < h[V[V.size() - 1]])
        {
            R[V[V.size() - 1]] = i;
            V.pop_back();
        }
        V.push_back(i);
    }

    // Tính các đỉnh trái của mỗi cột trong histogram
    for (int i = m; i >= 0; i--)
    {
        while (!V.empty() && h[i] < h[V[V.size() - 1]])
        {
            L[V[V.size() - 1]] = i;
            V.pop_back();
        }
        V.push_back(i);
    }
    unsigned long long ans = 0;

    // Tính diện tích lớn nhất trong histogram
    for (int i = 1; i <= m; i++)
    {
        unsigned long long c = (R[i] - L[i] - 1) * h[i];
        ans = ans < c ? c : ans;
    }
    return ans;
}

// Hàm giải quyết bài toán
long long solve()
{
    long long ans = 0;
    for (int i = 1; i <= m; i++)
        h[i] = 0;

    // Lặp qua từng hàng của lưới
    for (int i = 1; i <= n; i++)
    {
        // Cập nhật chiều cao của histogram dựa trên giá trị của lưới
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 0)
                h[j] = 0;
            else
                h[j] += 1;
        }

        // Tính diện tích hình chữ nhật lớn nhất và cập nhật diện tích lớn nhất tổng thể
        long long t = compute();
        if (t > ans)
            ans = t;
    }
    return ans; // In ra diện tích lớn nhất
}

int main()
{
    cin >> n >> m; // Đọc kích thước của lưới
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j]; // Đọc giá trị của lưới
        }
    }
    long long result = solve(); // Giải quyết bài toán và in kết quả
    cout << result << endl;
    return 0;
}
