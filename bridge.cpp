#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 5;
int n, m;
vector<int> adj[N];
vector<int> low(N), num(N, -1);
vector<pair<int, int> > res;
int curNum = 0;

void dfs(int u, int p){
	low[u] = num[u] = ++curNum;
	for(const int &v : adj[u]){
		if(v == p) continue;
		if(num[v] == -1){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}else{
			low[u] = min(low[u], num[v]);
		}
		if(low[v] > num[u]){
			res.push_back(make_pair(u, v));
		}
	}
}
void input(){
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//for(int u = 1; u <= n; u++){
	//	sort(adj[u].begin(), adj[u].end());
	//}
}
int main(){
	freopen("bridge.txt", "r", stdin);
	input();
	for (int u = 1; u <= n; u++){
		if(num[u] == -1) dfs(u, -1);
	}
	for(const pair<int, int> &e : res){
		cout << e.first << ' ' << e.second << endl;
	}
	return 0;
}