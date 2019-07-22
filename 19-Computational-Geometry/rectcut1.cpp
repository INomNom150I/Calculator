#include <iostream>
using namespace std;

struct rect{
    int x0,y0,x1,y1;
};

void print(rect& a){
    cout << a.x0 << ' ' << a.y0 << '-' << a.x1 << ' ' << a.y1 << endl; 
}

void cover(rect a, rect b){
    rect c;
    int x1 = min(a.x1,b.x0);
    int x0 = max(a.x0,b.x1);
    cout << "x1 " << x1 << endl;
    cout << "x0 " << x0 << endl;


    if(a.x0 < b.x0){
        c = a;
        //c.x1 = min(a.x1,b.x0);
        c.x1 = x1; 
        cout << "1" << endl;
        print(c); 
    } 
    if(a.x1 > b.x1){
        c = a;
        //c.x0 = max(a.x0,b.x1);
        c.x0 = x0;
        cout << "2" << endl;
        print(c); 
    }

    x0 = max(a.x0,b.x0);
    x1 = min(a.x1,b.x1);
    if(a.y0 < b.y0 && x0 < x1){
        c = a;
        c.x0 = max(a.x0,b.x0);
        //c.x0 = x1; 
        c.x1 = min(a.x1,b.x1);
        //c.x1 = x0;
        c.y1 = min(a.y1,b.y0);
        cout << "3" << endl;
        print(c); 
    }
    if(a.y1 > b.y1 && x0 < x1){
        c = a;
        c.x0 = max(a.x0,b.x0);
        c.x1 = min(a.x1,b.x1);
        c.y0 = max(a.y0,b.y1);
        cout << "4" << endl;
        print(c); 
    }
}

int main(){
    cout << "input rectangle: ";
    rect r[2];
    for(int i = 0; i < 2; i++){
        cin >> r[i].x0 >> r[i].y0 >> r[i].x1 >> r[i].y1;
    }
    cout << endl;
    cover(r[0],r[1]);
}
