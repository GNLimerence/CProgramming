#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e4 + 5;
vector<int> adj[N];
vector<bool> visited(N, false);
int n, m;
queue<int> Q;
vector<int> dist(N, -1);
void BFS(int start) {
	Q.push(start);
	//visited[start] = true;
	dist[start] = 0;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		cout << u << ' ' << dist[u] << endl;

		for(int v : adj[u]){
			if(dist[v] == -1){
				Q.push(v);
				//visited[v] = true;
				dist[v] = 1 + dist[u];
			}
		}
	}
}

void input(){
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		adj[u].push_back(v);
	}
}

int main(){
	freopen("scc.inp", "r", stdin);
	input();
	for (int u = 1; u <=n; u++){
		if(dist[u] == -1) BFS(u);
	}
	return 0;
}