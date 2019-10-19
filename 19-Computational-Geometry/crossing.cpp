#include <iostream>
using namespace std;

struct pt{
    int x, y; 
    pt(int x, int y):x(x),y(y) {};
};

int ccw(pt& a, pt& b, pt& c){
    int d = (c.y-b.y) * (b.x-a.x) - (b.y-a.y) * (c.x-b.x);
    if(d < 0) return -1;
    if(d == 0) return 0;
    return 1;
}

bool onseg(pt& p, pt& q, pt& r){
    return (r.x >= p.x) && (r.x <= q.x);
}

bool doIntersect(pt& p,pt& q, pt& p1, pt& q1){
    int o1 = ccw(p,q,p1);
    int o2 = ccw(p,q,q1);
    int o3 = ccw(p1,q1,p);
    int o4 = ccw(p1,q1,q);
    return (o1 == 0 && onseg(p,q,p1)) || 
           (o2 == 0 && onseg(p,q,q1)) ||
           (o3 == 0 && onseg(p1,q1,p)) ||
           (o4 == 0 && onseg(p1,q1,q)) ||
           ((o1 != o2) && (o3 != o4));
}

int main() 
{ 
    pt p1(1, 1), q1(10, 1); 
    pt p2(1, 2), q2(10, 2); 
  
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n"; 
  
    q1 = {10, 0}, p1= {0, 10}; 
    p2 = {0, 0}, q2 = {10, 10}; 
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n"; 
  
    p1 = {-5, -5}, q1 = {0, 0}; 
    p2 = {1, 1}, q2 = {10, 10}; 
    doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n"; 
  
    return 0; 
} 
