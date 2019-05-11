#include <iostream>
#include <queue>
#define MAXN 100
using namespace std;
int g[MAXN][MAXN];
int r[MAXN][MAXN];
int p[MAXN];
int V;

void addEdge(int i, int j, int weight){
    g[i][j] = weight;
}

bool bfs(int s, int t){
    memset(p,-1,sizeof(p));
    queue<int> q;
    q.push(s);
    p[s] = 0;

    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i = 0; i < V; i++){
            if(r[tmp][i] > 0 && p[i] == -1){
                p[i] = tmp;
                if(i == t){
                    return true;
                }
                q.push(i);
            }
        }
    }
    return false;
}

void mincut(){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            r[i][j] = g[i][j];
        }
    }
    int flow = 0;

    while(bfs(0,V-1)){
        int t = V-1;
        int pathflow = 0x7FFF;
        while(p[t] != 0){
            if(r[p[t]][t] < pathflow){
                pathflow = r[p[t]][t];
            }
            t = p[t];   
        }
        flow += pathflow;
        t = V-1;
        while(p[t] != 0){
            r[p[t]][t] -= pathflow;
            r[t][p[t]] += pathflow;
            t = p[t];
        }
    }
    cout << "maxflow\t" << flow << endl;
    int minc = 0;
    
    
    queue<int> q;
    bool visited[V];
    memset(visited,0,sizeof(visited));
    q.push(0);
    visited[0] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(int i = 0; i < V; i++){
            if(r[u][i] > 0 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    } 

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(g[i][j] > 0 && visited[i] && !visited[j]){
                cout << i << '\t' << j << endl;
                minc += g[i][j]; 
            }
        }
    }
    cout << "mincut\t" << minc << endl;
}  


int main(){
    V = 6;
    addEdge(0,1,16);
    addEdge(0,2,13);
    addEdge(1,2,10);
    addEdge(1,3,12);
    addEdge(2,1,4);
    addEdge(2,4,14);
    addEdge(3,2,9);
    addEdge(3,5,20);
    addEdge(4,3,7);
    addEdge(4,5,4);


    mincut();   
    return 0;
}
