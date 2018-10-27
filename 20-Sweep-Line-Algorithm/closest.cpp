#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct point{
    int x, y;
    point(int x, int y): x(x), y(y) {}
    bool operator < (const point o) const{
        return x < o.x;
    }
};

double dist(const point &a, const point &b){
    return sqrt((b.x - a.x) * (b.x - a.x)+ (b.y - a.y) * (b.y - a.y));
}

double closest(std::vector<point> &P ){
    double mini = 99999;
    for(int i = 0; i < P.size(); i++){
        for(int j = i + 1; j < P.size(); j++){
            double tmp = dist(P[i],P[j]);
            if(tmp < mini) mini = tmp;
        }
    }
    return mini;
}

void print(std::vector<point> &P){
    for(int i = 0; i < P.size(); i++){
        std::cout << ", (" << P[i].x << ',' << P[i].y << ')';
    } std::cout << std::endl;
}

bool boxcheck(double h, const point p1, const point p2){
    return abs(p2.y -p1.y) < h;
}

double sweep(std::vector<point> &P){
    print(P);
    std::sort(P.begin(), P.end());
    print(P);
    std::set<point> s;
    s.insert(P[0]);
    double h  = 99999;
    int left = 0;
    for(int i = 1; i < P.size(); i++){
        while(left < i){
            if(P[i].x - P[left].x < h) break;
            s.erase(P[left]);
            left++;
       }       
       for(set<point>::iterator j = s.begin(); j != s.end(); j++){
            if(boxcheck(h,P[i], *j)){
                double tmp = dist(P[i], *j);
                if(tmp < h) h = tmp;
            }
        }
        s.insert(P[i]);
    }
    return h;
}

double sweep2(std::vector<point> &P){
    print(P);
    std::sort(P.begin(), P.end());
    print(P);
    double h  = 99999;
    int left = 0;
    for(int i = 1; i < P.size(); i++){
        while(left < i){
            if(P[i].x - P[left].x < h) break;
            left++;
       }       
       for(int j = left; j < i; j++){
            if(boxcheck(h,P[i], P[j])){
                double tmp = dist(P[i], P[j]);
                if(tmp < h) h = tmp;
            }
        }
    }
    return h;
}

int main(){
    std::vector<point> P;
    P.emplace_back(2, 3);
    P.emplace_back(12, 30);
    P.emplace_back(40, 50);
    P.emplace_back(5, 1);
    P.emplace_back(12, 10);
    P.emplace_back(3, 4);
    double mind = closest(P);
    std::cout << "The smallest distance is " << mind << std::endl;;
    mind = sweep(P);
    std::cout << "The smallest distance is " << mind << std::endl;;
    mind = sweep2(P);
    std::cout << "The smallest distance is " << mind << std::endl;;
    return 0;
}
