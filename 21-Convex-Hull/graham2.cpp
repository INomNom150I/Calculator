#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;

struct point{
    int x,y; 
    point(int x = 0, int y = 0): x(x),y(y) {};
};

point p0;

int ccw(point &a,point &b,point &c){
    return (c.y-b.y)*(b.x-a.x) - (b.y-a.y) * (c.x-b.x);  
}

double dist(point &a, point &b){
    return sqrt((b.y-a.y) * (b.y-a.y) + (b.x-a.x) * (b.x-a.x));
}

bool cmp(point &a, point &b){
    int clock = ccw(p0,a,b);
    if(clock > 0) return true;
    if(clock == 0) return dist(p0,a) < dist(p0,b);
    return false;
}

void graham(vector<point> &v){
    int l = 0;
    for(int i = 1; i < v.size(); i++){
        if((v[l].x > v[i].x) || (v[l].x == v[i].x && v[l].y > v[i].y)){
            l = i;
        } 
    }
    std::swap(v[l], v[0]);
    p0 = v[0];
    std::sort(v.begin()+1, v.end(),cmp);
    
    int b = 1;
    for(int n = 2; n < v.size(); n++){ 
    //    cout << b << ' ' << s[b].x << ' ' << s[b].y << endl;
        while(b > 0 && ccw(v[b-1],v[b],v[n]) <= 0){
            b--;
        }
        b++;
        v[b] = v[n];
    }
//    cout << "answer\n";

    for(int i = b; i >= 0; i--){
        cout << v[i].x << ' ' << v[i].y << endl;
    }
    cout << endl;
}

int main(){
    std::vector<point> P;
    P.emplace_back(0,3);
    P.emplace_back(2,2);
    P.emplace_back(1,1);
    P.emplace_back(2,1);
    P.emplace_back(3,0);
    P.emplace_back(0,0);
    P.emplace_back(3,3);
    graham(P);
    return 0;
}
