#include <iostream>
#include <queue>
using namespace std;

#define N 6

int adj[N][N];
int level[N];

void print(){
    for(int i = 0; i < N; i++){
        cout << level[i] << ' ';
    }
    cout << endl;
}

void addEdge(int s, int d, int w){
    adj[s][d] = w;
}

bool bfs(int s, int t){
    memset(level,-1,sizeof(level));
    level[s] = 0;

    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int tmp = q.front();
        q.pop();

        for(int i = 0; i < N; i++){
            if(adj[tmp][i] > 0 && level[i] == -1){
                level[i] = level[tmp]+1;
                q.push(i);
            }
        }
    }
    return level[t] != -1;
}

int blocking(int u, int t, int flow){
    if(u == t) return flow;
    for(int i = 0; i < N; i++){
        if(adj[u][i] > 0 && level[i] == level[u]+1){
            int pathflow = blocking(i,t,min(flow,adj[u][i]));
            if(pathflow > 0){
                adj[u][i] -= pathflow;
                adj[i][u] += pathflow;
                cout << u << ' ' << i << " pathflow " << pathflow << endl;
                return pathflow;
            }
        }
    }    
    return 0;
}

int maxflow(int s, int t){
    int flow = 0;
    int pathflow;
    while(bfs(s,t)){
        cout << "bfs\n";
        print();
        do{
            pathflow = blocking(s,t,INT_MAX);
            flow += pathflow;
            cout << "pathflow " << pathflow << endl;
        } while(pathflow > 0);       
    }
    return flow;
}

int main(){
#if 0
    addEdge(0, 1, 16 );
    addEdge(0, 2, 13 );
    addEdge(1, 2, 10 );
    addEdge(1, 3, 12 );
    addEdge(2, 1, 4 );
    addEdge(2, 4, 14);
    addEdge(3, 2, 9 );
    addEdge(3, 5, 20 );
    addEdge(4, 3, 7 );
    addEdge(4, 5, 4);
#else
     addEdge(0, 1, 10); 
     addEdge(0, 2, 10); 
     addEdge(1, 3, 4 ); 
     addEdge(1, 4, 8 ); 
     addEdge(1, 2, 2 ); 
     addEdge(2, 4, 9 ); 
     addEdge(3, 5, 10 ); 
     addEdge(4, 3, 6 ); 
     addEdge(4, 5, 10 );
#endif
    std::cout << maxflow(0,5) << std::endl;
}


