#include <iostream>
#include <iomanip>

using namespace std;

struct rect{
    int w,h;
    int **m;
    rect() {};
    rect(int w, int h): w(w),h(h) {
        m = new int *[h];
        for(int i = 0; i < h; i++){
            m[i] = new int [w];
        }
    }
};

void print(rect& a){
    for(int i = 0; i < a.h; i++){
        for(int j = 0; j < a.w; j++){
            cout << setw(3) << a.m[i][j];
        }
        cout << endl;
    }
}

void init(rect& a){
    int k = 1;
    for(int i = 0; i < a.h; i++){
        for(int j = 0; j < a.w; j++){
            a.m[i][j] = k++;
        }
    }
}

int main()
{
    rect a(3,4);
    init(a);
    print(a);
    rect b(1,1);
    init(b);
    print(b);
    return 0;
}

