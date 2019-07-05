#include <iostream>
using namespace std;

struct bignum{
    int d[1000];
    int w; 
    bignum(const string a){
        w = a.size();
        for(int i = 0; i < w; i++){
            d[w-i-1] = a[i]-'0';
        }
    }       
/*
    ostream& operator<< (ostream& os,bignum& b){
        for(int i = w; i >= 0; i++){
            os << b.d[i];
            return os;
        }
    }
*/
    ostream& operator<< (ostream& os){
        for(int i = w; i >= 0; i++){
            os << d[i];
        }
        return os;
    }
  
    bignum operator + (bignum &o){
        int m = max(w,o.w);
    }
};

int main(){
    bignum a("111111111111111111");
    cout << a << endl;
}
