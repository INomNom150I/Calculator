#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

struct edge{
    int src,dst,weight;
    edge(int src,int dst,int weight):src(src),dst(dst),weight(weight){};
    bool operator <(const edge &o) const {
        return weight < o.weight;
    }
};

struct node{
    int y,weight;
    node(int y,int weight):y(y),weight(weight){};
};

vector<edge> e;
vector<edge> mst;

int V = 9;
list<node> adj[100];

void add_edge(int u, int v,int weight){
    adj[u].push_back(node(v,weight));
    adj[v].push_back(node(u,weight));
    e.push_back(edge(u,v,weight));
}       

int find(int p[], int i){
    if(p[i] == -1) return i;
    p[i] = find(p,p[i]);
    return p[i];
}

void Union(int p[],int i, int j){
    int pi = find(p,i);
    int pj = find(p,j);

    p[pi] = pj;
}

void kmst(){
    sort(e.begin(),e.end());
    int p[V];
    memset(p,-1,sizeof(p));
    cout << endl;
    for(int i = 0; i < e.size(); i++){
        int u = find(p,e[i].src);
        int v = find(p,e[i].dst);
        if(u != v){
            mst.push_back(e[i]);
            Union(p,u,v);           
            if(mst.size() == V-1) return;
        } 
    }
}

void print(){
    for(auto &i: mst){
        std::cout << i.src << ' ' <<i.dst << ' ' << i.weight << std::endl;
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
    
    kmst();
    print();

    return 0;
}
