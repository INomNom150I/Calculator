#include <iostream>
#include <queue>
using namespace std;

#define N 6

int adj[N][N];
int parent[N];

void addEdge(int s, int d, int w){
    adj[s][d] = w;
}

void printpath(){
    int i = N-1;
    while( i != parent[i]){
        cout << i << '-' << parent[i] << '(' << adj[parent[i]][i] << "), ";
        i = parent[i];
    }
    cout << endl;
}

bool bfs(int s, int t){
    memset(parent,-1,sizeof(parent));
    parent[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();

        if(tmp == t) return true;
        for(int i = 0; i < N; i++){
            if(adj[tmp][i] > 0 && parent[i] == -1){
                cout << i << ' ' << tmp << endl;
                parent[i] = tmp;
                q.push(i);
            }
        }
    }
    return false;
}

int maxflow(int s, int t){
    int flow = 0;
    int pathflow;   
    while(bfs(s,t)){
        printpath();
        pathflow = INT_MAX;
        int i = t;
        while(i != parent[i]){
            pathflow = min(pathflow,adj[parent[i]][i]);
            i = parent[i];
        }
        i = t;
        while(i != parent[i]){
            adj[parent[i]][i] -= pathflow;
            adj[i][parent[i]] += pathflow;
            i = parent[i];
        }
        flow += pathflow;
        cout << "pathflow " << pathflow << endl;
    }
    return flow;
}

int main(){
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

    std::cout << maxflow(0,5) << std::endl;
}


