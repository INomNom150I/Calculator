#include <iostream>
#include <list>
#define SIZE 100
using namespace std;
list<int> g[SIZE];
int V, c = 0;
int low[SIZE], disc[SIZE], parent[SIZE];
bool ap[SIZE];

void init(int s){
    c = 0;
    V = s;
    memset(low,0,sizeof(low));
    memset(disc,0,sizeof(disc));
    memset(parent,-1,sizeof(parent));
    memset(ap,0,sizeof(ap));
    for(int i = 0; i < V; i++){
        g[i].clear();
    }
}

void print(){
    for(int i = 0; i < V; i++){
        if(ap[i]){
            cout << i << ' ';
        }
    }
    cout << endl;
}

void addEdge(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

void dfs(int u){
    disc[u] =low[u] = ++c;
    int child = 0;   
    for(auto &v : g[u]){
        if(disc[v] == 0){
            parent[v] = u;
            child++;
            dfs(v);
            if(parent[u] >= 0){
                if(low[v] > disc[u]){
                    ap[u] = true;
                }    
            }
            low[u] = min(low[u],low[v]);
        } else{
            if(parent[u] != v){
                low[u] = min(low[u],low[v]);
            }
        }
    }   
//    cout << u << " child " << child << " low " << low[u] << " disc " << disc[u] << endl;
    if(parent[u] == -1 && child >= 2){
        ap[u] = true;
    }
}

void AP(){
    dfs(0);
    print();
}

int main() 
{ 
    // Create graphs given in above diagrams 
    cout << "\nArticulation points in first graph \n"; 
    init(5); 
    addEdge(1, 0); 
    addEdge(0, 2); 
    addEdge(2, 1); 
    addEdge(0, 3); 
    addEdge(3, 4); 
    AP(); 
  
    cout << "\nArticulation points in second graph \n"; 
    init(5); 
    addEdge(0, 1); 
    addEdge(1, 2); 
    addEdge(2, 3); 
    addEdge(0,5);
    AP(); 
  
    cout << "\nArticulation points in third graph \n"; 
    init(7); 
    addEdge(0, 1); 
    addEdge(1, 2); 
    addEdge(2, 0); 
    addEdge(1, 3); 
    addEdge(1, 4); 
    addEdge(1, 6); 
    addEdge(3, 5); 
    addEdge(4, 5); 
    AP(); 
  
    return 0;
}
