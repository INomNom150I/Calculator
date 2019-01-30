#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

struct edge{
    int src,dst,weight;
    edge(int src,int dst,int weight):src(src),dst(dst),weight(weight){};
    bool operator <(const edge &o) const {
        return weight > o.weight;
    }
};
vector<edge> mst;


struct node{
    int y,weight;
    node(int y,int weight):y(y),weight(weight){};
};

int V = 9;
list<node> adj[100];
void add_edge(int u, int v,int weight){
    adj[u].push_back(node(v,weight));
    adj[v].push_back(node(u,weight));
}       


void prim(){
    bool visited[V];
    memset(visited,0,sizeof(visited));
    priority_queue<edge> q;

    for(auto &i:adj[0]){
        q.push(edge(0,i.y,i.weight));
    }
    visited[0] = 1;
    while(!q.empty()){
        edge n = q.top();
        q.pop();

        if(visited[n.dst]){
            continue;
        }
        visited[n.dst] = 1;
        mst.push_back(n);
        for(auto &i:adj[n.dst]){
            if(!visited[i.y]){
                q.push(edge(n.dst,i.y,i.weight));
            }
        }
    }
}

void print(){
    for(auto &i:mst){
        std::cout << i.src << ' ' << i.dst << ' '<< i.weight << '\n'; 
    }
}

int main(){
    add_edge(0,1,4);
    add_edge(0,7,8);
    add_edge(1,7,11);
    add_edge(1,2,8);
    add_edge(2,8,2);
    add_edge(7,8,7);
    add_edge(7,6,1);
    add_edge(6,8,6);
    add_edge(6,5,2);
    add_edge(2,5,4);
    add_edge(2,3,7);
    add_edge(3,5,14);
    add_edge(3,4,9);
    add_edge(5,4,10);
    prim();
    print();
    return 0;
}
