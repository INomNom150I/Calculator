#include <iostream>
#include <list>
using namespace std;
int V = 7;
list<int> con[100];

void addEdge(int u, int v){
    con[u].push_back(v);
    con[v].push_back(u);
}

void cover(){
    bool visited[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }
    for(int u = 0; u < V; u++){
        if(!visited[u]){
            for(auto &v:con[u]){
                visited[v] = true;
            }
        }
    }
    for(int i = 0; i < V; i++){
        if(!visited[i]) cout << i << endl;
    }
}

int main() 
{ 
    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 3); 
    addEdge(3, 4); 
    addEdge(4, 5); 
    addEdge(5, 6); 

    cover();
    return 0; 
} 
