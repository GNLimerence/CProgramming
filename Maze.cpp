#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1000;
int n, m, r, c;
int maze[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
struct Node
{
    int x,y,dist;
};
bool isValid(int x, int y){
    return(x>=0 && x<n && y>=0 && y<m && maze[x][y]==0 && !visited[x][y]);
}
int bfs(){
    queue<Node>q;
    Node start;
    start.x = r - 1;
    start.y = c - 1;
    start.dist = 0;
    q.push(start);
    while(!q.empty()){
        Node curr = q.front();
        q.pop();
        int x = curr.x;
        int y = curr.y;
        int dist = curr.dist;
        // nếu là biên sẽ cho ra lỗi thoát
        if (x == 0 || x == n-1 || y ==0 || y == m-1){
            return dist + 1;
        }
        // nếu không phải biên di chuyển
        for (int i=0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            // kiểm tra xem ô di chuyển vào có hợp lệ hay không
            if (isValid(newX, newY)){
                visited[x][y] = true;
                Node next;
                next.x = newX;
                next.y = newY;
                next.dist = dist + 1;
                q.push(next);
            }
        }
    }
    //không thấy đường đi
    return -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    int result = bfs();
    cout << result << endl;

    return 0;
}

