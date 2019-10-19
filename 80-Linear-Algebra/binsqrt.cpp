#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double d = 1e-10;

double bin(double N){
    double l = 0, r = N;
    int cnt = 1;
    cout <<"\n binary searchmethod\n";
    while(r - l > d){
        double mid = (l+r)/2;
        if(mid*mid < N){
            l = mid;
        } else {
            r = mid;
        }
        cnt++;
        cout << cnt << ' ' <<  mid << ' ' << setprecision(10) << l << ' ' << r << endl;
    }
        cout << cnt++ << endl; 
    return l;
}

double newt(double N){
    double prev = N;
    int cnt = 0;
    
    cout <<"\n newton method\n";
    double cur = N/2;
    while(abs(prev - cur) > d){
        prev = cur;
        cur= (cur +(N/cur))/2;
        cnt++;
        cout << cnt << ' ' <<setprecision(10) << cur<< endl; 
    }
        cout << cnt++ << endl; 
    return cur;
}

int main(){
    double n = 100000;
    cout << setprecision(10);
    cout << bin(n) << endl; 
    cout << newt(n) << endl; 
}
