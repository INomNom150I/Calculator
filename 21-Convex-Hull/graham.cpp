#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;

struct point{
    int x,y; 
    point(int x = 0, int y = 0): x(x),y(y) {};
    bool operator < (const point &o) const{
        return x < o.x;
    }
};

std::ostream& operator<< (std::ostream &out, const point &p){
    out << '(' << p.x << ',' << p.y << ") ";
    return out;
}

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

class comp{
 public:
    comp(point &p){
        origin = p;
    }   
    bool operator () (point &a, point &b){
        int clock = ccw(origin,a,b);
        if(clock > 0) return true;
        if(clock == 0) return dist(origin,a) < dist(origin,b);
        return false;
    }
 private:
    point origin;
};

void graham(vector<point> &v){
    std::stack<point> s;
    int l = 0;
    for(int i = 1; i < v.size(); i++){
        if(v[l].y != v[i].y){
            l = (v[l].x < v[i].x) ? l:i;
        } 
        l = (v[l].y < v[i].y) ? l:i;
    }
    //p0 = v[l];
    std::swap(v[l], v[0]);
    //std::sort(v.begin()+1, v.end(),cmp);
    std::sort(v.begin()+1, v.end(),comp(v[0]));
    
    s.push(v[0]);
    s.push(v[1]);
 
    for(int n = 2; n < v.size(); n++){ 
        point c = s.top();
        s.pop();
        while(ccw(s.top(),c,v[n]) <= 0){
            c = s.top();
            s.pop(); 
        }
        s.push(c);
        s.push(v[n]);
    }

    while(!s.empty()){
        //std::cout << '(' << s.top().x << ',' << s.top().y << "), ";
        cout << s.top();
        s.pop();
    } std::cout << std::endl;
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
