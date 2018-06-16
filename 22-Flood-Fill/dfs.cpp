#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
typedef pair<int,int> point;
int adj[10][10];
bool visited[10][10];
int dir[2] = {-1,1};
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
bool dfs(int x, int y, int n, int m){
    if(adj[x][y] == 0 || visited[x][y]) return false;
    if(x == n && y == m) return true;
    if((x < 0 || x > n) || (y < 0 || y > m)) return false;
    visited[x][y] = true;
    for(int i = 0; i < 2; i++){
        if(dfs(x+dir[i],y,n,m) || dfs(x,y+dir[i],n,m)){
            return true;
        }
    } 
    return false;
}



bool bfs(int n, int m){
    std::queue<point> q;
    q.push(make_pair(0,0));
    visited[0][0] = true; 
    while(!q.empty()){
        point p = q.front();
        q.pop();
        if(p.first == n && p.second == m) return true;       
        for(int i = 0; i < 4; i++){
            int x = p.first+dx[i];
            int y = p.second+dy[i];
            if(x < 0|| y < 0 || x > n || y > m) continue;
            if(adj[x][y] && !visited[x][y]){
                q.push(make_pair(x,y));
                visited[x][y] = true; 
            }
        }        
    }   
    return false;
}

void print(int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << adj[i][j] << ' ';
        } std::cout << std::endl;
    }
}

int main(){
    std::ifstream fin ("input.txt"); 
    std::ofstream fout ("output.txt");
    int n, m;
    fin >> n >> m;
    for(int i = 0; i != n; i++){
        for(int j = 0; j != m; j++){
            fin >> adj[i][j];
        }
    }
    print(n,m);
    //if(dfs(0,0,n-1,m-1)){
    if(bfs(n-1,m-1)){
        std::cout << "yes\n";
        fout << "Yes\n";
    } else{
        std::cout << "no\n";
        fout << "No\n";
    }
    return 0;
}
