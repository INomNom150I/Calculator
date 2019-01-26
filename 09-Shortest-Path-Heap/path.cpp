#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <list>
using namespace std;
#define N 9
#define INF 0X1F1F1F1F

struct edge{
    int t,w;
    edge() {}
    edge(int t, int w):
        t(t),w(w) {}

    bool operator <(const edge &o) const{
        return w > o.w;
    }
};

list<edge> g[N];
int dist[N];
int parent[N];
int seq[N];

void add_edge(int u, int v, int dist = 0){
    g[u].push_back(edge(v,dist));
    g[v].push_back(edge(u,dist));
}

void dijkstra(int src){
    bool visited[N];
    memset(visited,0, sizeof(visited));
    memset(dist,0x1F, sizeof(dist));
    priority_queue<edge> q;
    q.push(edge(src,0));
    dist[src] = 0;
    parent[src] = src;
    int i = 0;

    while(!q.empty()){
        edge tmp = q.top();
        q.pop();
        int u = tmp.t;
        if(visited[u]) continue;
        seq[i++] = u;
        visited[u] = 1;
        for(auto &e: g[u]){
            if(!visited[e.t] &&  dist[u] + e.w <= dist[e.t]){
                if(dist[u] + e.w == dist[e.t]){
                    if(parent[e.t] >  u) parent[e.t] = u; 
                } else{
                    dist[e.t] = dist[u] + e.w;
                    parent[e.t] = u;
                    q.push(edge(e.t,dist[e.t]));
                }
            }
        }
    }

}

void printpath(int j){
    if(j == parent[j]){
        cout << j << ' ';
        return; 
    }
    printpath(parent[j]);
    cout << j << ' ';
}

void printpath2(int j){
    cout << j << ' ';
    if(j != parent[j]){
        printpath2(parent[j]);
    }
}

void print(){
    for(int i = 0; i < N; i++){
        std::cout << seq[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        std::cout << dist[seq[i]] << ' ';
    }
    cout << endl;
    std::cout << "Dijkstra Shortest" << std::endl;
    for(int i = 0; i < N; i++){
        std::cout << i << ' ' << dist[i] << '\t';
        //printpath(i);
        printpath2(i);
        std::cout << endl;
    }
}

int main(){
    add_edge(0,1,4);
    add_edge(0,7,8);    
    add_edge(1,7,11);   
    add_edge(1,2,8);    
    add_edge(7,8,7);    
    add_edge(7,6,1);    
    add_edge(2,8,2);    
    add_edge(6,8,6);    
    add_edge(2,5,4);    
    add_edge(6,5,2);    
    add_edge(2,3,7);    
    add_edge(3,5,14);   
    add_edge(3,4,9);    
    add_edge(5,4,10);   

    dijkstra(0);
    print();    
    return 0;
}
