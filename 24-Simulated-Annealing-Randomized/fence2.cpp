#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
using namespace std;
int f;
int rangex, rangey;
struct fence{
    int x0, y0, x, y;
} fence[150];

void print(){
    for(int i = 0; i < f; i++){
        std::cout << i << ' ' << fence[i].x0 << fence[i].y0 << fence[i].x << fence[i].y << std::endl;
    }
}

bool accept(double delta, double temper){
        if(delta < 0) return true;
        //return 0.1 <= exp((-delta) / temper);//* RAND_MAX;
        return false;
}
    
double dist(int id, double x, double y){
    double dx = min(fabs(fence[id].x - x),fabs(fence[id].x0 - x));
    double dy = min(fabs(fence[id].y - y),fabs(fence[id].y0 - y));
    if(fence[id].x0 <= x && x <=  fence[id].x) return dy;
    if(fence[id].y0 <= y && y <=  fence[id].y) return dx;
    return sqrt(dx*dx + dy*dy);
}

double compareall(double x, double y){
    double wire = 0;
    for(int i = 0; i < f; i++){
        double n = dist(i, x, y);
        wire += n;
    }
    return wire;
}

void fence3(){
    std::ofstream fout("fence3.out");
    double shortx = 0,shorty = 0,wire=compareall(0,0);
    double temper = 10;
    double rate = 0.1;
    int dx[4] = { 0,-1,0,1};
    int dy[4] = {-1, 0,1,0};
    while(temper > 0.0001){
        temper *= 1-rate;
        double bestx = -1,besty = -1;
        for(int i = 0; i < 4; i++){
            double x = shortx + dx[i] * temper;
            double y = shorty + dy[i] * temper;
            double n = compareall(x,y);
            //if(wire > n){
            if(accept(n-wire,temper)){
                wire = n;
                bestx = x;
                besty = y;
            }
        }
        
        if(bestx != -1){
            shortx = bestx;
            shorty = besty;
            std::cout << fixed << shortx << ' ' << shorty << ' ' << wire << '\n';
        }
    }
    fout.precision(1);
    fout << fixed << shortx << ' ' << shorty << ' ' << wire << '\n';    
}

double dist1(int id, double x, double y){
    if(fence[id].x0 == fence[id].x){
        if(fence[id].y0 < y && y < fence[id].y) return abs(x - fence[id].x); 
        if(fence[id].y0 > y) return sqrt((fence[id].y0 - y) * (fence[id].y0 - y) + (fence[id].x - x) * (fence[id].x - x));
        return sqrt((y - fence[id].y) * (y - fence[id].y) + (fence[id].x - x) * (fence[id].x - x));
    }
    else{
       if(fence[id].x0 < x && x < fence[id].x) return abs(y - fence[id].y); 
       if(fence[id].x0 > x) return sqrt((fence[id].x0 - x) * (fence[id].x0 - x) + (fence[id].y - y) * (fence[id].y - y));
       return sqrt((x - fence[id].x) * (x - fence[id].x) + (fence[id].y - y) * (fence[id].y - y));
    }
}

void central(){
    std::ofstream fout("fence3.out");
    double shortx, shorty, wire = 9999;
    for(double i = 0; i <= rangex; i += 0.1){
        for(double j = 0; j <= rangey; j += 0.1){
            double n = compareall(i,j);
            if(wire > n){ 
                wire = n;
                shortx = i;
                shorty = j;
            }           
        }
    } 
    fout.precision(1);
    fout << fixed << shortx << ' ' << shorty << ' ' << wire << '\n';   
}

int main(){
    std::ifstream fin("fence3.in");
    rangex = rangey = 0;
    fin >> f;
    for(int i = 0; i < f; i++){
        fin >> fence[i].x0 >> fence[i].y0 >> fence[i].x >> fence[i].y;
        if(fence[i].x0 > fence[i].x) std::swap(fence[i].x0,fence[i].x);
        if(fence[i].y0 > fence[i].y) std::swap(fence[i].y0,fence[i].y);
        if(fence[i].x > rangex) rangex = fence[i].x;       
        if(fence[i].y > rangey) rangey = fence[i].y;       
    }
    fence3();
    return 0;
}
