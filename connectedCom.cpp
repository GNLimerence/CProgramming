#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 5;

vector<int> adj[N];
vector<int> compID(N, -1);
int n, m, curCompID = 1;

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

void dfs(int u){
	compID[u] = curCompID;
	for(const int &v : adj[u]){
		if(compID[v] == -1){
			dfs(v);
		}
	}
}
int main(){
	freopen("GraphData2.txt", "r", stdin);
	input();
	for(int i = 1; i <= n; i++){
		if(compID[i] == -1) {
			dfs(i);
			curCompID++;
		}
	}
	for(int i = 1; i <= n; i++){
		cout << i << ' ' << compID[i] << endl;
	}
}