#include <iostream>
#include <queue>
#define N 10
using namespace std;
int adj[N][N];
bool dp[N][1<<N];
bool visited[N];
int V;

void addedge(int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}

bool dfs(int v,int cnt){
    if(cnt == V-1) return true; 
    visited[v] = true;
    for(int i = 0; i < V; i++){
        if(adj[v][i] && !visited[i]){
            if(dfs(i,cnt+1)) return true;
        }
    }   
    visited[v] = false;
    return false;
}


int main(){
    V = 4;
    addedge(0, 1);
    addedge(1, 2);
    addedge(2, 3);
    addedge(3, 1);
    if(dfs(0,0)) cout << "has path" << endl;
    else cout << "no path" << endl;
    return 0;
}
