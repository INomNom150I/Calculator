#include <iostream>
#include <list>
#include <stack>
#define SIZE 20
using namespace std;

int N = 5;
list<int> g[SIZE];
list<int> t[SIZE];
bool visited[SIZE];
stack<int> st;
void add_edge(int s, int e){
    g[s].push_back(e);
}

void tran(){
    for(int i = 0; i < N; i++){
        for(auto &u : g[i]){
            t[u].push_back(i);
        }
    }
}

void dfs1(int u){
    visited[u] = true;
    for(auto &v: g[u]){
        if(!visited[v]){
            dfs1(v);
        }
    }
    st.push(u);
}

void dfs2(int u){
    visited[u] = true;
    for(auto&v:t[u]){
        if(!visited[v]){
            dfs2(v);
        }
    }
    cout << u << ' ';
}

void scc(){
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            dfs1(i);
        }
    }
    memset(visited,0,sizeof(visited));
    tran();
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(!visited[u]){
            dfs2(u);
            cout << endl;
        }
    }
}

int main(){
    N = 5;
    add_edge(0,2);
    add_edge(2,1);
    add_edge(1,0);
    add_edge(0,3);
    add_edge(3,4);
    
    scc();

    return 0;
}
