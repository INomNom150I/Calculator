#include <iostream>
#include <queue>
#include <list>
using namespace std;

#define MAXN 100
#define NIL 0
#define INF 9999
int U, V;
list<int> adj[MAXN];
int pairU[MAXN];
int pairV[MAXN];
int level[MAXN];

void addEdge(int u, int v){
    adj[u].push_back(v);
}

bool bfs(){
    queue<int> q;
    for(int u = 1; u <= U; u++){
        if(pairU[u] == 0){
            level[u] = 0;
            q.push(u);
        } else{
            level[u] = INF;
        }
    }
    level[0] = INF;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(level[u] < level[0]){
            for(auto v:adj[u]){
                if(level[pairV[v]] == INF){
                    level[pairV[v]] = level[u]+1; 
                    q.push(pairV[v]);
                }
            }
        }
    }
    return level[0] != INF;
}

bool dfs(int u){
    if(u == 0) return true;
    for(int v:adj[u]){
        if(level[pairV[v]] == level[u]+1){
            if(dfs(pairV[v])){
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hopKarp(){
    int maxedmatch = 0;
    while(bfs()){
        for(int u = 1; u <= U; u++){
            if(pairU[u] == 0 && dfs(u)){
                maxedmatch++;
            }
        }
    }
    return maxedmatch;
}

void print(){
    for(int u = 1; u <= U; u++){
        std::cout <<  u  << ' '<< pairU[u] << ":\n";
    }
    std::cout << std::endl;
    for(int v = 1; v <= V; v++){
        std::cout <<  pairV[v]  << ' '<< v << ":\n";
    }
}

int main(){
    U = 6; V = 6;
    addEdge(1,2);
    addEdge(1,3);
    addEdge(3,1);
    addEdge(3,4);
    addEdge(4,3);
    addEdge(5,3);
    addEdge(5,4);
    addEdge(6,6);
    std::cout << hopKarp() << std::endl;    
    print();
}

