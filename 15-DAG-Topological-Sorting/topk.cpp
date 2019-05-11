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
stack<int> st;

void top(){
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(in[i] == 0){
            q.push(i);
        }        
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0;i < V; i++){
            if(g[u][i] > 0){
                in[i]--;
                if(in[i] == 0) q.push(i);
            }
        }
        cout << u << ' ';
    }
    cout << endl;
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
