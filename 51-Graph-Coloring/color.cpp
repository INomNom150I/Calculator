#include <iostream>
#include <list>
using namespace std;
int V = 5;
list<int> con[100];

void addEdge(int u, int v){
    con[u].push_back(v);
    con[v].push_back(u);
}

void greedyColoring(){
    int color[V];
    for(int i = 0; i < V; i++){
        color[i] = -1;
    }
    color[0] = 0;
    for(int v = 1;v < V; v++){
        bool aval[V];
        for(int i = 0; i < V; i++) aval[i] = 1;
        for(auto &u:con[v]){
            if(color[u] != -1){
                aval[color[u]] =false;
            }
        }
        for(int j = 0; j < V; j++){
            if(aval[j]){
                color[v] = j;
                break;
            }
        }
    }
    for(int i = 0; i < V; i++){
        cout << color[i] << ' ';
    }
    cout << endl;
}

int main() 
{ 
#if 0
    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 2); 
    addEdge(1, 3); 
    addEdge(2, 3); 
    addEdge(3, 4); 
    cout << "Coloring of graph 1 \n"; 
    greedyColoring(); 
#else
    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 2); 
    addEdge(1, 4); 
    addEdge(2, 4); 
    addEdge(4, 3); 
    cout << "\nColoring of graph 2 \n"; 
    greedyColoring(); 
#endif
    return 0; 
} 
