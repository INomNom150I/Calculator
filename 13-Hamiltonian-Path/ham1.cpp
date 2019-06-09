#include <iostream>
#include <queue>
#define N 10
using namespace std;
int adj[N][N];
bool dp[N][1<<N];
int V;

void addedge(int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void print(){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < 1<<V; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}

bool dpCycle(){
    for(int i = 0; i < V; i++){
        dp[i][1<<i] = true;
    }

    for(int s = 0; s < 1<<V; s++){
        for(int i = 0; i < V; i++){
            if(s & 1<<i){
                int ss = s ^ (1<<i);
                for(int j = 0; j < V; j++){
                    if(ss & 1<<j){
                        if(dp[j][ss] && adj[j][i]){
                            dp[i][s] = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < V; i++){
        if(dp[i][(1<<V) -1]) return true;
    }
    return false;
}



int main(){
    V = 4;
    addedge(0, 1);
    addedge(1, 2);
    addedge(2, 3);
    addedge(3, 1);
    cout << dpCycle() << endl;
    print();
    return 0;
}
