#include <iostream>
#include <vector>
#define INF 9999
using namespace std;

struct edge{
    int u, v, w;
    edge(int u, int v, int w):
        u(u),v(v),w(w) {}
};

vector<edge> e;

void addEdge(int u, int v, int w){
    e.push_back(edge(u,v,w));
}

int dist[100];
int N;

void print(){
    for(int i = 0; i < N; i++){
        if(dist[i] > 8000) cout << "INF ";
        else std::cout << dist[i] << ' ';
    }
    std::cout << endl;
}

void bellman(){
    for(int i = 1; i < N; i++){
        dist[i] = INF;
    }
    dist[0] = 0;

    print();
    for(int i = 1; i < N; i++){
        for(int j = 0; j < e.size(); j++){
            int u = e[j].u;
            int v = e[j].v;
            int w = e[j].w;

            dist[v] = min(dist[v],dist[u] + w);
            print();
        }
    }  
}

int main(){
    N = 5;
    addEdge(4,3,-3);
    addEdge(1,2,3);
    addEdge(3,1,1);
    addEdge(1,3,2);
    addEdge(0,1,-1);
    addEdge(0,2,4);
    addEdge(1,4,2);
    addEdge(3,2,5);
    bellman();
    print();
}
