#include <iostream>
#include <queue>
#define N 8
using namespace std;
int c[N][N];
const int a[8] = {-2,-1,1,2,2,1,-1,-2};
const int b[8] = {1,2,2,1,-1,-2,-2,-1};
bool visited[N][N];

struct point{
    int x,y,dist;
    point(int x,int y,int dist = 0): x(x),y(y),dist(dist) {}
};

void bfs(point &pt, int dx, int dy){
    queue<point> q;
    q.push(pt);
    visited[pt.x][pt.y] = 1;
    while(!q.empty()){
        point p = q.front();
        q.pop();
        if(p.x == dx && p.y == dy){
            cout << p.dist << endl;
            return;
        }
        //cout << p.x << ' ' << p.y << endl;
        for(int i = 0; i < 8; i++){
            int cx = p.x+a[i], cy = p.y+b[i];
            if(cx < N && cx >= 0 && cy < N && cy >= 0 && !visited[cx][cy]){
                q.push(point(cx,cy,p.dist+1));
                visited[cx][cy] = 1;
                //cout << cx << ' ' << cy << endl;
            }
        }
    }
}

int main(){
    point p(1,1);
    bfs(p,1,2);
    return 0;
}
