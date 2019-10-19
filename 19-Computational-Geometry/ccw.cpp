#include <iostream>
using namespace std;

struct pt{
    int x, y;
    pt(int x,int y): x(x),y(y) {};
};

int ccw(pt& a, pt& b, pt& c){
    return (c.y-b.y) * (b.x-a.x) - (b.y-a.y) * (c.x - b.x);
}

int main(){
    pt a(1,1);
    pt b(3,3);
    pt c(2,5);
    cout << "ccw " << ccw(a,b,c) << endl; 
    cout << "cw " << ccw(a,c,b) << endl; 
    cout << "ccw " << ccw(b,c,a) << endl; 
}
