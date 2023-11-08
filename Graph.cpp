#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 5;

vector<int> adj[N];
vector<bool> visited(N, false);
int n, m;

void input(){
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		adj[u].push_back(v);
	}
	//for(int u = 1; u <= n; u++){
	//	sort(adj[u].begin(), adj[u].end());
	//}
}

void dfs(int u){
	cout << u << ' ';
	visited[u] = true;
	for(const int &v : adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}
int main(){
	freopen("GraphData.txt", "r", stdin);
	input();
	for(int i = 1; i <= n; i++){
		if(!visited[i]) dfs(i);
	}
}