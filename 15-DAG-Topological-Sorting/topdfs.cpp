#include <iostream>
#include <list>
#include <stack>
#include <queue>
#define SIZE 20
using namespace std;

int V = 6;
int g[SIZE][SIZE];

void addEdge(int u, int v){
    g[u][v] = 1;
}

bool visited[SIZE];
stack<int> st;

void dfs(int s){
    for(int i = 0; i < V; i++){
        if(g[s][i] == 1 && !visited[i]){
            visited[i] = true;
            dfs(i);
        }
    }    
    st.push(s);  
}

void top(){
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i);
        }
    }
    while(!st.empty()){
        cout << st.top() << ' ';
        st.pop();
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
