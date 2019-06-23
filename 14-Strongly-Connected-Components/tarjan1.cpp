#include <iostream>
#include <list>
#include <stack>
using namespace std;

#define SIZE 20

int V, c;
int low[SIZE];
int disc[SIZE];
int id[SIZE];
list<int> g[SIZE];    
bool instack[SIZE];
std::stack<int> st;

void addEdge(int u, int v){
    g[u].push_back(v);
}

void init(int s){
    V = s;
    c = 0;
    memset(low,0,sizeof(low));   
    memset(disc,0,sizeof(disc));   
    memset(instack,0,sizeof(instack));   
    for(int i = 0; i < V; i++){
        g[i].clear();
    }
}

int findlow(int v){
    if(disc[v] != low[v]){
        low[v] = findlow(id[low[v]]);
    }
    return low[v];
}

void updatelow(){
    for(int i = 0; i < V; i++){
        id[disc[i]] = i;
    }   
    for(int i = 0; i < V; i++){
        low[i] = findlow(id[low[i]]);
    }
}

void print(){
    for(int i = 0; i < V; i++){
        cout << low[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < V; i++){
        cout << disc[i] << ' ';
    }
    cout << endl;
}

void dfs(int u){
    disc[u] = low[u]= ++c;
    st.push(u);
    instack[u] = true;
    for(auto &v : g[u]){
        if(disc[v] == 0){
            dfs(v);
            low[u] = min(low[u],low[v]);   
        } else if(instack[v]){
            low[u] = min(low[u],disc[v]);
        }
    }

    if(disc[u] == low[u]){
        int v;
        do{
            v = st.top();
            st.pop();
            instack[v] = false;
            cout << v << ' ';
        } while(v != u);
        cout << endl;
    }
}

void scc(){
    for(int i = 0; i < V; i++){
        if(!disc[i]){
            dfs(i);
        }
    }
    print();
    updatelow();
    print();
}

int main(){
    init(11);
    addEdge(0,1);addEdge(0,3);
    addEdge(1,2);addEdge(1,4);
    addEdge(2,0);addEdge(2,6);
    addEdge(3,2);
    addEdge(4,5);addEdge(4,6);
    addEdge(5,6);addEdge(5,7);addEdge(5,8);addEdge(5,9);
    addEdge(6,4);
    addEdge(7,9);
    addEdge(8,9);
    addEdge(9,8);
    scc();

    std::cout << "------------------------------\n";

    init(11);
    addEdge(0,1); 
    addEdge(1,2);
    addEdge(2,3); addEdge(2,0); addEdge(2,4);
    addEdge(3,0);
    addEdge(4,5);
    addEdge(5,6); addEdge(5,7);
    addEdge(6,2); addEdge(6,4);
    addEdge(7,8);
    addEdge(8,5); addEdge(8,9);
    addEdge(9,5);
    addEdge(10,0);
    scc();

    return 0;
}
