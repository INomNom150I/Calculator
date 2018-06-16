#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct point{
	int x,y;
	point(int x, int y): x(x),y(y) {}
	bool operator < (const point &o) const{
		return x < o.x;
	}
};

int ccw(point &a, point &b, point &c){
	return (c.y-b.y)*(b.x-a.x) - (b.y-a.y) * (c.x-b.x);  
}

std::vector<point> convex(std::vector<point> &v){
    std::vector<point> hull;
    int mini = 0;
    for(int l = 0; l < v.size(); l++){
        if(v[l].x < v[mini].x) mini = l;
    } 
    int p = mini;
    do {
        hull.push_back(v[p]); 
        int q = (p+1)%v.size();
        for(int i = 0; i < v.size(); i++){
            if(ccw(v[p],v[q],v[i]) > 0) {
                q = i;
            }
        }   
        p = q;
    } while(p != mini);

    return hull;
}

void print(std::vector<point> &v){
    for(int i = 0; i < v.size(); i++){
        std::cout << '('<<v[i].x << ',' << v[i].y<< "), ";
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
    std::vector<point> hull = convex(P);
    print(hull);   
}
