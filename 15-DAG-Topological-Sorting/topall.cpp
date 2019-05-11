#include <iostream>
#include <list>
#include <stack>
#include <queue>
#define SIZE 20
using namespace std;

int V = 6;
int g[SIZE][SIZE];
int in[SIZE];

void addEdge(int u, int v){
    g[u][v] = 1;
    in[v]++;
}

bool visited[SIZE];
vector<int> v;

void dfs(int n){
    if(n == V){
        for(auto& i: v){
            cout << i << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < V; i++){
        if(!visited[i] && in[i] == 0){
            visited[i] = true;
            v.push_back(i);
            for(int j = 0; j < V; j++){
                if(g[i][j] > 0){
                    in[j]--;
                }
            }
            dfs(n+1);
            visited[i] = false;
            for(int j = 0; j < V; j++){
                if(g[i][j] > 0){
                    in[j]++;
                }
            }
            v.pop_back();
        }
    }
}

void top(){
    dfs(0);
}

int main(){
    addEdge(5,2);
    addEdge(5,0);
    addEdge(4,0);
    addEdge(4,1);
    addEdge(2,3);
    addEdge(3,1);
    top();
    return 0;
}
