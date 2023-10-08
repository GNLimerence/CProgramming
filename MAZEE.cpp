#include <iostream>
#include <queue>
using namespace std;
typedef pair <int, int> node;
const int maxN = 999 + 100;
int matrix[maxN][maxN], m, n, r, c, dist[maxN][maxN];
int dx[] = {1, 0, -1, 0},
    dy[] = {0, 1, 0, -1};
queue<node> q;
int solve()
{
    q.push(node(r, c));
    dist[r][c] = 0; // Khoảng cách ban đầu là 0
    matrix[r][c] = 1; /// Đánh dấu điểm (r, c) đã đi qua
    while (!q.empty())
    {
        node u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;
            //Nếu xác định được lối thoát
            if (x < 1 || x > m || y < 1 || y > n)
                return dist[u.first][u.second] + 1;
            //Nếu chưa xác định được lối thoát và vị trí tiếp theo chưa đi qua
            if (matrix[x][y] != 1)
            {
                dist[x][y] = dist[u.first][u.second] + 1;
                q.push(node(x, y));
                matrix[x][y] = 1;
            }
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n >> r >> c;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> matrix[i][j];
    int ans = solve();
    cout << ans;
    cout << endl;
    return 0;
}