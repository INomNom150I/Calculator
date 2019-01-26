#include <iostream>
using namespace std;

int main(){
    int ar[] = {1,2,3,4,5};
    int N = sizeof(ar)/sizeof(int);;
    int *p = ar;
    for(auto i:ar){
        cout << i << ' ';
        i+=10;
    }
    cout << endl;

    for(auto i:ar){
        cout << i << ' ';
    }
    cout << endl;

/*

for (int j, i=0; i<N; ++i){
    j = a[i];
}*/

    for(auto &i:ar){
        cout << i << ' ';
        i+=10;
    }
    cout << endl;

    for(auto i:ar){
        cout << i << ' ';
    }
    cout << endl;

    int * it=&ar[0];;
    for(int i = 0; i < N; i++){
        cout << (*it) << ' ';
        *it = *it+10;
        it++;
    }
    cout << endl;

    for(auto i:ar){
        cout << i << ' ';
    }
    cout << endl;

}
