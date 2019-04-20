#include <iostream>

#define MAXN 100

int adj[MAXN][MAXN];
int N, M;
int matches[MAXN];
void addEdge(int a, int b){
    adj[a][b] = 1;
}

bool bmp(int u, bool visited[]){
    for(int i = 0; i < N; i++){
        if(adj[u][i] > 0 && !visited[i]){
            visited[i] = true;
            if(matches[i] == -1 || bmp(matches[i],visited)){
                matches[u] = i;
                return true;
            }            
        }
    }
    return false;
}

int amaximum(){
    int match = 0;
    bool visited[N];
    memset(matches,-1,sizeof(matches));
    for(int i = 0; i < M; i++){
        memset(visited,0,sizeof(visited));
        if(bmp(i,visited)){
            match++;
        }
    }

    return match;
}

int main(){
    M = 2; N = 2;
    addEdge(0,0);
    addEdge(1,0);
    addEdge(0,1);
    std::cout << amaximum() << std::endl;   
}
